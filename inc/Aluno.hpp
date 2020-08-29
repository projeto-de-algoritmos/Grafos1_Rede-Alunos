#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <iostream>

using namespace std;

class Aluno {
    protected: 
    int matricula;
    string nome;
    string usuario; 
    string senha; 
    string email; 

    public: 
    Aluno(int matricula, string nome, string senha, string email); 

    int getMatricula();
    void setMatricula(int matricula); 
    string getNome();
    void setNome(string nome);
    string getUsuario();
    void setUsuario(string usuario);  
    string getSenha();
    void setSenha(string senha); 
    string getEmail();
    void setEmail(string email); 
};

#endif 