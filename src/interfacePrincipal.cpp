#include "interfacePrincipal.hpp"
#include "Aluno.hpp"

#include <iostream>

using namespace std;

InterfacePrincipal::InterfacePrincipal() {
    menuLogin();
}

string InterfacePrincipal::getString() {
    string valor;
    cin >> valor;
    cin.ignore(32767, '\n');
    return valor;
}

int InterfacePrincipal::getInt() {
    int valor;
    cin >> valor;
    cin.ignore(32767, '\n');
    return valor;
}

void InterfacePrincipal::menuLogin() {
    int opcao;
    while(true) {
        cout << "(1) Criar conta" << endl;
        cout << "(2) Fazer login" << endl;
        cout << "(3) Sair" << endl;
        opcao = getInt();
        if(opcao == 1)
            menuCriarConta();
        else if(opcao == 2)
            menuFazerLogin();
        else 
            break; 
    }
}


void InterfacePrincipal::menuCriarConta() {
    string nome, usuario, senha;
    int matricula;
    cout << "Matricula: ";
    matricula = getInt();
    cout << "Nome completo: ";
    nome = getString();
    cout << "Nome de usuário: ";
    usuario = getString();
    cout << "Senha: ";
    senha = getString();
    Aluno aluno = Aluno(ids.getTamanho(), matricula, nome, usuario, senha);
    alunos.push_back(aluno);
    ids.adicionaAluno(aluno);
    menuPrincipal();
}

void InterfacePrincipal::menuFazerLogin() {
    string nome, senha;
    cout << "Nome de usuário: ";
    nome = getString();
    cout << "Senha: ";
    senha = getString();
    menuPrincipal();
}

void InterfacePrincipal::menuPrincipal() {
    int paraLoop = 0;
    while(true) {
        int opcao;
        cout << "(1) Amigos" << endl;
        cout << "(2) Grupos de estudo" << endl;
        cout << "(3) Gerenciar perfil" << endl;
        cout << "(4) Visualizar grafo" << endl;
        cout << "(5) Sair da conta" << endl;
        opcao = getInt();
        switch(opcao) {
            case 1:
                menuAmigos();     
                break;
            case 2:
                menuGrupos();  
                break;
            case 3:
                menuConfiguracao();  
                break;
            case 4:
                break;
            default:
                paraLoop = 1;
        }
        if(paraLoop == 1)
            break;
    }
}

void InterfacePrincipal::menuAmigos() {
    int opcao;
    cout << "(1) Meus amigos" << endl;
    cout << "(2) Adicionar amigo" << endl;
    cout << "(3) Voltar" << endl;
    opcao = getInt();
}

void InterfacePrincipal::menuGrupos() {
    int opcao; 
    cout << "(1) Meus grupos" << endl;
    cout << "(2) Criar grupo" << endl; 
    cout << "(3) Voltar" << endl; 
    opcao = getInt(); 
}

void InterfacePrincipal::menuConfiguracao() {
    int opcao; 
    cout << "(1) Atualizar dados" << endl;
    cout << "(2) Excluir conta" << endl; 
    cout << "(3) Voltar" << endl; 
    opcao = getInt(); 

    if(opcao == 1){
        menuAtualizacao(); 
    }
    else if(opcao == 2){

    }
    else{

    }
}

void InterfacePrincipal::menuAtualizacao(){ 
    int opcao; 
    cout << "Escolha o dado que deseja atualizar:" << endl << endl;
    cout << "(1) Nome: " <<  endl;
    cout << "(2) Senha" << endl; 
    cout << "(3) Voltar" << endl; 
    opcao = getInt(); 
}
