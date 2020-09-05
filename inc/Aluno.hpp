#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <iostream>
#include <vector> 

using namespace std;

class Aluno {
private:
    int id;
    int matricula;
    string nome;
    string usuario;
    string senha;
    bool ativo; 

public:
    Aluno(int id, int matricula, string nome, string usuario,string senha); 
    int getMatricula();
    void setMatricula(int matricula); 
    string getNome();
    void setNome(string nome);
    string getUsuario();
    void setUsuario(string usuario);  
    string getSenha();
    void setSenha(string senha); 
    int getId(); 
    void imprimeDados(); 
    bool verificaUsuario(string usuario);
    bool verificaSenha(string senha);
    bool isAtivo();
    void setIsAtivo(bool ativo); 
};

#endif 