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
    cout << "Nome: ";
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

}