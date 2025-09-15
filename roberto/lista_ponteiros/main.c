#include <stdio.h>
#include <string.h>

void swap_char(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void printa_string(char *vector, int size)
{
    for(int c = 0; c < size; c++) printf("%c", vector[c]);
    printf("\n");
}

/*
// questao 1
int main(void)
{
    char string[] = "programacao";
    const int size = strlen(string);
    char *begin = string;
    char *end = &string[size - 1];
    const int limit = size/2;

    printa_string(string, size);

    for(int c = 0; c < limit; c++)
    {
        swap_char(begin, end);
        begin++;
        end--;
    }

    printa_string(string, size);

    return 0;
}
*/

//questao 2
/*
int main()
{
    char string[] = {"arara"};
    const int size = strlen(string);
    const int limit = size/2;
    char *begin = string;
    char *end = &string[size - 1];

    for(int i = 0; i < limit; i++)
    {
        if(*begin != *end)
        {
            printf("%s não é um palíndromo!\n", string);
            return 0;
        }
    }
    printf("%s é um palíndromo!\n", string);
    return 0;
}
*/

// questao 3 

int main(int argc, char const *argv[])
{
    int vectorA[3] = {1, 2, 3};
    int vectorB[3] = {4, 5, 6};
    const int size = 3;
    int result = 0;
    int *aPtr = vectorA;
    int *bPtr = vectorB;

    for(int i = 0; i < size; i++)
    {
        result += (*aPtr * *bPtr);
        aPtr++;
        bPtr++;
    }
    printf("Produto escalar = %d\n", result);
    return 0;
}
