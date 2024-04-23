#ifndef FOGAO_HPP
#define FOGAO_HPP

#include <iostream>

class Fogao {
    private:
        int _numero_de_queimadores;
        int _capacidade_forno;

    public:
        Fogao(int queimadores, int forno);
        int getQueimadores();
        int getCapacidade();
};

#endif