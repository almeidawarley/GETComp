#include <iostream>
#include <cstdlib>
#include "Grafo.h"
#include "carregaGrafo.h"
#include <fstream>

using namespace std;

carregaGrafo::carregaGrafo(Grafo *grafo){
    g = grafo;
}

carregaGrafo::~carregaGrafo(){

}

void carregaGrafo::carregaDeArquivo(){
    ifstream arquivo;
    int i,c,f, linhas = 0;
    int maior = 0;
    arquivo.open("teste.txt");
    while(arquivo>>i>>c){
        //cout << i << " - " << c << endl;
        if(maior<i){
            maior = i;
        }
        if(maior<c){
            maior = c;
        }
        linhas++;
    }
    //cout << "MAIOR: " << maior << endl;
    arquivo.close();
    arquivo.open("teste.txt");
    g->redimensionaGrafo(maior+1, 0);
    for(f=0; f<linhas; f++){
        arquivo >> i >> c;
        g->insereArco(i,c);
        //cout << "Tentando inserir : " << i  << " - " << c << endl;
    }
}
