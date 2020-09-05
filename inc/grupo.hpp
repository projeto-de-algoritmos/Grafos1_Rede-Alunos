#ifndef GRUPO_HPP
#define GRUPO_HPP

#include "Aluno.hpp"

using namespace std;

class Grupo{
    private: 
        int id; 
        string nome;
        string descricao;
        vector <Aluno> membros; 
    
    public: 
        Grupo(string nome, string descricao);
        int getId(); 
        void setId(int id);
        string getNome();
        void setNome(string nome);
        string getDescricao();
        void setDescricao(string descricao);  
};

#endif

