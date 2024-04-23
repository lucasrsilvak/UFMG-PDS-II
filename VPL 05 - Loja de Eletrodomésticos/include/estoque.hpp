#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <iostream>
#include <vector>

#include "geladeira.hpp"
#include "fogao.hpp"

using namespace std;

class Estoque {

    private:
        vector<Geladeira> _geladeiras;
        vector<Fogao> _fogoes;

        int _indice_geladeiras;
        int _indice_fogoes;

    public:

        Estoque();

        void armazena_geladeira(int capacidade, int portas);
        void vende_geladeira(int capacidade, int portas);
        void armazena_fogao(int queimadores, int capacidade);
        void vende_fogao(int queimadores, int capacidade);
        void exibe_geladeiras();
        void exibe_fogoes();
        int quantidade_geladeiras();
        int quantidade_fogoes();
};

#endif