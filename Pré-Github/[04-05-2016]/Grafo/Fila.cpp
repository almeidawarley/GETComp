#include <iostream>
#include <cstdlib>
#include "Fila.h"

Fila::Fila(){
    int i;
    inicio = 0;
    tamanho = 100;
    fim = 0;
    /*for(i=0; i<100; i++){
        vetor[i] = 0;
    } */
}

Fila::~Fila(){

}

void Fila::entra(int valor){
    if(tamanho==fim){
        std::cout << "Fila cheia!";
    }else{
        vetor[fim] = valor;
        fim++;
        tamanho++;
    }
}

void Fila::sai(){
    inicio++;
    tamanho--;
}

void Fila::imprime(){
    int c;
    for(c=inicio; c<fim; c++){
        std::cout << vetor[c];
    }
}

bool Fila::vazia(){
    if(inicio==fim){
        return true;
    }
    return false;
}

int Fila::consultaInicio(){
    return vetor[inicio];
}
