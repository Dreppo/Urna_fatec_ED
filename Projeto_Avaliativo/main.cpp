#include <iostream>
#include <locale>
#include <cstdlib>
#include <fstream>
#include "funcoes_candidato.h"
#include "funcoes_eleitores.h"
#include "estrutura_fila.h"
#include "funcoes_voto.h"
using namespace std;


Candidato *lista_candidatos= NULL;
Eleitor *lista_eleitores = NULL;
Voto *listavotos = NULL;
FilaEleitor *fila = new FilaEleitor();
	


int main(){
	setlocale(LC_ALL,"Portuguese"); 
	int escolha, escolha_candidatos, escolha_eleitores, escolha_votacao;
	
	cout << "----------Urna Eletronica----------\n";
	cout << "-----------------------------------\n";
	cout << "-----------------------------------\n";
	

	while(escolha != 4){
		
		cout << endl << endl;
		cout << "1- Candidatos" << endl;
		cout << "2- Eleitores" << endl;
		cout << "3- Votação" << endl;
		cout << "4- sair" << endl;
		cin >> escolha;
		switch(escolha){
			
			case 1:
			int escolha_candidatos;
			while(escolha_candidatos != 4){
		
				cout << endl << endl;
				cout << "1- Inserir Candidatos" << endl;
				cout << "2- Mostrar Candidatos" << endl;
				cout << "3- Deletar Candidatos" << endl;
				cout << "4- Voltar" << endl;
				cin >> escolha_candidatos;
		
				switch(escolha_candidatos){
		
					case 1:	
					cout << "----------Cadastro Candidato----------\n";
					cout << endl;
					cadastrarCandidato(lista_candidatos);
					free_candidato(lista_candidatos);
					cout << endl;
					cout << "--------------------------------------\n";
					break;
			
					case 2:
						cout << "----------Mostrar Candidatos----------\n";
						carregarCandidatos(lista_candidatos);
						listarCandidatos(lista_candidatos);
						free_candidato(lista_candidatos);
						cout << "--------------------------------------\n";
					break;

					case 3:
						cout << "----------Deletando Candidatos----------\n";
						removeCandidato(lista_candidatos);
						cout << "----------------------------------------\n";
					break;
			
					case 4:
						cout << "Encerrando";
					break;
			
				}		
			
			};
			break;
			
			case 2:
			int escolha_eleitores;
			while(escolha_eleitores != 3){
		
				cout << endl << endl;
				cout << "1- Inserir Eleitores" << endl;
				cout << "2- Mostrar Eleitores" << endl;
				cout << "3- voltar" << endl;
				cin >> escolha_eleitores;
		
				switch(escolha_eleitores){
		
					case 1:
					cout << "----------Cadastro Eleitor------------\n";
					cout << endl;
					cadastraEleitor(lista_eleitores);
					free_eleitor(lista_eleitores);
					cout << endl;
					cout << "--------------------------------------\n";	
					break;
			
					case 2:
					cout << "----------Mostrar Eleitores------------\n";
					carregarEleitores(lista_eleitores);
					listarEleitores(lista_eleitores);
					free_eleitor(lista_eleitores);
					cout << "---------------------------------------\n";	
					break;

					case 3:	
					break;
			
				}		
			
			};	
			break;

			case 3:
			int escolha_votacao;
			while(escolha_votacao != 3){
		
				cout << endl << endl;
				cout << "1- Votar" << endl;
				cout << "2- Mostrar Resultado" << endl;
				cout << "3- voltar" << endl;
				cin >> escolha_votacao;
		
				switch(escolha_votacao){
		
					case 1:	
					cout << "Entrando na fila para votar \n";
					carregarEleitores(lista_eleitores);
					carregarCandidatos(lista_candidatos);
					insereFila(fila, lista_eleitores);
					cout << "---------------------------------------\n";
					cout << "----------------Votação----------------\n";
					votar(fila, listavotos, lista_candidatos);
					free_eleitor(lista_eleitores);
					free_candidato(lista_candidatos);
					cout << "---------------------------------------\n";
					break;
			
					case 2:
					cout << "---------------Resultado---------------\n";
					cout << endl;
					carregarCandidatos(lista_candidatos);
            		carregarEleitores(lista_eleitores);
            		relatorioQtdVotosCandidato(listavotos,lista_candidatos);
            		free_candidato(lista_candidatos);
            		free_eleitor(lista_eleitores);
            		free_voto(listavotos);
					cout << endl;
					cout << "---------------------------------------\n";
					delete fila;
					break;
					
					case 3:
					break;
			
				}		
			
			};		
			break;
			
			case 4:
			break;
			
		}		
			
	};
	return 0;
}
