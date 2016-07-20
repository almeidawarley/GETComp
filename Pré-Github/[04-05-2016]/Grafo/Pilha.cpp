#include <iostream>
#include <cstdlib>
#include "Pilha.h"

Pilha::Pilha(){
    int i;
    tamanho = 100;
    fim = -1;
}

Pilha::~Pilha(){

}

void Pilha::empilha(int valor){
    fim++;
    vetor[fim] = valor;
}

void Pilha::desempilha(){
    fim--;
}

bool Pilha::vazia(){
    if(fim == -1){
        return true;
    }
    return false;
}

int Pilha::consultaTopo(){
    return vetor[fim];
}

void Pilha::imprime(){
    int i;
    for(i=0; i<fim; i++){
        std::cout << "Elemento " << i << ": " << vetor[i];
    }
}

