#include <iostream>
#include <cstdlib>

class GrafoLista{
    private:
    int *vetor[10];

    public:
    GrafoLista();
    ~GrafoLista();
    void buscaLargura();
    void buscaProfundidade();
    void imprimeLista();
};
