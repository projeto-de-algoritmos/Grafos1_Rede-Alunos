#include "Aluno.hpp"

#include <iostream>

Aluno::Aluno(int matricula, string nome, string usuario, string senha) {
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