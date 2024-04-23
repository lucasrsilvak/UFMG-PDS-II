#ifndef PIZZA_H
#define PIZZA_H

#include "produto.hpp"

class Pizza : public Produto {
      public:
            Pizza(const string& sabor, int pedacos, bool borda_recheada, int qtd);
            float calcPreco() const override;
            string descricao() const override;
      private:
            string _sabor;
            int   _num_pedacos;
            bool  _borda_recheada;
};

#endif