#ifndef GRUPO_HPP
#define GRUPO_HPP

#include "Aluno.hpp"

using namespace std;

class Grupo{
    private: 
        int id; 
        string nome;
        string descricao;
        vector <int> membros; 
    
    public: 
        Grupo(int id, string nome, string descricao);
        int getId();
        string getNome();
        void setNome(string nome);
        string getDescricao();
        void setDescricao(string descricao); 
        vector <int> getMembros(); 

};

#endif

