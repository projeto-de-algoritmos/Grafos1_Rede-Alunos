#include "grupo.hpp"

Grupo::Grupo(int id, string nome, string descricao){
     this->id = id;
     this->nome = nome;
     this->descricao = descricao;
}

int Grupo::getId(){
    return id; 
} 

string Grupo::getNome(){
    return nome; 
}

void Grupo::setNome(string nome){
    this->nome = nome; 
}

string Grupo::getDescricao(){
    return descricao;  
}

void Grupo::setDescricao(string descricao){
    this->descricao = descricao; 
}

vector<int>Grupo::getMembros(){
    return membros; 
} 

void Grupo::addMembro(int idAluno){
    membros.push_back(idAluno); 
}

void Grupo::mostrarDados(){
    cout << "Nome do Grupo: " <<  nome << endl; 
    cout << "Descricao: " << descricao << endl;
    cout << "Membros: ";
}
        