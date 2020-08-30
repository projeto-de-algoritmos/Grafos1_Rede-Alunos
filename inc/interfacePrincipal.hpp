#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "grafo.hpp"

#include <iostream>

using namespace std;

class InterfacePrincipal {
private:
    Grafo ids;
    vector <Aluno> alunos;
    int alunoAtual;
public:
    InterfacePrincipal();
    void menuLogin();
    void menuCriarConta();
    void menuFazerLogin();
    void menuPrincipal();
    void menuAmigos();
    void menuGrupos();  
    void menuConfiguracao();  
    void menuAtualizacao();  
    void mostrarPerfil(); 
    string getString();
    int getInt();
    bool verificaCredenciais(string usuario, string senha);
    bool validacaoCadastro(Aluno aluno);  
    void adicionarAmigo();
    void mostrarAmigos(); 
    void removerAmigo();
};

#endif