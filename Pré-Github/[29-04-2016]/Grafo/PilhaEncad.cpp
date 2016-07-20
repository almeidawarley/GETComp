#include "PilhaEncad.h"

// construtor
PilhaEncad::PilhaEncad()
{
    cout << "Criando PilhaEncad" << endl;
    topo = NULL;
}

// destrutor
PilhaEncad::~PilhaEncad()
{
    cout << "Destruindo PilhaEncad" << endl;
    No* p = topo;
    while(topo != NULL)
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

void PilhaEncad::empilha(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
}

void PilhaEncad::desempilha()
{
    No* p;
    if(topo != NULL)
    {
        p = topo;
        topo = p->getProx();
        delete p;
    }
    else
    {
        cout << "Erro" << endl;
        exit(1);
    }
}

int PilhaEncad::consultaTopo()
{
    if(topo != NULL)
        return topo->getInfo();
    else
    {
        cout << "Pilha vazia!" << endl;
        exit(1);
    }
}

bool PilhaEncad::vazia()
{
    if(topo == NULL)
        return(true);
    else
        return(false);
}

void PilhaEncad::imprime()
{
    // implemente aqui ...
}
