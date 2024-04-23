#ifndef CACHORRO_QUENTE_C
#define CACHORRO_QUENTE_C

#include "cachorro_quente.hpp"

using namespace std;

CachorroQuente::CachorroQuente(int num_salsichas, vector<string>& complementos, bool prensado, int qtd) {
    this->_num_salsichas = num_salsichas;
    this->_prensado      = prensado;
    this->_quantidade    = qtd;
    for (int unsigned i = 0; i < complementos.size(); i++) {
        this->_complementos.push_back(complementos.at(i));
    }
}

float CachorroQuente::calcPreco() const {
    float resultado = 5 + this->_num_salsichas * 1.5 + this->_complementos.size() * 1 + this->_prensado * 0.5;
    return resultado * this->_quantidade;
};
            
string CachorroQuente::descricao() const {
    string descricao;
    descricao = to_string(this->_quantidade) + "X cachorro-quente";
    if (this->_prensado) { 
        descricao += " prensado";
    }
    descricao += (" com " + to_string(this->_num_salsichas) + " salsicha(s)");
    for (int unsigned i = 0; i < this->_complementos.size(); i++) {
        descricao += (", " + _complementos.at(i));
    }
    descricao += ".";
    return descricao;
}

#endif