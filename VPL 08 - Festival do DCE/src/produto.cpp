#ifndef PRODUTO_C
#define PRODUTO_C

#include "produto.hpp"

using namespace std;

int Produto::getQtd() {
    return this->_quantidade;
}

float Produto::getValor() {
    return this->_valor_unitario;
}

string Produto::descricao() const {
    return 0;
}

float Produto::calcPreco() const {
    return 0;   
}

#endif