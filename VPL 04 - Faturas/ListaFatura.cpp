#include <iostream>
#include "ListaFatura.hpp"

using namespace std;

ListaFatura::ListaFatura() {
    _Inicio = nullptr;
}

Fatura* ListaFatura::getFim() {
    return _Fim;
}

void ListaFatura::insere_fatura(Fatura *novafatura) {
    if (!_Inicio) {
        _Inicio = novafatura;
        _Fim    = novafatura;

        novafatura->setProximo(nullptr);
        novafatura->setAnterior(nullptr);
    } else {
        if (novafatura->getValor() < _Inicio->getValor()) {
            Fatura *Atual           = _Inicio->getProximo();
            Fatura *AntesAtual      = _Inicio;
            while (Atual && (novafatura->getValor() < Atual->getValor()))
            {
                AntesAtual          = Atual;
                Atual               = Atual->getProximo();
            }
            if (Atual) {
                if (novafatura->getValor() > Atual->getValor()) {
                    novafatura->setAnterior(AntesAtual);
                    novafatura->setProximo(Atual);
                    AntesAtual->setProximo(novafatura);
                    return;
                }
            }
            _Fim                    = novafatura;
            Atual                   = novafatura;
            Atual->_Proximo         = nullptr;
            Atual->_Anterior        = AntesAtual;
            AntesAtual->_Proximo    = Atual;
        } else {
            Fatura *Atual           = _Inicio->getAnterior();
            Fatura *DepoisAtual     = _Inicio;
            while (Atual && (novafatura->getValor() > Atual->getValor())) {
                DepoisAtual         = Atual;
                Atual               = Atual->getAnterior();
            }
            if (Atual) {
                if (novafatura->getValor() < Atual->getValor()) {
                    novafatura->setProximo(DepoisAtual);
                    novafatura->setAnterior(Atual);
                    DepoisAtual->setAnterior(novafatura);
                    return;
                }
            }
            Atual                   = novafatura;
            _Inicio                 = novafatura;
            Atual->_Anterior        = nullptr;
            Atual->_Proximo         = DepoisAtual;
            DepoisAtual->_Anterior  = Atual;
        }
    }
}

Fatura* ListaFatura::proxima_fatura() {
    if(!_Inicio) {
        return nullptr;
    }
    Fatura* _Resultado;
    _Resultado = _Inicio;
    
    if (_Inicio->getProximo()) {
        _Inicio = _Inicio->getProximo();
        _Inicio->setAnterior(nullptr);
    } else {
        _Inicio = nullptr;
    }

    return _Resultado;
}

void ListaFatura::imprimir_lista() {
    Fatura *Atual = _Inicio;
    while(Atual)
    {
        Atual->imprimir_dados();
        Atual = Atual->getProximo();
    }
}