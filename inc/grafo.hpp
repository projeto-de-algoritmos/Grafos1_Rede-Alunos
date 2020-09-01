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
    vector <int> getListaAdjacencia(int id); 
    void getCiclos(int vertice);
    void dfsCiclo(int vertice, vector <bool> &visitados, vector <bool> &finalizados, vector <int> &predecessor);
    void imprimeCiclo(int vertice, int verticeConectado, vector <int> &predecessor);
    vector <int> bfs(int vertice);
    vector <int> GrauConectividade( int vertice); 

};

#endif