#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

struct Candidato{
int numero;
string nome;
Candidato *proximo;
};

struct Voto{
int titulo;
string nome;
Voto *proximo;
};

void liberarMemoriaC(Candidato *&lista){
	Candidato *candidatoAtual = NULL;
	if(lista == NULL){
		cout << "Lista esta vazia";	
	}
	else{
		candidatoAtual = lista;
		while(candidatoAtual != NULL){
			Candidato *prox = candidatoAtual->proximo;
			delete candidatoAtual;
			candidatoAtual = prox;
		}
		lista = NULL;
	}
}


void salva_candidato_txt(const Candidato* candidato) {
    ofstream arquivo("Candidatos.txt", ios::app);
    if (arquivo.is_open()) {
        arquivo << candidato->nome << ", " << candidato->numero << endl;
        arquivo.close();
        cout << "salvo" << endl;
    } else {
        cout << "Erro" << endl;
    }
}
void inserirCandidato(Candidato*& lista, const std::string& nome, int numero) {
    Candidato* novoCandidato = new Candidato;
    novoCandidato->nome = nome;
    novoCandidato->numero = numero;
    novoCandidato->proximo = NULL;
    
    if (lista == NULL) {
    	lista = novoCandidato;
    	salva_candidato_txt(novoCandidato);
    } 
	else {
        Candidato* ultimo = lista;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novoCandidato;
        salva_candidato_txt(novoCandidato);
    }
}

void cadastrarCandidato(Candidato* lista){
	string nome;
	int num;
	cout << "Nome: ";
	cin >> nome;
	cout << "Número: ";
	cin >> num;
	inserirCandidato(lista, nome, num);
}

void carregarCandidatos(Candidato*& lista) {
    ifstream arquivo("Candidatos.txt");
    if (arquivo.is_open()) {
        string nome;
        int numero;
        while (arquivo >> nome >> numero) {
            Candidato* novoCandidato = new Candidato;
            novoCandidato->nome = nome;
            novoCandidato->numero = numero;
            novoCandidato->proximo = NULL;

            if (lista == NULL) {
                lista = novoCandidato;
            } else {
                Candidato* atual = lista;
                while (atual->proximo != NULL) {
                    atual = atual->proximo;
                }
                atual->proximo = novoCandidato;
            }
        }
        arquivo.close();
        cout << "Candidatos carregados" << endl;
    } else {
        cout << "Erro" << endl;
    }
}

void listarCandidatos(const Candidato* lista) {
    if (lista == NULL) {
        cout << "Nenhum candidato cadastrado." << endl;
        return;
    }
    
    const Candidato* candidatoAtual = lista;
    while (candidatoAtual != NULL) {
        cout << "Nome: " << candidatoAtual->nome << " Número: " << candidatoAtual->numero << endl;
        candidatoAtual = candidatoAtual->proximo;
    }
}

void sobrescreveArquivo(Candidato *&lista){
	ofstream arquivo("Candidatos.txt");
    if (arquivo.is_open()) {
        Candidato *atual = lista;
        while (atual != NULL) {
            arquivo << atual->nome << ", " << atual->numero << endl;
            atual = atual->proximo;
        }
        arquivo.close();
    } else {
        cout << "Erro ao sobrescrever o arquivo" << endl;
    }
}

void removeCandidato(Candidato *&lista) {
    carregarCandidatos(lista);

    if (lista == NULL) {
        cout << "Nenhum candidato cadastrado at? o momento" << endl;
    } else {
    	listarCandidatos(lista);
        int num = 0;
        cout << "Informe o número do candidato que deseja excluir: ";
        cin >> num;

        Candidato *auxiliar = NULL;
        Candidato *atual = lista;

        while (atual != NULL) {
            if (num == atual->numero) {
                if (auxiliar == NULL) {
                    lista = atual->proximo;
                } else {
                    auxiliar->proximo = atual->proximo;
                }
                delete atual;
                cout << "Candidato removido com sucesso" << endl;
                break;
            } else {
                auxiliar = atual;
                atual = atual->proximo;
            }
        }
        sobrescreveArquivo(lista);
    }
liberarMemoriaC(lista);
}
