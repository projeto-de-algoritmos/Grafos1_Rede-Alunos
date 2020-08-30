#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Aluno.hpp"

#include <vector>

class Grafo {
private:
    int tamanho;
    vector<vector<int>> ids;

public:
    Grafo();
    void adicionaAluno(Aluno aluno);
    int getTamanho();
    void imprimeGrafo();
    void novoVertice();
    void conectar(int id1, int id2);
    void desconectar(int id1, int id2);
    void localizaDeleta(int id1, int id2);
    vector <int> getLinhaIds(int id); 
};

#endif