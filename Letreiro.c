#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



// -------- Defines 120----------
#define TAM_TELA 120
#define TEMPO 500000
#define QTDVEZESREODAR 10
// ---------------- Protótipos -------------------
void printaVet(char array[],int tamVet);
void inicializaTela(char array[], int tam);
void movimentaTextoProLado(char tela[], int tamTela,int tamVet);
void guardaNaTelaDeTrasPraFrente(char tela[], char texto[], int tamTela, int tamTexto);
void guardaNaTelaDeFrenteParaTras(char tela[], char texto[]);
void movimentaTextoParaTras(char tela[], int tamTela);
void imprimeUmaVezMovendo(char tela[],int tamTela,int tamTexto, int temEspera);
//------------------------------------------------
/*
	1- Criar um array para ser a minha tela
	2- Guardar o texto desejado na tela
	3- Printo cada posicao do texto desejado
	4- Rodar até a ultima posicao da tela
	5- Rodar mais de uma vez o passo 4



*/
int main(int argc, char *argv[]) {
	int tamTexto,para = 0;
	char tela[TAM_TELA];
	
	//Se um dia eu quiser perguntar para o usuário 
	char vet[] = "Rebeca Divina Paula Carvalhedo";
	tamTexto = sizeof(vet);
	
	//Mover várias vezes o Letreiro
	do{
		inicializaTela(tela,TAM_TELA); 
		guardaNaTelaDeFrenteParaTras(tela,vet);						
		imprimeUmaVezMovendo(tela,TAM_TELA,tamTexto,TEMPO);
		system("cls");
		para++;
	}while(para <= QTDVEZESREODAR);


	return 0;
}
void imprimeUmaVezMovendo(char tela[],int tamTela,int tamTexto, int temEspera){
	
	int contador = 0,i;
	do{
		printaVet(tela,tamTela);
		movimentaTextoProLado(tela,tamTela,tamTexto);
		system("cls");
		//Da um tempo
		for (i = 0; i < temEspera; i++);			
		contador++;
	}while(contador < tamTela+1);
}

void movimentaTextoParaTras(char tela[], int tamTela){

	int i, j;
	char caracterAnterior,caracterPosTerior,caracter;

	for(i = 0; i < tamTela; i++){
		if(tela[i] != ' ')
			break;
	}	


	caracterPosTerior = tela[i+1];
	caracter = tela[i];
	
	tela[i-1] = caracter;	
	tela[i] = caracterPosTerior;
	tela[i+1] = ' ';
	
	
	
}

void guardaNaTelaDeTrasPraFrente(char tela[], char texto[], int tamTela, int tamTexto){						
	int i,j = tamTexto-1;
	for(i = tamTela; i >= 0 ; i--){

		if(j >= 0){
			tela[i] = texto[j];
			j--;
		}else{
			tela[i] = ' ';	
		}
	}	
}
void guardaNaTelaDeFrenteParaTras(char tela[], char texto[]){						
	strcpy(tela, texto);	
}
void movimentaTextoProLado(char tela[], int tamTela, int tamVet){

	int i = tamVet, j;
	char caracter;

	for(j = tamTela; (j >= 0); j--){
		caracter = tela[j];
		tela[j+1] = caracter;	
		tela[j] = ' ';
	}	
	
}
void inicializaTela(char array[], int tam){
	int i;
	for(i = 0;i < tam; i++){
		array[i] = ' ';
	}
}

void printaVet(char array[],int tamVet){
	int i;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for(i = 0;i < tamVet; i++){
		printf("%c", array[i]);
	}
}

