#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "No.h"

using namespace std;

class FilaEncad
{
private:
    No *ini;
    No *fim;      // ponteiros para os No�s extremos
public:
    FilaEncad ();
    ~FilaEncad();
    int consultaInicio();
    void entra(int val); // insere No no fim
    void sai();            // elimina No do in�cio da fila
    bool vazia();          // verifica se fila est� vazia
};

#endif // FILA_H_INCLUDED
