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
    for(int i: membros) {
        if(idAluno == i)
            return;
    }
    membros.push_back(idAluno); 
}

void Grupo::removeMembro(int idAluno){
    int tamanho = membros.size(); 
    for(int i = 0; i < tamanho; i++){
        if(membros[i] == idAluno){
                membros.erase(membros.begin() + i); 
                break; 
        }
    }
}

void Grupo::mostrarDados(){
    cout << "Nome do Grupo: " <<  nome << endl; 
    cout << "Descricao: " << descricao << endl;
    cout << "Membros: " << membros.size() << endl;
}
        