#include <iostream>
#include <cstdlib>
#include "Grafo.h"
#include "GrafoMatriz.h"

GrafoMatriz::GrafoMatriz(){
    int i,c;
    for(i=0; i<10; i++){
        for(c=0; c<10; c++){
            matriz[i][c]=0;
        }
    }
}

GrafoMatriz::~GrafoMatriz(){

}

int GrafoMatriz::procuraAdjacencia(int vertice, int *adj){
    int i, tam=0, aux;
    for(i=0; i<10; i++){
        aux = matriz[vertice][i];
        if(aux!=0){
            adj[tam] = i;
            tam++;
        }
    }
    return tam;
}

void GrafoMatriz::imprimeGrafo(){
    int i,c;
    for(i=0; i<10; i++){
        for(c=0; c<10; c++){
            std::cout << matriz[i][c] << ", ";
        }
        std::cout << std::endl;
    }
}

void GrafoMatriz::carregaGrafo(){
    /*matriz[0][2] = 1;
    matriz[0][3] = 1;
    matriz[1][3] = 1;
    matriz[2][3] = -1;
    matriz[5][6] = 1;*/
    matriz[0][1] = 1;
    matriz[0][2] = 1;
    matriz[1][2] = 1;
    matriz[3][2] = 1;
    matriz[4][2] = 1;
    matriz[3][4] = 1;
    matriz[2][5] = 1;
    matriz[5][1] = 1;
}
