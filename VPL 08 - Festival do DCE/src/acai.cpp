#ifndef ACAI_C
#define ACAI_C

#include "acai.hpp"

using namespace std;

Acai::Acai(int tamanho, vector<string>& complementos, int qtd) {
    this->_tamanho      = tamanho;
    this->_quantidade   = qtd;
    for (int unsigned i = 0; i < complementos.size(); i++) {
        this->_complementos.push_back(complementos.at(i));
    }
}

float Acai::calcPreco() const {
    float resultado = this->_tamanho*0.02 + 2*this->_complementos.size();
    return resultado * this->_quantidade;
}

string Acai::descricao() const {
    string descricao;
    descricao = to_string(this->_quantidade) + "X açai " + to_string(this->_tamanho) + "ml com ";
    for (int unsigned i = 0; i < this->_complementos.size(); i++) {
        descricao += _complementos.at(i);
        if (i == _complementos.size()-1) {
            descricao += ".";
        } else {
            descricao += ", ";
        }
    }
    return descricao;
}

#endif