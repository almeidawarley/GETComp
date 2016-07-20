#include <iostream>
#include <cstdlib>
#include "Lista.h"

Lista::Lista(int t){
    tamanho = t;
    vetor = new int[100];
    ultimo = -1;
}

Lista::~Lista(){
    delete vetor;
}
void Lista::insereInicio(int valor){
    insereK(0, valor);
}
void Lista::insereUltimo(int valor){
    ultimo++;
    vetor[ultimo] = valor;
}
void Lista::insereK(int k, int valor){
    int f;
    ultimo++;
    for(f=ultimo; f>k; f--){
        vetor[f] = vetor[f-1];
    }
    vetor[k] = valor;
}
void Lista::eliminaUltimo(){
    ultimo--;
}

void Lista::eliminaValor(int valor){
    int f,c;
    for(f=0; f<ultimo; f++){
        if(vetor[f]==valor){
            for(c=f; c<ultimo; c++){
                vetor[c] = vetor[c+1];
            }
            ultimo--;
        }
    }
}
void Lista::imprime(){
    int i;
    for(i=0; i<=ultimo; i++){
        std::cout << vetor[i];
    }
}
bool Lista::vazia(){
    if(ultimo==-1){
        return true;
    }
    return false;
}
int Lista::consultaInicio(){
    if(!vazia()){
        return vetor[0];
    }
}
int Lista::consultaUltimo(){
    if(!vazia()){
        return vetor[ultimo];
    }
}
int Lista::consultaK(int k){
    if(k<ultimo){
        return vetor[k];
    }else{
        return -1;
    }
}

void Lista::insereEmOrdem(int valor){
    int i;
    bool aux = false;
    for(i=0; i<=ultimo; i++){
        if(vetor[i]<valor){
            insereK(i, valor);
            aux = true;
        }
    }
    if(!aux){
        insereUltimo(valor);
    }
}

int Lista::retornaTamanho(){
    return ultimo+1;
}

/*bool Lista::existeValor(int valor){
    int g;
    for(g=0; g<=ultimo; g++){
        if(vetor[g]==valor){
            return true;
        }
    }
    return false;
}*/
