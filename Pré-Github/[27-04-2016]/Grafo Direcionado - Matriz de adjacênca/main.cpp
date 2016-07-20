#include <iostream>
#include "GrafoMatriz.h"

using namespace std;

int main()
{
    GrafoMatriz g;
    cout << "Impressao da matriz para conferencia" << endl;
    g.imprimeMatriz();
    cout << "Busca em profundidade" << endl;
    g.buscaProfundidade();
    cout << "Busca em largura" << endl;
    g.buscaLargura();
    return 0;
}
