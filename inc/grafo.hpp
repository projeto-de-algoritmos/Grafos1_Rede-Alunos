#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Aluno.hpp"

#include <vector>

class Grafo {
private:
    int tamanho;
    vector <Aluno> alunos;

public:
    Grafo();
    void adicionaAluno(Aluno aluno);
    void imprimeGrafo();
    int getTamanho();
};

#endif