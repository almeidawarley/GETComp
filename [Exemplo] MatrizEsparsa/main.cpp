#include <iostream>
#include "matrizesparsa.h"
using namespace std;

int main()
{
    MatrizEsparsa m(10);
    m.insere(1, 9, 9);
    m.insere(1, 7, 8);
    m.imprime();
    return 0;
}
