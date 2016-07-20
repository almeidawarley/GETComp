#include <iostream>
#include <cstdlib>
#include "Grafo.h"

class buscaEmGrafo{
    Grafo *g;

    public:
    buscaEmGrafo(Grafo *grafo);
    void buscaLargura();
    void buscaProfundidade();
    ~buscaEmGrafo();
};
