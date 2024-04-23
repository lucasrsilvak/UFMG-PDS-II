#ifndef FOGAO_CPP
#define FOGAO_CPP

#include "fogao.hpp"

Fogao::Fogao(int _numero_de_queimadores, int _capacidade_forno) {
    this->_numero_de_queimadores = _numero_de_queimadores;
    this->_capacidade_forno = _capacidade_forno;
}

int Fogao::getQueimadores() {
    return this->_numero_de_queimadores;
}

int Fogao::getCapacidade() {
    return this->_capacidade_forno;
}


#endif
