#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int line, int col)
{
  int counter = 0;
  for (int i = 0; i < line; i++)
    for (int j = 0; j < col; j++)
    {
      if (counter % col == 0)
        printf("\n");
      printf("%d ", matrix[i][j]);
      counter++;
    }
  printf("\n");
}

void fill_matrix(int **matrix, int line, int col)
{
  printf("Enter the elements:\n");
  for (int i = 0; i < line; i++)
    for (int j = 0; j < col; j++)
      scanf("%d", &matrix[i][j]);
}

static inline void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

static inline void swap_arrays(int **a, int **b)
{
  int *temp = *a;
  *a = *b;
  *b = temp;
}

void invert_elements(int **matrix, int line, int col)
{ 
  const int limit = col / 2;
  for(int i = 0; i < line; i++)
  {
    for(int j = 0; j < limit; j++)
    {
      swap(&matrix[i][j], &matrix[i][col - j - 1]);
    }
  }
}

void invert_line_order(int **matrix, int line)
{
  int begin = 0;
  int end = line - 1;

  while(begin < end)
  { 
    swap_arrays(&matrix[begin], &matrix[end]);
    begin++;
    end--;
  }
}

static inline int canbeMult(int col1, int line2)
{
  if (col1 == line2)
    return 1;
  return 0;
}

static inline int inMainDig(int line, int col)
{
  if (line != col)
    return 0;
  return 1;
}

static inline int isQuad(int lines, int colums)
{
  if (lines != colums)
    return 0;
  return 1;
}

int **multi(int **matrix1, int **matrix2, int line1, int line2, int col1, int col2)
{
  int **result;
  const int size = sizeof(int);
  result = (int **)malloc(line1 * size);
  for (int i = 0; i < line1; i++)
    result[i] = (int *)malloc(col2 * size);

  for (int i = 0; i < line1; i++)
    for (int j = 0; j < col2; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < col1; k++)
      {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  return result;
}

void rotate(int ** matrix, int line, int col)
{ 
    invert_elements(matrix, line, col);
    invert_line_order(matrix, line);
}

int isMagicSquare(int **matrix, int line, int col)
{
  int magicSum = 0;
  for (int j = 0; j < col; j++)
    magicSum += matrix[0][j];

  // verificando as linhas
  for (int i = 1; i < line; ++i)
  {
    int currentLinesum = 0;
    for (int j = 0; j < col; ++j)
    {
      currentLinesum += matrix[i][j];
    }
    if (currentLinesum != magicSum)
      return 0;
  }

  // verificando as colunas

  for (int i = 0; i < line; i++)
  {
    int currentColsum = 0;
    for (int j = 0; j < col; j++)
    {
      currentColsum += matrix[i][j];
    }
    if (currentColsum != magicSum)
      return 0;
  }

  // diagonais
  int mainDigsum = 0;
  int secDigsum = 0;
  for (int i = 0; i < line; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (i == j)
        mainDigsum += matrix[i][j];
      if ((i + j) == line - 1)
        secDigsum += matrix[i][j];
    }
  }

  if (mainDigsum != magicSum || secDigsum != magicSum)
    return 0;

  return 1;
}

/*
// questao 1
int main(void)
{
    int **matrix;
    int line, col;
    printf("Número de linhas e colunas:\n");
    scanf("%d", &line);
    scanf("%d", &col);

    matrix = (int **)malloc(line * sizeof(int *));
    for(int i = 0; i < line; i++)
        matrix[i] = (int *)malloc(col * sizeof(int));

    fill_matrix(matrix, line, col);

    printf("Por qual escalar voce deseja multiplicar a matriz? ");
    int escalar;
    scanf("%d", &escalar);

    for(int i = 0; i < line; i++)
        for(int j = 0; j < col; j++)
            matrix[i][j] *= escalar;

    print_matrix(matrix, line, col);

    return 0;
}
*/

/*
// questao 3
int main(int argc, char const *argv[])
{
    int **matrix;
    int line, col;
    printf("Número de linhas e colunas:\n");
    scanf("%d", &line);
    scanf("%d", &col);

    matrix = (int **)malloc(line * sizeof(int *));
    for (int i = 0; i < line; i++)
        matrix[i] = (int *)malloc(col * sizeof(int));

    fill_matrix(matrix, line, col);
    int result = 0;

    for(int i = 0; i < line; i++)
        for(int j = 0; j < col; j++)
            result += matrix[i][j];

    printf("%d\n", result);
    return 0;
}
*/

/*
// questao 5
int main(int argc, char const *argv[])
{
    int **matrix;
    int line, col;
    printf("Número de linhas e colunas:\n");
    scanf("%d", &line);
    scanf("%d", &col);

    matrix = (int **)malloc(line * sizeof(int *));
    for (int i = 0; i < line; i++)
        matrix[i] = (int *)malloc(col * sizeof(int));

    fill_matrix(matrix, line, col);
    int result = 0;

    for (int i = 0; i < line; i++)
        for (int j = 0; j < col; j++)
        {
          result =  matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] *
matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] *
matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] *
matrix[2][0]);
        }
    print("%d", result);
    return 0;
}
*/

/*
// questao 6
int main(void)
{
    int **matrix;
    int **new_matrix;

    int line, col;
    printf("Número de linhas e colunas:\n");
    scanf("%d", &line);
    scanf("%d", &col);

    matrix = (int **)malloc(line * sizeof(int *));
    for (int i = 0; i < line; i++)
        matrix[i] = (int *)malloc(col * sizeof(int));

    new_matrix = (int**)malloc(col * sizeof(int));
    for(int j = 0; j < col; j++)
        new_matrix[j] = (int*)malloc(line * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
            new_matrix[j][i] = matrix[i][j];
        }
    }

    print_matrix(matrix, line, col);
    printf("\n");
    print_matrix(new_matrix, col, line);
    return 0;
}
*/

/*
//questao 7
int main(int argc, char const *argv[])
{
    int **matrix1;
    int ** matrix2;
    int line1, col1, line2, col2;
    printf("Número de linhas e colunas da primeira:\n");
    scanf("%d", &line1);
    scanf("%d", &col1);

    printf("Número de linhas e colunas da segunda:\n");
    scanf("%d", &line2);
    scanf("%d", &col2);

    if(canbeMult(col1, line2) == 0)
    {
        printf("As matrizes nao podem ser multiplicadas!\n");
        return 0;
    }

    matrix1 = (int **)malloc(line1 * sizeof(int *));
    for (int i = 0; i < line1; i++)
        matrix1[i] = (int *)malloc(col1 * sizeof(int));

    matrix2 = (int **)malloc(line2 * sizeof(int *));
    for (int i = 0; i < line2; i++)
        matrix2[i] = (int *)malloc(col2 * sizeof(int));

    fill_matrix(matrix1, line1, col1);
    fill_matrix(matrix2, line2, col2);

    int **result = multi(matrix1, matrix2, line1, line2, col1, col2);
    print_matrix(result, line1, col2);
    printf("\n");

    return 0;
}
*/

/*
//questao 8
int main(int argc, char const *argv[])
{
    int **matrix;
    int line, col;
    printf("Número de linhas e colunas:\n");
    scanf("%d", &line);
    scanf("%d", &col);

    matrix = (int **)malloc(line * sizeof(int *));
    for (int i = 0; i < line; i++)
        matrix[i] = (int *)malloc(col * sizeof(int));

    fill_matrix(matrix, line, col);

    int dom = 1;
    int linesum = 0;

    for(int i = 0; i < line; i++)
    {
        linesum = 0;
        for(int j = 0; j < col; j++)
        {
            if(inMainDig(i, j))
            {
                for(int k = 0; k < col; k++)
                {
                    if(k != j)
                        linesum += matrix[i][k];
                }
                if(matrix[i][j] <= linesum) dom = 0;
            }
        }
    }

    if(dom == 0) printf("A matriz tem a diagonal principal dominante!\n");
    else printf("A matriz nao tem a diagonal principal dominante.\n");

    return 0;
}
*/

/*
// questao 9
int main(int argc, char const *argv[])
{
  int **matrix;
  int line, col, linessum, colsum, mainDigsum, secDigsum;
  linessum = 0;
  colsum = 0;
  mainDigsum = 0;
  secDigsum = 0;

  printf("Número de linhas e colunas:\n");
  scanf("%d", &line);
  scanf("%d", &col);

  if (!isQuad(line, col))
  {
    printf("Por favor, insira uma matriz quadrática!\n");
    return 0;
  }

  matrix = (int **)malloc(line * sizeof(int *));
  for (int i = 0; i < line; i++)
    matrix[i] = (int *)malloc(col * sizeof(int));

  fill_matrix(matrix, line, col);

  int result = isMagicSquare(matrix, line, col);

  if (result)
    printf("1\n");
  else
    printf("0\n");

  return 0;
}
*/

/*
// questao 10 
int main(void)
{
  int **matrix;
  int line, col;

  printf("Número de linhas e colunas:\n");
  scanf("%d", &line);
  scanf("%d", &col);

  matrix = (int **)malloc(line * sizeof(int *));
  for (int i = 0; i < line; i++)
    matrix[i] = (int *)malloc(col * sizeof(int));

  fill_matrix(matrix, line, col);
  print_matrix(matrix, line, col);
  rotate(matrix, line, col);
  print_matrix(matrix, line, col);

  return 0;
}
*/