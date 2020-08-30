#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Aluno.hpp"

#include <vector>

class Grafo {
private:
    int tamanho;
    vector <int> ids; 

public:
    Grafo();
    void adicionaAluno(Aluno aluno);
    int getTamanho();
};

#endif