#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

struct Eleitor {
int titulo;
string nome;
Eleitor* proximo;
};

void salva_eleitor_txt(Eleitor *eleitor){
	ofstream arquivo("Eleitores.txt", ios::app);
    if (arquivo.is_open()) {
        arquivo << eleitor->nome << ", " << eleitor->titulo << endl;
        arquivo.close();
        cout << "salvo" << endl;
    } else {
        cout << "Erro" << endl;
    }
}
void inserirEleitor(Eleitor*& lista, const std::string& nome, int numero){
	Eleitor* novoEleitor = new Eleitor;
    novoEleitor->nome = nome;
    novoEleitor->titulo = numero;
    novoEleitor->proximo = NULL;

    if (lista == NULL) {
        lista = novoEleitor;
        salva_eleitor_txt(novoEleitor);
    } else {
        Eleitor* ultimo = lista;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novoEleitor;
        salva_eleitor_txt(novoEleitor);
    }
}
void cadastraEleitor(Eleitor *lista){
	string nome;
	int num;
	cout << "Nome: ";
	cin >> nome;
	cout << "Número do titulo de eleitor: ";
	cin >> num;
	inserirEleitor(lista, nome, num);
}
void carregarEleitores(Eleitor *&lista) {
    ifstream arquivo("Eleitores.txt");
    if (arquivo.is_open()) {
        string nome;
        int numero;
        while (arquivo >> nome >> numero) {
            Eleitor* novoEleitor = new Eleitor;
            novoEleitor->nome = nome;
            novoEleitor->titulo = numero;
            novoEleitor->proximo = NULL;

            if (lista == NULL) {
                lista = novoEleitor;
            } else {
                Eleitor* atual = lista;
                while (atual->proximo != NULL) {
                    atual = atual->proximo;
                }
                atual->proximo = novoEleitor;
            }
        }
        arquivo.close();
    } else {
        cout << "Erro" << endl;
    }
    
    
}
bool verificaElegibilidade(int titulo, Eleitor* lista) {
    Eleitor* eleitorAtual = lista;
    bool boolean = false;
    
    if (lista == NULL) {
        cout << "Lista vazia" << endl;
        return false;
    } else {
        while (eleitorAtual != NULL) {
            if (eleitorAtual->titulo == titulo) {
                boolean = true;
                break;
            }
            eleitorAtual = eleitorAtual->proximo;
        }
        return boolean;
    }
}
void liberarMemoriaE(Eleitor *&lista){
	Eleitor *eleitorAtual = NULL;
	if(lista == NULL){
		cout << "vazia";
	}
	else{
		eleitorAtual = lista;
		while(eleitorAtual != NULL){
			Eleitor *prox = eleitorAtual->proximo;
			delete eleitorAtual;
			eleitorAtual = prox;
		}
		lista = NULL;
	}
}
void listarEleitores(const Eleitor* lista) {
    if (lista == NULL) {
        cout << "Nenhum candidato cadastrado." << endl;
        return;
    }
    
    const Eleitor* eleitorAtual = lista;
    while (eleitorAtual != NULL) {
        cout << "Nome: " << eleitorAtual->nome << " Número: " << eleitorAtual->titulo << endl;
        eleitorAtual = eleitorAtual->proximo;
    }
}
