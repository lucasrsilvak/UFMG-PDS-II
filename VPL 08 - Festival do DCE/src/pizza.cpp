#ifndef PIZZA_C
#define PIZZA_C

#include "pizza.hpp"

using namespace std;

Pizza::Pizza(const string& sabor, int pedacos, bool borda_recheada, int qtd) {
    this->_sabor          = sabor;
    this->_num_pedacos    = pedacos;
    this->_borda_recheada = borda_recheada;
    this->_quantidade     = qtd;
}

float Pizza::calcPreco() const {
    float resultado = 5 * this->_num_pedacos + 10 * _borda_recheada;
    if (this->_sabor.find("especial") != string::npos) {
        resultado += 8;
    }
    return resultado * this->_quantidade;
}

string Pizza::descricao() const {
    string descricao;
    descricao = to_string(this->_quantidade) + "X pizza " + this->_sabor + ", " + to_string(this->_num_pedacos) + " pedaços ";
    if (this->_borda_recheada) { 
        descricao += "e ";
    } else {
        descricao += "sem ";
    }
    descricao += "borda recheada.";
    return descricao;
}

#endif