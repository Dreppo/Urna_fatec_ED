#include <iostream>
#include <locale>
#include <fstream>
using namespace std;



void salvarRelatorioCEmArquivo(string nome, int qtd){
    ofstream arquivo("Relatorios.txt", ios::app);
    if (arquivo.is_open()) {
        arquivo << "Relat�rio de Votos por candidatos: " << endl;
        arquivo << "Nome: " << nome << ", " <<"Quantidade de votos: "<< qtd << endl;
        arquivo.close();
    } else {
        cout << "N�o foi poss�vel abrir o arquivo Relatorios.txt" << endl;
    }
}



void insereFila(FilaEleitor*& fila, Eleitor *lista){
	int titulo;
	cout << "Insira o n�mero de seu t�tulo de eleitor: ";
	cin >> titulo;
	
	if(verificaElegibilidade(titulo, lista)){
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
		cout << "N�o e apto a votar" << endl;
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
string pesquisaNomeCandidato(int num, Candidato *lista){
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
		
		cout << "Digite o n�mero do candidato que deseja votar: ";
		cin >> num;
		string nome = pesquisaNomeCandidato(num, candidatos);
		if(nome != ""){
                
		inserirVoto(votos,nome,num );
		cout << "Voto realizado" << endl;
        }else{
              cout << "Erro" << endl;
              } 
		
		fila->desenfileirar();
	}
}
void relatorioQtdVotosCandidato(Voto*& votos, Candidato*& lista) {
    Candidato* candidatoAtual = lista;
    Voto* votoAtual = votos;

    if (votos == NULL) {
        cout << "As elei��es ainda n�o foram realizadas!" << endl;
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

            salvarRelatorioCEmArquivo(candidatoAtual->nome, qtd);
            cout << "A quantidade de votos do candidato " << candidatoAtual->nome << " �: " << qtd << " votos" << endl;

            candidatoAtual = candidatoAtual->proximo;
        }

    }
}

void liberarMemoriaV(Voto *&lista){

    Voto *votoAtual = NULL;
    if(lista == NULL){
        cout << "Lista est� vazia";

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

