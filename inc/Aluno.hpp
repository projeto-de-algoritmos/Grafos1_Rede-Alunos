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
    void setMatricula(); 
    string getNome();
    void setNome();
    string getUsuario();
    void setUsuario();  
    string getSenha();
    void setSenha(); 
    string getEmail();
    void setEmail(); 

};

#endif 