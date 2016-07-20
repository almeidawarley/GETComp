#include <iostream>
#include <cstdlib>
#include "Grafo.h"

class GrafoMatriz : public Grafo{
    private:
    int matriz[10][10];

    public:
    GrafoMatriz();
    ~GrafoMatriz();
    int procuraAdjacencia(int vertice, int *adj);
    void imprimeGrafo();
    void carregaGrafo();
};

