#ifndef PEDIDO_C
#define PEDIDO_C

#include "pedido.hpp"

using namespace std;

Pedido::~Pedido() {
    for (auto const& i : this->_produtos) {
        delete i;
    }
}

void Pedido::adicionaProduto(Produto* p) {
    this->_produtos.push_back(p);
}

float Pedido::calculaTotal() const {
    float total = 0;
    for (auto const& i : this->_produtos) {
        total += i->calcPreco();
    }
    return total;
}

string Pedido::resumo() const {
    string descricao;
    for (auto const& i : this->_produtos) {
        descricao += (i->descricao() + "\n");
    }
    descricao += "Endereço: " + this->_endereco;
    return descricao;
}

void Pedido::setEndereco(const std::string& endereco) {
    this->_endereco = endereco;
}

#endif