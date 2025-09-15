/*
// questao 10
#include <stdio.h>
#include <string.h>

int main() {
  char frase[100];
  char palavraA[20];
  char palavraB[20];

  printf("Digite a frase: ");
  fgets(frase, sizeof(frase), stdin);
  frase[strcspn(frase, "\n")] = '\0';
  const int size = strlen(frase);

  printf("Palavra A: ");
  fgets(palavraA, sizeof(palavraA), stdin);
  palavraA[strcspn(palavraA, "\n")] = '\0';

  printf("Palavra B: \n");
  fgets(palavraB, sizeof(palavraB), stdin);
  palavraB[strcspn(palavraB, "\n")] = '\0';

  char temp[20];

  if (strstr(frase, palavraA) != NULL || strstr(frase, palavraB) != NULL) {
    strcpy(temp, palavraA);
    strcpy(palavraA, palavraB);
    strcpy(palavraB, temp);
  }

  for (size_t i = 0; i < size; i++)
    printf("%c", frase[i]);

  return 0;
}
*/
/*
// questao 9
#include <stdio.h>
#include <string.h>

int main() {
  char frase[100];

  printf("Digite a frase: ");
  fgets(frase, sizeof(frase), stdin);

  frase[strcspn(frase, "\n")] = '\0';
  const int size = strlen(frase);

  for (size_t c = 0; c < size; c++) {
    if (frase[c] != ' ') {
      printf("%c", frase[c]);
      printf("%c", frase[c]);
    } else
      printf("%c", frase[c]);
  }

  return 0;
}
*/

/*
// questao 8
#include <stdio.h>
#include <string.h>

int main() {
  char nomes[4][50];
  char temp[50];

  for (size_t i = 0; i < 4; i++) {
    printf("Digite o nome %d\n", i + 1);
    fgets(nomes[i], sizeof(nomes[i]), stdin);

    nomes[i][strcspn(nomes[i], "\n")] = '\0';
  }
  // ordenando usando bubblesort

  for (size_t i = 0; i <= 3; i++) {
    for (size_t j = i + 1; j < 4; j++) {
      // olha se a primeira vem antes no dicionario
      if (strcmp(nomes[i], nomes[j]) > 0) {
        strcpy(temp, nomes[i]);
        strcpy(nomes[i], nomes[j]);
        strcpy(nomes[j], temp);
      }
    }
  }

  printf("\nNomes em ordem alfabética:\n");
  for (int i = 0; i < 4; i++) {
    printf("%s\n", nomes[i]);
  }

  return 0;
}
*/

/*
// questao 7
// imprime o primeiro e o ultimo nome
#include <stdio.h>
#include <string.h>

int main() {
  char nome[100];
  char primeiro[50], ultimo[50];

  printf("Digite o nome completo: ");
  fgets(nome, sizeof(nome), stdin);

  // Remove '\n' se existir
  nome[strcspn(nome, "\n")] = '\0';

  // Encontra primeiro nome
  char *token = strtok(nome, " ");
  strcpy(primeiro, token);

  // Encontra último nome
  while (token != NULL) {
    strcpy(ultimo, token);
    token = strtok(NULL, " ");
  }

  printf("%s, %s\n", primeiro, ultimo);

  return 0;
}
*/
/*
// questao 6
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char attempt[30];
  int errors = 0;

  while (errors < 3) {
    fgets(attempt, sizeof(attempt), stdin);
    if (strcmp(attempt, "password\n") == 0) {
      printf("Acesso liberado!\n");
      return 0;
    }
    errors++;
  }
  printf("Explodindo o computador...\n");
  return 0;
}
*/

// questao 4
/*
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char usr[30];
  int palavras = 0;
  int dentro_Palavra = 0;

  if (fgets(usr, sizeof(usr), stdin) == NULL) {
    return 1;
  }
  int len = strlen(usr);

  for (int i = 0; i < len; ++i) {
    if (!isspace(usr[i])) {
      if (dentro_Palavra == 0) {
        palavras++;
        dentro_Palavra = 1;
      }
    } else
      dentro_Palavra = 0;
  }

  printf("%d\n", palavras);
  return 0;
}
*/

/*
// questao 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *usr = "200700";
  const int size = strlen(usr);

  int aux = size;
  for (int i = 0; i < size; i++) {
    if ()
      printf("%c", usr[i]);
    aux--;
  }
}
*/

/*
// questao 14
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *usr = "Hello";
  const int size = strlen(usr);

  int aux = 0;
  for (int i = 0; i < size; i++) {
    printf("\n");
    for (int j = 0; j <= aux; j++) {
      printf("%c", usr[j]);
    }
    aux++;
  }
  printf("\n");
  return 0;
}
*/
