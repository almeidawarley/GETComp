#include <iostream>
#include <cstdlib>
#include "Grafo.h"

class GrafoLista : public Grafo{
    private:
    int *adjacentes[10];
    int conexoes[10];

    public:
    GrafoLista();
    ~GrafoLista();
    int procuraAdjacencia(int vertice, int *adj);
    void imprimeGrafo();
    void carregaGrafo();
};


