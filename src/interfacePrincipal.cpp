#include "interfacePrincipal.hpp"

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
    cout << "(1) Criar conta" << endl;
    cout << "(2) Fazer login" << endl;
    opcao = getInt();
    if(opcao == 1)
        menuCriarConta();
    else
        menuFazerLogin();
}

void InterfacePrincipal::menuCriarConta() {
    string nome, usuario, senha;
    cout << "Nome completo: ";
    nome = getString();
    cout << "Nome de usuário: ";
    usuario = getString();
    cout << "Senha: ";
    senha = getString();
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
    while (true){
        system("clear"); 
        int opcao; 
        cout << "(1) Amigos" << endl;
        cout << "(2) Grupos de estudo" << endl; 
        cout << "(3) Gerenciar perfil" << endl;
        cout << "(4) Sair da conta" << endl; 
        opcao = getInt(); 

        switch (opcao){
            case 1:{
                menuAmigos();     
                break;
            }
            case 2: {
                menuGrupos();  
                break;
            }
            case 3: {
                menuConfiguracao();  
                break;
            }
            default:
                paraLoop = 1;
                break; 
        }
        if(paraLoop == 1)
            break; 
    }
}

void InterfacePrincipal::menuAmigos(){
    int opcao; 
    cout << "(1) Meus amigos" << endl;
    cout << "(2) Adicionar amigo" << endl; 
    cout << "(3) Voltar" << endl; 
    opcao = getInt(); 

    if(opcao == 1){

    }
    else if(opcao == 3){

    }
    else{

    }
}

void InterfacePrincipal::menuGrupos(){
    int opcao; 
    cout << "(1) Meus grupos" << endl;
    cout << "(2) Criar grupo" << endl; 
    cout << "(3) Voltar" << endl; 
    opcao = getInt(); 
}

void InterfacePrincipal::menuConfiguracao(){
    int opcao; 
    cout << "(1) Atualizar dados" << endl;
    cout << "(2) Excluir conta" << endl; 
    cout << "(3) Voltar" << endl; 
    opcao = getInt(); 
}
