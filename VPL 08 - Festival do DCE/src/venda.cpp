#ifndef VENDA_C
#define VENDA_C

#include "venda.hpp"

using namespace std;

Venda::~Venda() {
    for (auto it = this->_pedidos.begin(); it != this->_pedidos.end(); ++it) {
        delete *it;
    }
    this->_pedidos.clear();
}

void Venda::adicionaPedido(Pedido* p) {
    this->_pedidos.push_back(p);
}

void Venda:: imprimeRelatorio() const {
    float total = 0;
    int j = 1;
    for (auto const& i : this->_pedidos) {
        cout << "Pedido " << j << endl;
        cout << i->resumo() << endl;
        total += i->calculaTotal();
        j++;
    }
    cout << "Relatorio de Vendas" << endl;
    cout << "Total de vendas: R$" << fixed << setprecision(2) << total << endl;
    cout << "Total de pedidos: " << j-1 << endl;
}

#endif