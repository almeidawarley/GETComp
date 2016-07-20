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
    virtual void redimensionaGrafo(int numv, int numa)=0;
    virtual void insereArco(int origem, int destino)=0;
    virtual int consultaNumVertices()=0;
    virtual void defineNumVertices(int v)=0;
    virtual void caminhoMaisCurtoD(int v)=0;
    virtual void caminhoMaisCurtoFB(int v)=0;
    virtual void fluxoMaximo(int fonte, int sumidouro)=0;
};

#endif

