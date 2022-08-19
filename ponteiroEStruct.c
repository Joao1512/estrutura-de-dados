#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int peso;
    int altura;
    int idade;
} Pessoa;

int main() {
    int x = 25;
    int* y = &x;
    printf("Valor de x: %i, Endereco de x na memoria: %i", x, y);

    Pessoa* enderecoPessoa =  (Pessoa*) malloc(sizeof(Pessoa));
    enderecoPessoa->altura = 1;
    enderecoPessoa->peso = 90;

    printf("Endereco de Pessoa: %i, tamanho de alocacao: %i altura: %i", enderecoPessoa, sizeof(Pessoa), enderecoPessoa->altura);
}