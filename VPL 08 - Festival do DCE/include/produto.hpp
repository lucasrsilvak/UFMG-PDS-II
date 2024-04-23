#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Produto {
    public:
        int     getQtd();
        float   getValor();
        virtual string descricao() const = 0;
        virtual float calcPreco() const = 0;
        virtual ~Produto() = default;

    protected:
        int     _quantidade;
        float   _valor_unitario;
};
#endif