#include <iostream>
#include <cstdlib>

class Lista{
    private:
    int ultimo, tamanho;
    int *vetor;

    public:
    Lista(int t);
    ~Lista();
    void insereInicio(int valor);
    void insereUltimo(int valor);
    void insereK(int k, int valor);
    void insereEmOrdem(int valor);
    void eliminaUltimo();
    void eliminaValor(int valor);
    void imprime();
    bool vazia();
    int consultaInicio();
    int consultaUltimo();
    int consultaK(int k);
    int retornaTamanho();
    bool consultaValor(int valor);
};
