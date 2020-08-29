#include "grafo.hpp"

Grafo::Grafo() {
    tamanho = 0;
}

void Grafo::adicionaAluno(Aluno aluno) {
    alunos.push_back(aluno);
}

void Grafo::imprimeGrafo() {
    for(Aluno a: alunos) {
        cout << a.getId() << " -> ";
        for(int i: a.getConexoes())
            cout << i << "   ";
        cout << endl;
    }
}

int Grafo::getTamanho() {
    return tamanho;
}