#ifndef GELADEIRA_CPP
#define GELADEIRA_CPP

#include "geladeira.hpp"

Geladeira::Geladeira(int _capacidade_em_litros, int _numero_de_portas) {
    this->_capacidade_em_litros = _capacidade_em_litros;
    this->_numero_de_portas = _numero_de_portas;
}

int Geladeira::getCapacidade() {
    return this->_capacidade_em_litros;
}

int Geladeira::getPortas() {
    return this->_numero_de_portas;
}

#endif
