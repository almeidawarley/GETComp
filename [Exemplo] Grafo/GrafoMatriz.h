#include <iostream>
#include <cstdlib>
#include "Grafo.h"

class GrafoMatriz : public Grafo{
    private:
    int **matriz;
    int **rfluxo;
    int numVertices;
    int numArestas;

    public:
    GrafoMatriz();
    ~GrafoMatriz();
    int procuraAdjacencia(int vertice, int *adj);
    void imprimeGrafo();
    void redimensionaGrafo(int numv, int numa);
    void insereArco(int origem, int destino);
    int consultaNumVertices();
    void defineNumVertices(int v);
    void caminhoMaisCurtoD(int v);
    void caminhoMaisCurtoFB(int v);
    void fluxoMaximo(int fonte, int sumidouro);
    bool bfs(int fonte, int sumidouro, int caminho[]);
};

