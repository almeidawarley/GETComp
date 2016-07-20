#include <iostream>
#include <cstdlib>
#include "GrafoMatriz.h"
#include "PilhaEncad.h"

GrafoMatriz::GrafoMatriz(){
    int i, c;

    for(i=0; i<10; i++){
        for(c=0; c<10; c++){
            matriz[i][c]=0;
        }
    }
    //Inicialização de um grafo qualquer
    matriz[0][2]=1;
    matriz[2][5]=1;
    matriz[0][1]=1;
    matriz[1][4]=1;
    matriz[6][5]=-1;

}

GrafoMatriz::~GrafoMatriz(){

}

void GrafoMatriz::buscaProfundidade(){
    int i,c;
    for(i=0; i<10; i++){
        for(c=0; c<10; c++){
            if(matriz[i][c]!=0){
                if(matriz[i][c]==1){
                    std::cout << "Existe conexao entre " << i << " e " << c << std::endl;
                }
                if(matriz[i][c]==(-1)){
                    std::cout << "Existe conexao entre " << c << " e " << i << std::endl;
                }
            }
        }
    }
}

void GrafoMatriz::buscaLargura(){
    int i, aux;
    PilhaEncad p1;
    p1.empilha(0);
    while(!p1.vazia()){
        aux = p1.consultaTopo();
        p1.desempilha();
        for(i=0; i<10; i++){
            if(matriz[aux][i]!=0){
                p1.empilha(i);
                if(matriz[aux][i]==1){
                    std::cout<<"Existe conexao entre " << aux << " e " << i << std::endl;
                }else{
                    std::cout<<"Existe conexao entre " << i << " e " << aux << std::endl;
                }
            }
        }
    }
}

void GrafoMatriz::imprimeMatriz(){
    int i,c;
    for(i=0; i<10;i++){
        for(c=0; c<10;c++){
            std::cout << matriz[i][c] << " - ";
        }
        std::cout<<std::endl;
    }
}
