#include <iostream>
#include <locale>
#include <cstdlib>
#include <fstream>
#include "funcoes_candidato.h"
#include "funcoes_eleitores.h"
#include "estrutura_fila.h"
#include "funcoes_voto.h"
using namespace std;


string relatorios = "Relatorios.txt";
Candidato *listacandidatos = NULL;
Eleitor *listaeleitores = NULL;
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
					cadastrarCandidato(listacandidatos);
					liberarMemoriaC(listacandidatos);
					cout << endl;
					cout << "--------------------------------------\n";
					break;
			
					case 2:
						cout << "----------Mostrar Candidatos----------\n";
						carregarCandidatos(listacandidatos);
						listarCandidatos(listacandidatos);
						liberarMemoriaC(listacandidatos);
						cout << "--------------------------------------\n";
					break;

					case 3:
						cout << "----------Deletando Candidatos----------\n";
						removeCandidato(listacandidatos);
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
					cadastraEleitor(listaeleitores);
					liberarMemoriaE(listaeleitores);
					cout << endl;
					cout << "--------------------------------------\n";	
					break;
			
					case 2:
					cout << "----------Mostrar Eleitores------------\n";
					carregarEleitores(listaeleitores);
					listarEleitores(listaeleitores);
					liberarMemoriaE(listaeleitores);
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
					carregarEleitores(listaeleitores);
					carregarCandidatos(listacandidatos);
					insereFila(fila, listaeleitores);
					cout << "---------------------------------------\n";
					cout << "----------------Votação----------------\n";
					votar(fila, listavotos, listacandidatos);
					liberarMemoriaE(listaeleitores);
					liberarMemoriaC(listacandidatos);
					cout << "---------------------------------------\n";
					break;
			
					case 2:
					cout << "---------------Resultado---------------\n";
					cout << endl;
					excluirArquivo(relatorios);
					carregarCandidatos(listacandidatos);
            		carregarEleitores(listaeleitores);
            		relatorioQtdVotosCandidato(listavotos,listacandidatos);
            		liberarMemoriaC(listacandidatos);
            		liberarMemoriaE(listaeleitores);
            		liberarMemoriaV(listavotos);
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
