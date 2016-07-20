#include <iostream>
#include <cstdlib>
#include "Grafo.h"
#include "GrafoLista.h"

GrafoLista::GrafoLista(){
    int i;
    for(i=0;i<10;i++){
        conexoes[i]=0;
        adjacentes[i] = new int[10];
    }
}

GrafoLista::~GrafoLista(){

}

int GrafoLista::procuraAdjacencia(int vertice, int *adj){
    int i;
    for(i=0; i<conexoes[vertice]; i++){
        adj[i] = adjacentes[vertice][i];
    }
    return conexoes[vertice];
}

void GrafoLista::imprimeGrafo(){
    int i,c;
    for(i=0; i<10; i++){
        std::cout << "Grafo " << i << " - ";
        for(c=0; c<conexoes[i]; c++){
            std::cout << adjacentes[i][c] << ", ";
        }
        std::cout << std::endl;
    }
}

void GrafoLista::carregaGrafo(){
    adjacentes[0][0] = 1;
    adjacentes[0][1] = 2;
    conexoes[0] = 2;
    adjacentes[1][0] = 2;
    conexoes[1] = 1;
    adjacentes[2][0] = 5;
    conexoes[2] = 1;
    adjacentes[5][0] = 1;
    conexoes[5] = 1;
    adjacentes[3][0] = 2;
    adjacentes[3][1] = 4;
    conexoes[3] = 2;
    adjacentes[4][0] = 2;
    conexoes[4] = 1;
}
