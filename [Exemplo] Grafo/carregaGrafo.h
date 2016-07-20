#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

class carregaGrafo{
    private:
    Grafo *g;

    public:
    carregaGrafo(Grafo *grafo);
    ~carregaGrafo();
    void carregaDeArquivo();

};
