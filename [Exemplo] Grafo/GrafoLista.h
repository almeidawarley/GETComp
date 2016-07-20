#include <iostream>
#include <cstdlib>
#include "Grafo.h"

class GrafoLista : public Grafo{
    private:
    int **adjacentes;
    int *conexoes;
    int numVertices;
    int numArestas;

    public:
    GrafoLista();
    ~GrafoLista();
    int procuraAdjacencia(int vertice, int *adj);
    void imprimeGrafo();
    void redimensionaGrafo(int numv, int numa);
    void insereArco(int origem, int destino);
    int consultaNumVertices();
    void defineNumVertices(int v);
    void caminhoMaisCurtoD(int v);
    void caminhoMaisCurtoFB(int v);
};


