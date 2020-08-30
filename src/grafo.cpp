#include "grafo.hpp"

Grafo::Grafo() {
    tamanho = 0;
}

int Grafo::getTamanho() {
    return tamanho;
}

void Grafo::imprimeGrafo() {
    for(int i = 0; i < tamanho; i++) {
        cout << i << " -> ";
        for(int j: ids[i])
            cout << j << "   ";
        cout << endl;
    }
}

void Grafo::novoVertice() {
    ids.resize(tamanho + 1);
    tamanho++;
}

void Grafo::conectar(int id1, int id2) {
    ids[id1].push_back(id2);
    ids[id2].push_back(id1);
}
