#include <iostream>
#include <cstdlib>
#include "GrafoLista.h"
#include "PilhaEncad.h"

GrafoLista::GrafoLista(){
    int i,c;

    for(i=0;i<10;i++){
        vetor[i] = new int[2];
        for(c=0; c<2; c++){
            vetor[i][c]=0;
        }
    }
    vetor[0][0] = 2;
    vetor[0][1] = 3;
    vetor[2][0] = 6;
    vetor[6][0] = 9;
}

GrafoLista::~GrafoLista(){
    int i;
    for(i=0; i<10; i++){
        delete vetor[i];
    }
    delete vetor;
}

void GrafoLista::buscaProfundidade(){
    int i, c;
}

void GrafoLista::buscaLargura(){

}

void GrafoLista::imprimeLista(){
    int i,c;

    for(i=0; i<10; i++){
        std::cout << "Grafo " << i  << ": ";
        for(c=0; c<2; c++){
            std::cout << vetor[i][c] << ", ";
        }
        std::cout << std::endl;
    }
}

