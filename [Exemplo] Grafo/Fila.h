#include <iostream>
#include <cstdlib>

class Fila{
    private:
    int inicio, fim, tamanho;
    int vetor[100];

    public:
    Fila();
    ~Fila();
    void entra(int valor);
    void sai();
    void imprime();
    bool vazia();
    int consultaInicio();
};


