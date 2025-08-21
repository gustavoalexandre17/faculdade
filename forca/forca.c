#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "forca.h" // header file - contem a assinatura das funcoes 
#include <stdlib.h>

char palavra[20];
char chutes[26];
int chutesdados = 0;

void introducao() {
	printf("******************\n");
	printf("*  Jogo da Forca  *\n");
	printf("******************\n");
}

void chuta() {
	char chute;
	scanf(" %c", &chute); // O espaço antes do %c permite q o scanf ignore o enter
			      
	chutes[chutesdados] = chute; // todo array é um ponteiro que aponta pra primeira posicao
	chutesdados++; // chutesdados existe para simular os indices do array chutes
}
int jachutou(char letra) {
	int achou = 0;

	for(int j = 0; j < chutesdados; j++) { // percorre todos os chutes feitos
		if(chutes[j] == letra) {
		achou = 1;
		break;
		}
	} 
	return achou;
}

int letra_existe_na_palavra(char caractere) {
	// criando um loop na palavra secreta
	for(int i = 0; i < strlen(palavra); i++) {
		if(palavra[i] == caractere) {
			return 1;
		}
	}
	return 0;
}

int enforcou() {
	int erros = 0;

	for(int i = 0; i < chutesdados; i++) {
		if(!letra_existe_na_palavra(chutes[i])) {
			erros++;
		}
	}
	return erros >= 5;
}

int acertou() {
	for(int i = 0; i < strlen(palavra); i++) {
		if(!jachutou(palavra[i])) {
			return 0;
		}
	}
	return 1;
}

void desenhaforca() {
	for(int i = 0; i < strlen(palavra); i++) {
		int achou = jachutou(palavra[i]);
		if (achou) {
			printf("%c ", palavra[i]);
		}
		else {
			printf("_ ");
		}
	}
	printf("\n");
}

void adicionapalavra() {
	
	char quer;
	printf("Desejas adicionar uma nova palavra no jogo? ");
	scanf(" %c", &quer);

	if(quer == 'S') {
		
		char novapalavra[20];
		printf("Qual a nova palavra? ");
		scanf("%s", &novapalavra);

		FILE *f;
		f = fopen("palavras.txt", "r+");
		if(f == 0) {
			printf("Desculpe, banco de dados não disponível\n\n");
			exit(1);
		}

		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;

		//posicionando a setinha do pro começo do arquivo
		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);
		
		//posicionando a setinha do pro fim do arquivo 
		fseek(f, 0, SEEK_END);
		fprintf(f, "%s\n", novapalavra);
		
		fclose(f);
	}
}

void escolhe_palavra() {
	FILE* f;
	f = fopen("palavras.txt", "r"); // retorna um ponteiro do arquivo 
	if(f==0) {
		printf("Desculpe, banco de dados não disponível\n\n");
		exit(1);
	}


	int qtddepalavras;
	fscanf(f, "%d", &qtddepalavras);

	srand(time(0));
	int randomico = rand() % qtddepalavras;

	for(int i = 0; i<= randomico; i++) {
		fscanf(f, "%s", palavra);
	}

	fclose(f);
}

int main() {
	escolhe_palavra();
	introducao();

	do {

	desenhaforca();
	chuta(); 

	} while(!acertou() && !enforcou());

	printf("FIM!\n");
	adicionapalavra();

	return(0);
}
