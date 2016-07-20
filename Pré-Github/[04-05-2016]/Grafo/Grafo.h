#include <iostream>
#include <cstdlib>
#ifndef Grafo_H
#define Grafo_H

class Grafo{
    public:
    Grafo();
    ~Grafo();
    virtual int procuraAdjacencia(int vertice, int *adj)=0;
    virtual void imprimeGrafo()=0;
    virtual void carregaGrafo()=0;
};

#endif

