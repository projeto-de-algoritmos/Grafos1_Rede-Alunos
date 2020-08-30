#include "interfacePrincipal.hpp"
#include "Aluno.hpp"

#include <iostream>
#include <algorithm>

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
        cout << "(0) Sair" << endl;
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
    bool validacao; 
    while(true){  
        cout << "Criação de Conta" << endl << endl; 
        cout << "Matricula: ";
        matricula = getInt();
        cout << "Nome completo: ";
        nome = getString();
        cout << "Nome de usuário: ";
        usuario = getString();
        cout << "Senha: ";
        senha = getString();
        Aluno aluno = Aluno(ids.getTamanho(), matricula, nome, usuario, senha);
        validacao = validacaoCadastro(aluno); 
        if(validacao){
            alunoAtual = ids.getTamanho();
            alunos.push_back(aluno);
            ids.novoVertice();
            cout << "Conta criada com sucesso!" << endl; 
            menuPrincipal();
            return; 
        }
        else{
            int opcao; 
            cout << "Conta já cadastrada!" << endl;
            cout << "(1) Fazer Login " << endl;
            cout << "(2) Novo cadastro" << endl;
            opcao = getInt(); 
            if(opcao == 1){
                menuFazerLogin();
                return; 
            }           
        }
    }
}

bool InterfacePrincipal::validacaoCadastro(Aluno aluno){
    for(Aluno i: alunos){
        if(i.getMatricula() == aluno.getMatricula())
            return false; 
    } 
    return true;     
}

void InterfacePrincipal::menuFazerLogin() {
    string usuario, senha;
    bool loop = true;
    while(loop) {
        cout << "Nome de usuário: ";
        usuario = getString();
        cout << "Senha: ";
        senha = getString();
        loop = verificaCredenciais(usuario, senha);
        if(loop == true){
            int opcao; 
            cout << "Credenciais incorretas." << endl;
            cout << "(1)Tentar novamente" << endl;
            cout << "(2)Cadastre-se" << endl;
            opcao = getInt(); 
            if(opcao == 2){
                menuCriarConta();
                return; 
            } 
        }
    }
    menuPrincipal();
}

bool InterfacePrincipal::verificaCredenciais(string usuario, string senha) {
    for(Aluno a: alunos) {
        if(a.verificaUsuario(usuario) && a.verificaSenha(senha)) {
            alunoAtual = a.getId();
            return false;
        }
    }
    return true;
}

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        int opcao;
        cout << "(1) Amigos" << endl;
        cout << "(2) Grupos de estudo" << endl;
        cout << "(3) Gerenciar perfil" << endl;
        cout << "(4) Visualizar grafo" << endl;
        cout << "(0) Sair da conta" << endl;
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
                ids.imprimeGrafo();
                break;
            case 0:
                return; 
        }
    }
}

void InterfacePrincipal::menuAmigos() {
    int opcao;
    cout << "(1) Meus amigos" << endl;
    cout << "(2) Adicionar amigo" << endl;
    cout << "(3) Voltar" << endl;
    opcao = getInt();
    if(opcao == 1)
        mostrarAmigos(); 
    else if(opcao == 2)
        adicionarAmigo();
}

void InterfacePrincipal::mostrarAmigos() {
    cout << "Numero de amigos: " << ids.getLinhaIds(alunoAtual).size()<< endl;
    vector <string> nomesAmigos;
    for (int i: ids.getLinhaIds(alunoAtual)){
        nomesAmigos.push_back(alunos[i].getNome());
    }
    sort(nomesAmigos.begin(), nomesAmigos.end(), [](string a, string b) {return (a > b); }); 
    for(string j: nomesAmigos)
        cout << j << endl; 
}
void InterfacePrincipal::adicionarAmigo() {
    int id;
    cout << "Usuario do aluno: ";
    string usuarioAluno = getString();
    for(Aluno i: alunos){
        if(i.getUsuario() == usuarioAluno){
            id = i.getId();
            break;   
        }
    }
    ids.conectar(alunoAtual, id);
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
    mostrarPerfil(); 
    cout << "Escolha o dado que deseja atualizar:" << endl << endl;
    cout << "(1) Nome "  << endl;
    cout << "(2) Usuario "  << endl;
    cout << "(3) Senha" << endl; 
    cout << "(4) Voltar" << endl; 
    opcao = getInt(); 
    if(opcao == 1) {
        cout << "Nome: ";
        string nome = getString();
        alunos[alunoAtual].setNome(nome);
    } else if(opcao == 2) {
        cout << "Usuario: ";
        string usuario = getString();
        alunos[alunoAtual].setUsuario(usuario);
    } else if(opcao == 3) {
        cout << "Senha: ";
        string senha = getString();
        alunos[alunoAtual].setSenha(senha);
    }
}

void InterfacePrincipal::mostrarPerfil(){
    alunos[alunoAtual].imprimeDados(); 
}