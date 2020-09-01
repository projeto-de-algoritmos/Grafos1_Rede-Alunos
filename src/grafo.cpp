#include "grafo.hpp"

#include <algorithm>


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
    int tamanhoLista = ids[id1].size();
    for(int i = 0; i < tamanhoLista; i++) {
        if(ids[id1][i] == id2) {
            ids[id1].erase(ids[id1].begin() + i);
            break;
        }
    }
}

vector <int> Grafo::constroiCiclo(int vertice, int verticeConectado, vector <int> &predecessor) {
    vector <int> ciclo;
    while(verticeConectado != vertice) {
        ciclo.push_back(verticeConectado);
        verticeConectado = predecessor[verticeConectado];
    }
    ciclo.push_back(vertice);
    return ciclo;
}

void Grafo::dfsCiclo(int vertice, vector <bool> &visitados, vector <bool> &finalizados, vector <int> &predecessor, vector <bool> &buscados, vector <vector <int>> &ciclos) {
    visitados[vertice] = true;
    int tamanhoLista = ids[vertice].size();
    for(int i = 0; i < tamanhoLista; i++) {
        int verticeConectado = ids[vertice][i];
        if(!visitados[verticeConectado]) {
            predecessor[verticeConectado] = vertice;
            dfsCiclo(verticeConectado, visitados, finalizados, predecessor, buscados, ciclos);
        } else if(finalizados[verticeConectado])
            ciclos.push_back(constroiCiclo(vertice, verticeConectado, predecessor));
    }
    finalizados[vertice] = true;
    buscados[vertice] = true;
}

vector <vector <int>> Grafo::getCiclos() {
    vector <vector <int>> ciclos;
    vector <bool> buscados(tamanho, false);
    for(int i = 0; i < tamanho; i++) {
        vector <bool> visitados(tamanho, false), finalizados(tamanho, false);
        vector <int> predecessor(tamanho, -1);
        if(!buscados[i])
            dfsCiclo(i, visitados, finalizados, predecessor, buscados, ciclos);
    }
    return ciclos;
}

vector <int> Grafo::bfs(int vertice) {
    vector <bool> visitados(tamanho, false);
    vector <int> fila; 
    vector<int> amigosRecomendados; 
    int qntdVizinhos = ids[vertice].size();
    int cont = 0; 
    int aux =0; 
    bool sugerir = false;  
    visitados[vertice] = true; 
    fila.push_back(vertice);
    while(!fila.empty()){
        int u = fila[0]; 
        fila.erase(fila.begin());
        for(int i:ids[u]){
            if(!visitados[i]){
                visitados[i] = true;
                fila.push_back(i); 
                if(sugerir){
                   amigosRecomendados.push_back(i); 
                }
            } 
            cont++;
        } 
        if(cont == qntdVizinhos){
            aux = cont; 
            for(int j=0; j<qntdVizinhos; j++){
                aux += ids[fila[j]].size(); 
            }
            sugerir = true; 
        }
        if(cont == aux)
            break; 
    }
    return amigosRecomendados;     
}

vector <int> Grafo::GrauConectividade(int vertice){
    vector<int> pesos(tamanho, 0);
    vector<int> vizinhos = ids[vertice]; 
    for(int i:vizinhos){
        for(int j : ids[i]){
            cout << j <<"[" <<pesos[j] << "]"; 
            pesos[j]++; 
        }
    }
    return pesos;  
}
vector <int> Grafo::getListaAdjacencia(int id) {
    return ids[id];
}

int Grafo::getQtdDesconectados() {
    int contador = 0;
    for(int i = 0; i < tamanho; i++) {
        if(ids[i].empty())
            contador++;
    }
    return contador;
}