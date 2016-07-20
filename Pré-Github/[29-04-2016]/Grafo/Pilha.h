#include <iostream>
#include <cstdlib>

class Pilha{
    private:
    int fim, tamanho;
    int vetor[100];

    public:
    Pilha();
    ~Pilha();
    void empilha(int valor);
    void desempilha();
    void imprime();
    bool vazia();
    int consultaTopo();
};



