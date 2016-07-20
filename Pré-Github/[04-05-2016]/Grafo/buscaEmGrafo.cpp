#include <iostream>
#include <cstdlib>
#include "Grafo.h"
#include "Fila.h"
#include "Pilha.h"
#include "buscaEmGrafo.h"

buscaEmGrafo::buscaEmGrafo(Grafo *grafo){
    g = grafo;
}

buscaEmGrafo::~buscaEmGrafo(){

}

void buscaEmGrafo::buscaLargura(){
    Fila fila;
    int i, aux, c, tam, adjacentes[10];
    bool visitados[10];

    for(i=0;i<10; i++){
        visitados[i] = false;
    }
    for(i=0; i<10; i++){
        fila.entra(i);
        while(!fila.vazia()){
            aux = fila.consultaInicio();
            fila.sai();
            if(!visitados[aux]){
                tam = g->procuraAdjacencia(aux, adjacentes);
                for(c=0; c<tam; c++){
                    fila.entra(adjacentes[c]);
                    std::cout << "Existe conexao entre " << aux << " e " << adjacentes[c] << std::endl;
                }
            }
            visitados[aux] = true;
        }
    }
}

void buscaEmGrafo::buscaProfundidade(){
    int adjacentes[10];
    int oi;
    int i, c, aux, tam=-1, topo;
    bool visitados[10];
    Pilha pilha;

    for(i=0;i<10; i++){
        visitados[i] = false;
    }

    for(i=0; i<10; i++){
        pilha.empilha(i);
        while(!pilha.vazia()){
            topo = pilha.consultaTopo();
            pilha.desempilha();
            if(!visitados[topo]){
                visitados[topo] = true;
                tam = g->procuraAdjacencia(topo, adjacentes);
                for(c=0; c<tam; c++){
                    aux = adjacentes[c];
                    pilha.empilha(adjacentes[c]);
                    std::cout << "Existe conexao entre " << topo << " e " << aux << std::endl;
                }
                //
            }
        }
    }
}
