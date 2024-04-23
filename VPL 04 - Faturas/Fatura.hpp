#ifndef FATURA_H
#define FATURA_H

typedef struct Fatura {
    // ATRIBUTOS
    int    _id;
    double _valor;
    Fatura *_Anterior;
    Fatura *_Proximo;

    // MÉTODOS
    Fatura(int id, double valor);
    void imprimir_dados();
    Fatura* getAnterior();
    Fatura* getProximo();
    void setAnterior(Fatura* Ante);
    void setProximo(Fatura* Prox);
    double getValor();
} Fatura;

#endif