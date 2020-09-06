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
        cout << "(0) Voltar" << endl;
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
    while(true) {
        cout << "(1) Conectar usuários" << endl;
        cout << "(2) Desconectar Usuários" << endl;
        int opcao = getInput<int>("");
        if(opcao == 1)
            menuAmigosAdmin(true);
        else if(opcao == 2)
            menuAmigosAdmin(false);
        else 
            break;  
    }
}

void InterfacePrincipal::menuAmigosAdmin(bool adicionar) {
    cout << "(1) Por nome de usuário" << endl;
    cout << "(2) Por ID" << endl;
    cout << "(0) Voltar" << endl;
    int opcao = getInput<int>("");
    if(opcao == 1) {
        string usuario1 = getInput<string>("Usuário 1: ");
        string usuario2 = getInput<string>("Usuário 2: ");
        if(validacaoUsuario(usuario1) && validacaoUsuario(usuario2)){
            vector <int> idUsuarios = procuraIds(usuario1, usuario2);
            if(adicionar)
                ids.conectar(idUsuarios[0], idUsuarios[1]);
            else
                ids.desconectar(idUsuarios[0], idUsuarios[1]);
        }
    } else if(opcao == 2) {
        int id1 = getInput<int>("ID 1: ");
        int id2 = getInput<int>("ID 2: ");
            if(adicionar && validacaoAmizade(id1,id2))
                ids.conectar(id1, id2);
            else
                ids.desconectar(id1, id2);
    }
}

bool InterfacePrincipal::validacaoUsuario(string usuario){
    for(Aluno a: alunos){
        if(a.getUsuario() == usuario)
            return true; 
    }
    return false; 

}

vector <int> InterfacePrincipal::procuraIds(string usuario1, string usuario2) {
    vector <int> idUsuarios(2, -1);
    for(Aluno a: alunos) {
        if(a.getUsuario() == usuario1)
            idUsuarios[0] = a.getId();
        if(a.getUsuario() == usuario2)
            idUsuarios[1] = a.getId();
        if(idUsuarios[0] != -1 && idUsuarios[1] != -1)
            break;
    }
    return idUsuarios;
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
    for(Aluno a: alunos){
        if(a.getMatricula() == aluno.getMatricula() || a.getUsuario() == aluno.getUsuario())
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
            case 0:
                return; 
        }
    }
}

void InterfacePrincipal::menuAmigos() {
    while(true){
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
        else 
            return; 
    }
}

void InterfacePrincipal::sugerirAmigos() {
    vector <int> amigosRecomendados = ids.bfs(alunoAtual); 
    vector <int> pesos = ids.GrauConectividade(alunoAtual);
    for(int i : amigosRecomendados){
        cout << alunos[i].getUsuario() << "  "<< pesos[i] <<" amigos em comum" << endl;
    }
}

void InterfacePrincipal::removerAmigo() {
    string usuario = getInput<string>("Nome de usuário: ");
    for(int id: ids.getListaAdjacencia(alunoAtual)) {
        if(usuario == alunos[id].getUsuario()) {
            ids.desconectar(alunoAtual, id);
            break;
        }
    }
}

void InterfacePrincipal::mostrarAmigos() {
    cout << "Numero de amigos: " << ids.getListaAdjacencia(alunoAtual).size()<< endl;
    vector <string> nomesAmigos;
    for (int i: ids.getListaAdjacencia(alunoAtual)){
        nomesAmigos.push_back(alunos[i].getUsuario());
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
    if(id2 == -1 || id1 > ids.getTamanho() || id2 > ids.getTamanho()){
        cout << "Falhou!" << endl; 
        return false; 
    }
    else if(id1 == id2)
        return false; 

    for(int i: ids.getListaAdjacencia(id1)){
        if(i == id2)
            return false;
    }
    cout << "Amizade formada" << endl; 
    return true; 
} 

void InterfacePrincipal::menuGrupos() {
    while(true){
        cout << "(1) Meus grupos" << endl;
        cout << "(2) Criar grupo" << endl;
        cout << "(3) Entrar em um grupo" << endl;  
        cout << "(0) Voltar" << endl; 
        int opcao = getInput<int>(""); 
        if(opcao == 1)
            mostrarGrupos(); 
        else if(opcao == 2)
            menuCriarGrupo(); 
        else if(opcao == 3){

        }
        else
            break; 
    }

}

void InterfacePrincipal::mostrarGrupos(){
    vector <int> idsGrupos = alunos[alunoAtual].getGrupos();
    for(int i:idsGrupos)
        grupos[i].mostrarDados();         
}

void InterfacePrincipal::menuCriarGrupo(){
    string nome; 
    do {
    nome = getInput <string> ("Nome do Grupo: ");
    } while(!validacaoGrupo(nome)); 
    string descricao = getInput <string> ("Descricao do Grupo: ");
    int id = grupos.size(); 
    grupos.push_back(Grupo(id, nome, descricao));  
    alunos[alunoAtual].addGrupo(id);
}

bool InterfacePrincipal::validacaoGrupo(string nome){
    for(Grupo g: grupos){
        if(g.getNome() == nome)
            return false; 
    }
        return true; 
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