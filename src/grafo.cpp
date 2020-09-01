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
        if(ids[id1][i] == id2)
            ids[id1].erase(ids[id1].begin() + i);
    }
}

vector <int> Grafo::getLinhaIds(int id){
    return ids[id]; 
} 

void Grafo::imprimeCiclo(int vertice, int verticeConectado, vector <int> &predecessor) {
    while(verticeConectado != vertice) {
        cout << verticeConectado << "   ";
        verticeConectado = predecessor[verticeConectado];
    }
    cout << vertice << endl;
}

void Grafo::dfsCiclo(int vertice, vector <bool> &visitados, vector <bool> &finalizados, vector <int> &predecessor) {
    visitados[vertice] = true;
    int tamanhoLista = ids[vertice].size();
    for(int i = 0; i < tamanhoLista; i++) {
        int verticeConectado = ids[vertice][i];
        if(visitados[verticeConectado] == false) {
            predecessor[verticeConectado] = vertice;
            dfsCiclo(verticeConectado, visitados, finalizados, predecessor);
        } else if(finalizados[verticeConectado] == true)
            imprimeCiclo(vertice, verticeConectado, predecessor);
    }
    finalizados[vertice] = 1;
}

void Grafo::getCiclos(int vertice) {
    vector <bool> visitados(tamanho, false), finalizados(tamanho, false);
    vector <int> predecessor(tamanho, -1);
    dfsCiclo(vertice, visitados, finalizados, predecessor);
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

vector <int> Grafo::GrauConectividade(vector <int> verticesConectados,int vertice){
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