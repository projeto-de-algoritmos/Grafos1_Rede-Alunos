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

void Grafo::desconectar(int id1, int id2) {
    localizaDeleta(id1, id2);
    localizaDeleta(id2, id1);
}

void Grafo::localizaDeleta(int id1, int id2) {
    for(int i = 0; i < ids[id1].size(); i++) {
        if(ids[id1][i] == id2)
            ids[id1].erase(ids[id1].begin() + i);
    }
}

vector <int> Grafo::getLinhaIds(int id){
    return ids[id]; 
} 