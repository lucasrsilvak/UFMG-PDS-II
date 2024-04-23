#ifndef ESTOQUE_CPP
#define ESTOQUE_CPP

#include "fogao.hpp"
#include "geladeira.hpp"
#include "estoque.hpp"

using namespace std;

Estoque::Estoque() {
    _indice_geladeiras = 0;
    _indice_fogoes = 0;
}

void Estoque::armazena_geladeira(int capacidade, int portas) {
    Geladeira* nova = new Geladeira(capacidade, portas);
    this->_geladeiras.push_back(*nova);
    this->_indice_geladeiras++;
}

void Estoque::vende_geladeira(int capacidade, int portas) {
    for (int i = this->_indice_geladeiras-1; i >= 0; i--) {
        if ((_geladeiras[i].getCapacidade() == capacidade) && (_geladeiras[i].getPortas() == portas)) {
            _geladeiras.erase(_geladeiras.end() - (this->_indice_geladeiras-i));
            this->_indice_geladeiras--;
            break;
        }
    }
}

void Estoque::armazena_fogao(int queimadores, int capacidade) {
    Fogao* novo = new Fogao(queimadores, capacidade);
    this->_fogoes.push_back(*novo);
    this->_indice_fogoes++;
}

void Estoque::vende_fogao(int queimadores, int capacidade) {
    for (int i = this->_indice_fogoes-1; i >= 0; i--) {
        if ((_fogoes[i].getQueimadores() == queimadores) && (_fogoes[i].getCapacidade() == capacidade)) {
            _fogoes.erase(_fogoes.end() - (this->_indice_fogoes-i));
            this->_indice_fogoes--;
            break;
        }
    }
}

void Estoque::exibe_geladeiras() {
    for (int i = 0, ie = this->_indice_geladeiras; i < ie; i++) {
        cout << "G " << _geladeiras[i].getCapacidade() << " ";
        cout << _geladeiras[i].getPortas() << endl;
    }
}

void Estoque::exibe_fogoes() {
    for (int i = 0, ie = this->_indice_fogoes; i < ie; i++) {
        cout << "F " << _fogoes[i].getQueimadores() << " ";
        cout << _fogoes[i].getCapacidade() << endl;
    }
}

int Estoque::quantidade_geladeiras() {
    return _indice_geladeiras;
}

int Estoque::quantidade_fogoes() {
    return _indice_fogoes;
}

#endif
