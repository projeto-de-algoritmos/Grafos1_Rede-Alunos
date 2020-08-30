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
