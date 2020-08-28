#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include <iostream>

using namespace std;

class InterfacePrincipal {
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
    string getString();
    int getInt();
};

#endif