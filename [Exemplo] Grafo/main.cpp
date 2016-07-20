#include <iostream>
#include "Grafo.h"
#include "GrafoMatriz.h"
#include "GrafoLista.h"
#include "buscaEmGrafo.h"
#include "carregaGrafo.h"

using namespace std;

int main()
{
    Grafo *g;
    GrafoMatriz gm;
    //GrafoLista gl;
    carregaGrafo *c;

    cout << "********************* GRAFO MATRIZ *****************************" << endl;

    g = &gm;

    c = new carregaGrafo(g);
    c->carregaDeArquivo();

    buscaEmGrafo b1(g);
    cout << "Grafo em matriz de adjacencia: " << endl;
    cout << "- impressao do grafo:" << endl;
    g->imprimeGrafo();
    cout << "- caminho mais curto por Dijkstra: " << endl;
    g->caminhoMaisCurtoD(0);
    cout << "- caminho mais curto por Ford Bellman: " << endl;
    g->caminhoMaisCurtoFB(0);
    cout << "- fluxo maximo por Ford & Fullkerson: "<<endl;
    g->fluxoMaximo(0,5);

    cout << "- busca em profundidade: " << endl;
    //b1.buscaProfundidade();
    cout << "- busca em largura: " << endl;
    //b1.buscaLargura();

    /*cout << "********************* GRAFO LISTA *****************************" << endl;

    delete c;

    g = &gl;
    c = new carregaGrafo(g);
    c->carregaDeArquivo();

    buscaEmGrafo b2(g);
    cout << endl;
    cout << "Grafo em lista de incidencia: " << endl;
    cout << "- impressao do grafo:" << endl;
    g->imprimeGrafo();
    cout << "- busca em profundidade: " << endl;
    b2.buscaProfundidade();
    cout << "- busca em largura: " << endl;
    b2.buscaLargura();
    */
    delete c;
    return 0;
}
