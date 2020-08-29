#include "grafo.hpp"

Grafo::Grafo() {
    tamanho = 0;
}

void Grafo::adicionaAluno(Aluno aluno) {
    ids.push_back(aluno.getId());
    tamanho++; 
}


int Grafo::getTamanho() {
    return tamanho;
}
