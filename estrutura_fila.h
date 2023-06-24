#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

class FilaEleitor {
private:
    Eleitor* primeiro;
    Eleitor* ultimo;

public:
    FilaEleitor() {
        primeiro = NULL;
        ultimo = NULL;
    }

    bool estaVazia() {
        return primeiro == NULL;
    }

    void enfileirar(int titulo, const string &nome) {
        Eleitor* novoEleitor = new Eleitor;
        novoEleitor->titulo = titulo;
        novoEleitor->nome = nome;
        novoEleitor->proximo = NULL;

        if (estaVazia()) {
            primeiro = novoEleitor;
            ultimo = novoEleitor;
        } else {
            ultimo->proximo = novoEleitor;
            ultimo = novoEleitor;
        }
    }

    void desenfileirar() {
        if (estaVazia()) {
            cout << "fila vazia." << endl;
            return;
        }

        Eleitor* eleitorRemovido = primeiro;
        primeiro = primeiro->proximo;

        if (primeiro == NULL) {
            ultimo = NULL;
        }
        delete eleitorRemovido;
    }

    void exibirFila() {
        if (estaVazia()) {
            cout << "fila vazia" << endl;
            return;
        }

        Eleitor* atual = primeiro;
        cout << "Fila de eleitores:" << endl;
        while (atual != NULL) {
            cout << "Título: " << atual->titulo << ", Nome: " << atual->nome << endl;
            atual = atual->proximo;
        }
    }
    
	int votar() {
    if (estaVazia()) {
        cout << "fila vazia" << endl;
        return -1;
    }
    
    Eleitor* atual = primeiro;
    while (atual != NULL) {
        return atual->titulo;
        atual = atual->proximo;
    }

    return -1;
}
    ~FilaEleitor() {
    Eleitor* atual = primeiro;
    while (atual != NULL) {
        Eleitor* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}
};
