#include "interfacePrincipal.hpp"
#include "Aluno.hpp"

#include <iostream>
#include <algorithm>

using namespace std;

InterfacePrincipal::InterfacePrincipal() {
    menuLogin();
}

template <typename T>
T getInput(string mensagem) {
    T entrada;
    bool loop = true;
    while(loop) {
        cout << mensagem;
        loop = false;
        cin >> entrada;
        if(cin.fail()) {
            cin.clear();
            cout << "Entrada inválida." << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return entrada;
}


void InterfacePrincipal::menuLogin() {
    while(true) {
        cout << "(1) Criar conta" << endl;
        cout << "(2) Fazer login" << endl;
        cout << "(3) Opções avançadas" << endl;
        cout << "(0) Sair" << endl;
        int opcao = getInput<int>("");
        if(opcao == 1)
            menuCriarConta();
        else if(opcao == 2)
            menuFazerLogin();
        else if(opcao == 3)
            menuAvancado();
        else
            break;
    }
}

void InterfacePrincipal::menuAvancado() {
    while(true) {
        cout << "(1) Modo administrador" << endl;
        cout << "(2) Estatísticas" << endl;
        cout << "(0) Voltar" << endl;
        int opcao = getInput<int>("");
        if(opcao == 1)
            menuAdmin();
        else if(opcao == 2)
            menuEstatisticas();
        else
            break;
    }
}

void InterfacePrincipal::menuAdmin() {

}

void InterfacePrincipal::menuEstatisticas() {
    cout << ids.getTamanho() << " usuários estão cadastrados." << endl;
    int qtdDesconectados = ids.getQtdDesconectados();
    cout << ids.getTamanho() - qtdDesconectados << " usuários estão conectados." << endl;
    cout << ids.getQtdDesconectados() << " usuários não estão conectados." << endl;
    cout << ids.getCiclos().size() <<" ciclos foram formados" << endl;
}

void InterfacePrincipal::menuCriarConta() {
    bool validacao; 
    while(true){  
        cout << "Criação de Conta" << endl << endl; 
        int matricula = getInput<int>("Matrícula: ");
        string nome = getInput<string>("Nome completo: ");
        string usuario = getInput<string>("Nome de usuário: ");
        string senha = getInput<string>("Senha: ");
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
            cout << "Conta já cadastrada!" << endl;
            cout << "(1) Fazer Login " << endl;
            cout << "(2) Novo cadastro" << endl;
            int opcao = getInput<int>(""); 
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
    bool loop = true;
    while(loop) {
        string usuario = getInput<string>("Nome de usuário: ");
        string senha = getInput<string>("Senha: ");
        loop = verificaCredenciais(usuario, senha);
        if(loop == true){
            cout << "Credenciais incorretas." << endl;
            cout << "(1)Tentar novamente" << endl;
            cout << "(2)Cadastre-se" << endl;
            int opcao = getInput<int>(""); 
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
        cout << "(1) Amigos" << endl;
        cout << "(2) Grupos de estudo" << endl;
        cout << "(3) Gerenciar perfil" << endl;
        cout << "(4) Visualizar grafo" << endl;
        cout << "(0) Sair da conta" << endl;
        int opcao = getInput<int>("");
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
    cout << "(1) Meus amigos" << endl;
    cout << "(2) Adicionar amigo" << endl;
    cout << "(3) Remover amigo" << endl;
    cout << "(4) Amigos sugeridos" << endl;
    cout << "(0) Voltar" << endl;
    int opcao = getInput<int>("");
    if(opcao == 1)
        mostrarAmigos(); 
    else if(opcao == 2)
        adicionarAmigo();
    else if(opcao == 3)
        removerAmigo();
    else if(opcao == 4)
        sugerirAmigos();
}

void InterfacePrincipal::sugerirAmigos() {
    vector <int> amigosRecomendados = ids.bfs(alunoAtual); 
    vector <int> pesos = ids.GrauConectividade(alunoAtual);
    for(int i : amigosRecomendados){
        cout << alunos[i].getUsuario() << "  "<< pesos[i] <<"Amigos em Comum" << endl;
    }
}

void InterfacePrincipal::removerAmigo() {
    string usuario = getInput<string>("Nome de usuário: ");
    for(int id: ids.getListaAdjacencia(alunoAtual)) {
        if(usuario == alunos[id].getNome()) {
            ids.desconectar(alunoAtual, id);
            break;
        }
    }
}

void InterfacePrincipal::mostrarAmigos() {
    cout << "Numero de amigos: " << ids.getListaAdjacencia(alunoAtual).size()<< endl;
    vector <string> nomesAmigos;
    for (int i: ids.getListaAdjacencia(alunoAtual)){
        nomesAmigos.push_back(alunos[i].getNome());
    }
    sort(nomesAmigos.begin(), nomesAmigos.end(), [](string a, string b) {return (a < b); }); 
    for(string j: nomesAmigos)
        cout << j << endl; 
}

void InterfacePrincipal::adicionarAmigo() {
    int id = -1;
    string usuarioAluno = getInput<string>("Usuário do aluno: ");
    for(Aluno i: alunos){
        if(i.getUsuario() == usuarioAluno){
            id = i.getId();
            break;   
        }
    }
    if(validacaoAmizade(alunoAtual, id))
        ids.conectar(alunoAtual, id); 
}

bool InterfacePrincipal::validacaoAmizade(int id1, int id2){
    if(id2 == -1){
        cout << "Usuario não encontrado" << endl; 
        return false; 
    }
    else if(id1 == id2)
        return false; 
    for(int i: ids.getListaAdjacencia(id1)){
        if(i == id2)
            return false;
    }
    return true; 
} 

void InterfacePrincipal::menuGrupos() {
    cout << "(1) Meus grupos" << endl;
    cout << "(2) Criar grupo" << endl; 
    cout << "(0) Voltar" << endl; 
    int opcao = getInput<int>(""); 
}

void InterfacePrincipal::menuConfiguracao() {
    cout << "(1) Atualizar dados" << endl;
    cout << "(2) Excluir conta" << endl;  
    cout << "(0) Voltar" << endl; 
    int opcao = getInput<int>(""); 

    if(opcao == 1){
        menuAtualizacao(); 
    }
    else if(opcao == 2){

    }
    else{

    }
}

void InterfacePrincipal::menuAtualizacao(){ 
    mostrarPerfil(); 
    cout << "Escolha o dado que deseja atualizar:" << endl << endl;
    cout << "(1) Nome "  << endl;
    cout << "(2) Usuario "  << endl;
    cout << "(3) Senha" << endl; 
    cout << "(4) Matrícula" << endl;
    cout << "(0) Voltar" << endl; 
    int opcao = getInput<int>(""); 
    if(opcao == 1) {
        string nome = getInput<string>("Nome: ");
        alunos[alunoAtual].setNome(nome);
    } else if(opcao == 2) {
        string usuario = getInput<string>("Usuário: ");
        alunos[alunoAtual].setUsuario(usuario);
    } else if(opcao == 3) {
        string senha = getInput<string>("Senha: ");
        alunos[alunoAtual].setSenha(senha);
    } else if(opcao == 4) {
        int matricula = getInput<int>("Matrícula: ");
        alunos[alunoAtual].setMatricula(matricula);
    }
}

void InterfacePrincipal::mostrarPerfil(){
    alunos[alunoAtual].imprimeDados(); 
}