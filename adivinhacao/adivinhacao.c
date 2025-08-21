#include <stdio.h> // deritiva
#include <stdlib.h>
#include <time.h>

int main() {
	// imprime o cabeçalho
	printf("\n");
	printf("**************************************\n");
	printf("Bem vindo ao nosso jogo de adivinhação\n");
	printf("**************************************\n");
	printf("\n");

	int segundos = time(0);
	srand(segundos);
	int numerosecreto = rand() % 100;
	int chute;
	int contador = 1;
	double total_pontos = 1000;
	double pontos_perdidos = 0;
	
	int dificuldade;
	printf("Em qual nível de dificuldade desejas jogar?\n");
	printf("(1) - Fácil, (2) - Médio, (3) - Difícil\n\n");
	printf("Escolha: ");
	scanf("%d", &dificuldade);

	int maximo_tentativas;
	switch(dificuldade) {
		case 1: // se dificuldade == 1
			maximo_tentativas = 21;
			break;
		case 2: // se dificuldade == 2
			maximo_tentativas = 11;
			break;
		case 3: // se dificuldade == 3
			maximo_tentativas = 7;
			break;
		desfault:
			printf("Por favor, insira um numero válido"); // tratando erros 
			break;
	}

	for(int i = 1; i <= maximo_tentativas; i++) { // variavel, condicao, incremento
		while(5) {
			printf("\n");
			printf("Tentativa n°%d:\n", contador);
			printf("Qual é o seu chute? ");
			scanf("%d", &chute);
			printf("\n");
			
			contador ++;

			if(chute<0) {
				printf("Digite apenas números positivos!\n");
			}
			else {
				break;
			}
		}
			if(chute == numerosecreto) {
				break;
			}

			else if(contador == maximo_tentativas) {
				break;
			}

			else if(chute < numerosecreto) {
				printf("Um pouco mais!\n");

				pontos_perdidos = (double)(numerosecreto - chute) / 2; // casting(conversão)
			}
			else if (chute > numerosecreto) {
				printf("Um pouco menos!\n");
				
				pontos_perdidos = (chute - numerosecreto) / (double)2;
			}

			total_pontos = total_pontos - pontos_perdidos;


}
			if(chute == numerosecreto) {
				printf("Parabens, você venceu!\n");
				printf("Você precisou de %d tentativas para me vencer!\n", contador);
			}
			else if(dificuldade != 1 && dificuldade != 2 && dificuldade != 3) {
				printf("Por favor, insira uma dificuldade válida!\n");
			}
			else {
				printf("Você perdeu! Tente novamente.\n");
			}
}
