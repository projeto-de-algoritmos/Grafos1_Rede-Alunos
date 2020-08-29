#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <iostream>
#include <vector> 
using namespace std;

class Aluno {
    protected: 
        int matricula;
        string nome;
        string usuario; 
        string senha;
        vector <int> amigos; 

    public: 
    Aluno(int matricula, string nome, string usuario,string senha); 

    int getMatricula();
    void setMatricula(int matricula); 
    string getNome();
    void setNome(string nome);
    string getUsuario();
    void setUsuario(string usuario);  
    string getSenha();
    void setSenha(string senha); 
};

#endif 