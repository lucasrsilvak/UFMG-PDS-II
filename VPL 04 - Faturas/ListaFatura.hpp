#ifndef LISTAFATURA_H
#define LISTAFATURA_H

#include "Fatura.hpp"

struct ListaFatura {

    // ATRIBUTOS
    Fatura *_Inicio;
    Fatura *_Fim;

    // MÉTODOS
    ListaFatura();
    void insere_fatura(Fatura *novafatura);
    Fatura* proxima_fatura();
    void imprimir_lista();
    Fatura* getFim();
};

#endif