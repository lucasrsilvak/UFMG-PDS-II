#ifndef CACHORRO_QUENTE_H
#define CACHORRO_QUENTE_H

#include "produto.hpp"
#include <vector>

using namespace std;

class CachorroQuente : public Produto {
    public:
        CachorroQuente(int num_salsichas, vector<string>& complementos, bool prensado, int qtd);
        float calcPreco() const override;
        string descricao() const override;

    private:
        int             _num_salsichas;
        vector<string>  _complementos;
        bool            _prensado;
};

#endif