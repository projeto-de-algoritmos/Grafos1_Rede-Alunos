#include "Aluno.hpp"

#include <iostream>

using namespace std; 

Aluno::Aluno(int id, int matricula, string nome, string usuario, string senha) {
    this->id = id;
    this->matricula = matricula;
    this->nome = nome;
    this->usuario = usuario;
    this->senha = senha;
}

int Aluno::getMatricula() {
    return matricula;
}

void Aluno::setMatricula(int matricula) {
    this->matricula = matricula;
}

string Aluno::getNome() {
    return nome;
}

void Aluno::setNome(string nome) {
    this->nome = nome;
}

string Aluno::getUsuario() {
    return usuario;
}

void Aluno::setUsuario(string usuario) {
    this->usuario = usuario;
}

string Aluno::getSenha() {
    return senha;
}

void Aluno::setSenha(string senha) {
    this->senha = senha;
}

int Aluno::getId() {
    return id;
}

void Aluno::imprimeDados() {
    cout << "Nome: " << getNome() << endl;
    cout << "Usuario: " << getUsuario() << endl;
    cout << "Matricula: " << getMatricula() << endl << endl;
    
}

bool Aluno::verificaSenha(string senha) {
    if(this->senha == senha)
        return true;
    else
        return false;
}

bool Aluno::verificaUsuario(string usuario) {
    if(this->usuario == usuario)
        return true;
    else
        return false;
}

