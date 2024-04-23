#ifndef ACAI_H
#define ACAI_H

#include "produto.hpp"

using namespace std;

class Acai : public Produto {
    public:
        Acai(int tamanho, vector<string>& complementos, int qtd);
        float calcPreco() const override;
        string descricao() const override;

    private:
        int _tamanho;
        vector<string> _complementos;
};
#endif