#include <iostream>
#include "Fatura.hpp"

using namespace std;

Fatura::Fatura(int id, double valor) {
    _id     = id;
    _valor  = valor;
}

void Fatura::imprimir_dados() {
    cout << _id << " " << _valor << endl;
}

void Fatura::setProximo(Fatura *Prox) {
    _Proximo = Prox;
}

void Fatura::setAnterior(Fatura *Ante) {
    _Anterior = Ante;
}

Fatura* Fatura::getProximo() {
    return _Proximo;
}

Fatura* Fatura::getAnterior() {
    return _Anterior;
}

double Fatura::getValor() {
    return _valor;
}