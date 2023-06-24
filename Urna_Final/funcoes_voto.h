#include <iostream>
#include <locale>
#include <fstream>
using namespace std;


struct Voto{
int titulo;
string nome;
Voto *proximo;
};


void salvar_relatorio(string nome, int qtd){
    ofstream arquivo("Relatorios.txt", ios::app);
    if (arquivo.is_open()) {
        arquivo << "Relatório de Votos por candidatos: " << endl;
        arquivo << "Nome: " << nome << ", " <<"Quantidade de votos: "<< qtd << endl;
        arquivo.close();
    } else {
        cout << "Erro" << endl;
    }
}



void insereFila(FilaEleitor*& fila, Eleitor *lista){
	int titulo;
	cout << "Insira o número de seu título de eleitor: ";
	cin >> titulo;
	
	if(pode_votar(titulo, lista)){
		Eleitor *eleitorAtual = lista;
		while(eleitorAtual != NULL){
			if(eleitorAtual->titulo == titulo){
				fila->enfileirar(titulo, eleitorAtual->nome);
				fila->exibirFila();
			}
			eleitorAtual = eleitorAtual->proximo;
		}
	}
	else{
		cout << "Não e apto a votar" << endl;
	}
	
}
void inserirVoto(Voto*& lista, const std::string& nome, int numero){
	Voto *novoVoto = new Voto;
    novoVoto->nome = nome;
    novoVoto->titulo = numero;
    novoVoto->proximo = NULL;

    if (lista == NULL) {
        lista = novoVoto;
        
    } 
	else {
        Voto* ultimo = lista;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novoVoto;
        
    }
}
string procurar_candidato(int num, Candidato *lista){
	Candidato *atual = lista;
	while(atual != NULL){
		if(num == atual->numero){
			string nome = atual->nome;
			return nome;
		}
		atual = atual->proximo;
	}
	return "";
}

void votar(FilaEleitor*& fila,Voto*& votos,Candidato*& candidatos){
	int num;
	if(fila->estaVazia()){
		cout << "Fila de eleitores vazia" << endl;
		
	}else{
		int titulo = fila->votar();
		Candidato *atual = candidatos;
		listarCandidatos(candidatos);
		
		cout << "Digite o número do candidato que deseja votar: ";
		cin >> num;
		string nome = procurar_candidato(num, candidatos);
		if(nome != ""){
                
		inserirVoto(votos,nome,num );
		cout << "Voto realizado" << endl;
        }else{
              cout << "Erro" << endl;
              } 
		
		fila->desenfileirar();
	}
}
void quantidade_votos(Voto*& votos, Candidato*& lista) {
    Candidato* candidatoAtual = lista;
    Voto* votoAtual = votos;

    if (votos == NULL) {
        cout << "Não a votos" << endl;
    } else {
        while (votoAtual != NULL) {
            cout << votoAtual->titulo << endl;
            votoAtual = votoAtual->proximo;
        }

        while (candidatoAtual != NULL) {
            int qtd = 0;
            votoAtual = votos;

            while (votoAtual != NULL) {
                if (candidatoAtual->nome == votoAtual->nome) {
                    qtd++;
                }
                votoAtual = votoAtual->proximo;
            }

            salvar_relatorio(candidatoAtual->nome, qtd);
            cout << "A quantidade de votos do candidato " << candidatoAtual->nome << " é: " << qtd << " votos" << endl;

            candidatoAtual = candidatoAtual->proximo;
        }

    }
}

void free_voto(Voto *&lista){

    Voto *votoAtual = NULL;
    if(lista == NULL){
        cout << "Lista está vazia";

    }
	else{
        votoAtual = lista;
        while(votoAtual != NULL){
            Voto *prox = votoAtual->proximo;
            delete votoAtual;
            votoAtual = prox;
        }
        lista = NULL;
    }
}

void excluirArquivo(const std::string& nomeArquivo) {
    if (std::remove(nomeArquivo.c_str()) == 0) {
    } 
	else {
        std::cout << "Erro ao excluir o arquivo." << std::endl;
    }
}

