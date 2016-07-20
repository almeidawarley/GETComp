#include <iostream>
#include <cstdlib>

class GrafoMatriz{
    private:
    int matriz[10][10];

    public:
    GrafoMatriz();
    ~GrafoMatriz();
    void buscaLargura();
    void buscaProfundidade();
    void imprimeMatriz();
};
