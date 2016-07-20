#include <iostream>
#include <cstdlib>
#include "Grafo.h"
#include "GrafoLista.h"

GrafoLista::GrafoLista(){
    numVertices = 0;
    numArestas = 0;
    adjacentes = NULL;
    conexoes = NULL;
}

GrafoLista::~GrafoLista(){

}

int GrafoLista::consultaNumVertices(){
    return numVertices;
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
    for(i=0; i<numVertices; i++){
        std::cout << "Vertice" << i << " - ";
        for(c=0; c<conexoes[i]; c++){
            std::cout << adjacentes[i][c] << ", ";
        }
        std::cout << std::endl;
    }
}

void GrafoLista::redimensionaGrafo(int numv, int numa){
    int i,c;
    if(conexoes!=NULL){
        delete conexoes;
        conexoes==NULL;
    }
    if(adjacentes!=NULL){
        for(i=0; i<numVertices; i++){
            delete adjacentes[i];
        }
        delete adjacentes;
        adjacentes = NULL;
    }
    numVertices = numv;
    numArestas = numa;
    conexoes = new int [numVertices];
    for(i=0; i<numVertices; i++){
        conexoes[i] = 0;
    }
    adjacentes = new int *[numVertices];
    for(i=0; i< numVertices; i++){
        adjacentes[i] = new int [numVertices];
        for(c=0; c<numVertices; c++){
            adjacentes[i][c] = 0;
        }
    }
}

void GrafoLista::insereArco(int origem, int destino){
    if(conexoes!=NULL&&adjacentes!=NULL&&origem<numVertices&&destino<numVertices){
        adjacentes[origem][conexoes[origem]] = destino;
        conexoes[origem] = conexoes[origem] + 1;
        numArestas++;
    }else{
        if(conexoes==NULL||adjacentes==NULL){
            std::cout << "Grafo não dimensionado" << std::endl;
        }else{
            std::cout << "Parametros invalidos" << std::endl;
        }
    }
}

void GrafoLista::defineNumVertices(int v){
    numVertices = v;
}

void GrafoLista::caminhoMaisCurtoD(int v){

}

void GrafoLista::caminhoMaisCurtoFB(int v){

}
