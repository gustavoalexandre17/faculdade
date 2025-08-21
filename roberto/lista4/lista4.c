// primeira questao

/*
#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  const int size = n;
  int vec[n];

  for (int i = 0; i < size; i++) {
    printf("Digite o numero %d da sequencia\n", i + 1);
    scanf("%d", &vec[i]);
  }

  printf("\n");

  // imprimindo os elementos do vetor

  for (int i = 0; i < size; i++)
    printf("(%d) ", vec[i]);
  return 0;
}
A*/

/*
// segunda questão

#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;
  printf("Qual será o tamanho do vetor?\n");
  scanf("%d", &n);
  const int size = n;
  int v[size];

  for (int i = 0; i < size; i++) {
    printf("Digite o elemento %d do vetor: \n", i + 1);
    scanf("%d", &v[i]);
  }

  printf("\n");

  // imprimindo os elementos do vetor preenchido
  for (int i = 0; i < size; i++)
    printf("%d\n", v[i]);

  printf("\n");

  // analizando se x faz parte do vetor:
  int x;
  int xIndex[size]; // terao no máximo SIZE numeros iguais
  int xCount = 0; // ajudará a preencher o vetor xIndex
  printf("Variável x:\n");
  scanf("%d", &x);

  int y;
  int isY = 0;
  printf("Variável y:\n");
  scanf("%d", &y);

  printf("\n");

  for (int i = 0; i < size; i++) {
    if (v[i] == x) {
      printf("%d pertence ao vetor!\n", x);
      xIndex[xCount] = i;
      xCount++;
    }
    if (v[i] == y) {
      printf("%d pertence vetor!\n", y);
      isY = 1;
    }
  }

  if (isY == 0) {
    for (int i = 0; i < xCount; i++) {
      v[xIndex[i]] = y;
    }
  }

  // imprimindo o vetor novamente:
  printf("\n");
  for (int i = 0; i < size; i++)
    printf("%d\n", v[i]);

  return 0;
}
*/

// terceira questao

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n;
  printf("Qual será o tamanho dos vetores?\n");
  scanf("%d", &n);
  const int size = n;
  int v1[size];
  int v2[size];
  char sv1[size + 1];
  char sv2[size + 1];
  char result[size + 2];

  printf("Digite os elementos dos vetores (pares: v1[i] v2[i]):\n");

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v1[i], &v2[i]);

    if ((v1[i] < 0 || v1[i] > 9) || (v2[i] < 0 || v2[i] > 9)) {
      printf("Cada elemento dos arrays deve ser um dígito entre 0 e 9!\n");
      return 0;
    }
    sv1[i] = v1[i] + '0';
    sv2[i] = v2[i] + '0';
  }

  sv1[size + 1] = '\0';
  sv2[size + 1] = '\0';

  int n1 = atoi(sv1);
  int n2 = atoi(sv2);
  int final = n1 + n2;

  printf("%d\n", final);
  return 0;
}
*/

// quarta questao
/*
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a,
         const void *b) { // funcao que define a maneira como qsort irá
ordernar int valor_a = *(const int *)a; int valor_b = *(const int *)b;

  return (valor_a - valor_b);
}

int main(int argc, char *argv[]) {
  // ponteiro para a funcao comp
  int (*compararInteiros)(const void *a, const void *b);
  compararInteiros = comp;
  int n;

  printf("Qual será o tamanho dos vetores?\n");
  scanf("%d", &n);
  const int size = n;
  int v1[size];
  int v2[size];
  int v3[2 * size];

  printf("Preencha os dois vetores alternativamente (primeiro v1[i e depois
" "v2[i)\n"); for (int i = 0; i < n; i++) { scanf("%d %d", &v1[i], &v2[i]);
    v3[2 * i] = v1[i];       // posicao par
    v3[(2 * i) + 1] = v2[i]; // posicao par
  }
  qsort(v3, 2 * size, sizeof(int), comp);

  for (int i = 0; i < 2 * size; i++)
    printf("(%d) ", v3[i]);
  return 0;
}
*/

// quinta questao

/*
#include <stdio.h>
#include <stdlib.h>

int invert(int x, char *buffer) {
  int negative = x < 0;
  if (negative)
    x = -x;

  int i = 0;
  while (x > 0) {
    buffer[i++] = (x % 10) + '0';
    x /= 10;
  }

  buffer[i] = '\0';
  int result;
  if (negative)
    result = atoi(buffer) * -1;
  else
    result = atoi(buffer);

  return result;
}

int main(int argc, char *argv[]) {
  int n;
  printf("Qual será o tamanho do vetor?\n");
  scanf("%d", &n);
  const int size = n;
  int v[size];
  char buffer[size];

  for (int i = 0; i < size; i++) {
    printf("Insira o elemento %d do vetor\n", i);
    scanf("%d", &v[i]);
    if (v[i] == invert(v[i], buffer)) {
      printf("O elemento %d é um palíndromo!\n", v[i]);
    }
  }
  return 0;
}

*/

// sexta questão:

/*
int sum(int x) { // funcao que soma as casas decimais de um numero
  int cont = 0;
  while (x > 0) {
    cont += x % 10;
    x /= 10;
  }

  return cont;
}

#include <stdio.h>

int main(int argc, char *argv[]) {
  const int size = 8;
  int d1[size];
  int d2[size];
  int cont1 = 0;
  int cont2 = 0;

  // 19011981
  printf("Digite a primeira data de aniversário:\n");
  for (int i = 0; i < size; i++) {
    scanf("%d", &d1[i]);
    cont1 += d1[i];
  }

  // 20021979
  printf("Digite a segunda data de aniversário:\n");
  for (int i = 0; i < size; i++) {
    scanf("%d", &d2[i]);
    cont2 += d2[i];
  }

  if (sum(cont1) == sum(cont2)) {
    printf("O casal é perfeito!\n");
  } else
    printf("O csal não é perfeito.\n");

  return 0;
}
*/
