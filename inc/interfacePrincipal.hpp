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
    bool verificaCredenciais(string usuario, string senha);
    bool validacaoCadastro(Aluno aluno);  
    bool validacaoAmizade(int id1, int id2);
    bool validacaoUsuario(string usuario); 
    void adicionarAmigo();
    void mostrarAmigos(); 
    void removerAmigo();
    void sugerirAmigos();
    void mostrarGrupos(); 
    void menuCriarGrupo(); 
    void menuAvancado();
    void menuAdmin();
    void menuEstatisticas();
    void menuAmigosAdmin(bool adicionar);
    vector <int> procuraIds(string usuario1, string usuario2);
};

#endif