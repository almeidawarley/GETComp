#include <iostream>
#include "Grafo.h"
#include "GrafoMatriz.h"
#include "GrafoLista.h"
#include "buscaEmGrafo.h"

using namespace std;

int main()
{
    Grafo *g;
    GrafoMatriz gm;
    GrafoLista gl;

    g = &gm;
    g->carregaGrafo();
    buscaEmGrafo b1(g);
    cout << "Grafo em matriz de adjacencia: " << endl;
    cout << "- busca em profundidade: " << endl;
    b1.buscaProfundidade();
    cout << "- busca em largura: " << endl;
    b1.buscaLargura();

    g = &gl;
    g->carregaGrafo();
    buscaEmGrafo b2(g);
    cout << endl;
    cout << "Grafo em lista de incidencia: " << endl;
    cout << "- busca em profundidade: " << endl;
    b2.buscaProfundidade();
    cout << "- busca em largura: " << endl;
    b2.buscaLargura();
    return 0;
}
