#include "FilaEncad.h"

FilaEncad::FilaEncad()
{
    cout << "Criando FilaEncad" << endl;
    ini = NULL;
    fim = NULL;
}

FilaEncad::~FilaEncad()
{
    cout << "Destruindo FilaEncad" << endl;
    No* p = ini;
    while(ini != NULL)
    {
        ini = p->getProx();
        delete p;
        p = ini;
    }
    fim = NULL;
}

bool FilaEncad::vazia()
{
    if(ini == NULL)
        return true;
    else
        return false;
}

void FilaEncad::entra(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim == NULL)
        ini = p;
    else
        fim->setProx(p);
    fim = p;
}

int FilaEncad::consultaInicio()
{
    if(ini != NULL)
        return ini->getInfo();
    else
    {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::sai()
{
    No* p;
    if(ini != NULL)
    {
        p = ini;
        ini = p->getProx();
        if(ini == NULL)
            fim = NULL;
        delete p;
    }
    else
    {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
}
