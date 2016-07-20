#include <iostream>
#include <cstdlib>
#include <limits.h>
#include "Grafo.h"
#include "GrafoMatriz.h"
#include "Fila.h"
#define INT_MAX 100000


GrafoMatriz::GrafoMatriz(){
    numVertices = 0;
    numArestas = 0;
    matriz = NULL;
    rfluxo = NULL;
}

GrafoMatriz::~GrafoMatriz(){

}

int GrafoMatriz::consultaNumVertices(){
    return numVertices;
}

int GrafoMatriz::procuraAdjacencia(int vertice, int *adj){
    int i, tam=0, aux;
    for(i=0; i<numVertices; i++){
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
    for(i=0; i<numVertices; i++){
        for(c=0; c<numVertices; c++){
            std::cout << matriz[i][c] << ", ";
        }
        std::cout << std::endl;
    }
}

void GrafoMatriz::redimensionaGrafo(int numv, int numa){
    int i,c;

    if(matriz!=NULL){
        for(i=0; i<numVertices; i++){
            delete matriz[i];
            delete rfluxo[i];
        }
        delete matriz;
        delete rfluxo;
        matriz=NULL;
        rfluxo = NULL;
    }
    numVertices = numv;
    numArestas = numa;
    matriz = new int* [numVertices];
    rfluxo = new int* [numVertices];
    for(i=0; i<numVertices; i++){
        matriz[i] = new int[numVertices];
        rfluxo[i] = new int[numVertices];
        for(c=0; c<numVertices; c++){
            matriz[i][c] = 0;
            rfluxo[i][c] = 0;
        }
    }
}

void GrafoMatriz::insereArco(int origem, int destino){
    if(matriz!=NULL&&origem<numVertices&&destino<numVertices){
        matriz[origem][destino] = 1;
        numArestas++;
    }else{
        if(matriz==NULL){
            std::cout << "Grafo não dimensionado" << std::endl;
        }else{
            std::cout << "Parametros invalidos" << std::endl;
        }
    }
}

void GrafoMatriz::defineNumVertices(int v){
    numVertices = v;
}

void GrafoMatriz::caminhoMaisCurtoD(int v){
    int dt[numVertices];
    int c, i;
    bool fechados[numVertices];
    for (i = 0; i < numVertices; i++){
      dt[i] = INT_MAX;
      fechados[i] = false;
    }
    dt[v] = 0;

    for (int c = 0; c < numVertices -1; c++){
        int min = INT_MAX, index;
        for (i = 0; i < numVertices; i++){
            if (fechados[i] == false && dt[i] <= min){
                min = dt[i];
                index = i;
            }
        }
        fechados[index] = true;
        for (i = 0; i < numVertices; i++){
            if (!fechados[i] && matriz[index][i] && dt[index] != INT_MAX && dt[index]+matriz[index][i] < dt[i]){
                dt[i] = dt[index] + matriz[index][i];
            }
        }
    }
    for(c=0; c<numVertices; c++){
        if(dt[c]!=INT_MAX){
            std::cout << "Distancia de " << v << " ao ponto " << c << ": " << dt[c] << std::endl;
        }else{
            std::cout << "Vertice " << c << " nao acessivel a partir de " << v << std::endl;
        }
    }
}

void GrafoMatriz::caminhoMaisCurtoFB(int v){
    int dist[numVertices];
    int i, j, c;
    for (i = 0; i < numVertices; i++){
        dist[i]  = INT_MAX;
    }
    dist[v] = 0;
    for(i=0; i<numVertices; i++){ //vertice de origem
        for(j=0; j<numVertices; j++){ //vertice de destino
            if (dist[i]!=INT_MAX && dist[i] + matriz[i][j] <= dist[j]&&matriz[i][j]==1){
                dist[j] = dist[i] + matriz[i][j];
            }
        }
    }
    for(c=0; c<numVertices; c++){
        if(dist[c]!=INT_MAX){
            std::cout << "Distancia de " << v << " ao ponto " << c << ": " << dist[c] << std::endl;
        }else{
            std::cout << "Vertice " << c << " nao acessivel a partir de " << v << std::endl;
        }
    }
}

bool GrafoMatriz::bfs(int fonte, int sumidouro, int caminho[]){
    /*Dado a fonte e o sumidouro, percorro todo o grafo em busca
    de um possível caminho da fonte ao sumidouro e retorno os índices
    do caminho no vetor caminho[]*/
    int i;
    bool visitado[numVertices];
    for(i=0; i<numVertices; i++){
        visitado[i] = false;
    }
    Fila *f = new Fila();
    f->entra(fonte);
    visitado[fonte] = true;
    caminho[fonte]=-1;
    while(!f->vazia()){
        int u = f->consultaInicio();
        f->sai();
        for(i=0; i<numVertices; i++){
            if(visitado[i]==false&&rfluxo[u][i] > 0){
                f->entra(i);
                caminho[i] = u;
                visitado[i] = true;
            }
        }
    }
    return visitado[sumidouro];
}

void GrafoMatriz::fluxoMaximo(int fonte, int sumidouro){
    int i, c;
    int *caminho = new int [numVertices];
    int fluxomaximo = 0;

    for(i=0; i<numVertices; i++){
        for(c=0; c<numVertices; c++){
            rfluxo[i][c] = matriz[i][c];
        }
    }
    //bfs verifica se existe caminho da fonte ao sumidouro
    for(i=0; i<numVertices; i++){
        for(c=0; c<numVertices; c++){
            if(matriz[i][c]==1){
                rfluxo[i][c] = 5;
                rfluxo[c][i] = -5;
            }else{
                rfluxo[i][c] = 0;
            }
        }
    }
    rfluxo[0][6] = 20;
    rfluxo[6][0] = -20;
    rfluxo[6][5] = 20;
    rfluxo[5][6] = -20;

    while(bfs(fonte, sumidouro, caminho)){
        int fluxocaminho = INT_MAX;
        for(i = sumidouro; i!=fonte; i = caminho[i]){ //a cada interação, já que temos um caminho por causa de bfs, iremos ir do sumidouro a fonte
            c = caminho[i]; //  i é o vertice de destino e c é o vertice de origem
            fluxocaminho = std::min(fluxocaminho, rfluxo[c][i]);
        }
        for(i = sumidouro; i!=fonte; i = caminho[i]){
            c = caminho[i];
            rfluxo[c][i] = rfluxo[c][i] - fluxocaminho; //atualiza o rótulo do arco direto
            rfluxo[i][c] = rfluxo[i][c] + fluxocaminho; //atualiza o rótulo do arco reverso
        }
        fluxomaximo = fluxomaximo + fluxocaminho;
    }
    std::cout << "Fluxo maximo: " << fluxomaximo << std::endl;

}
