#include <stdio.h>

// o número retornado representa a altura e largura dos maiores quadrados iguais que dividem a área.
int divideAreaIntoEqualSquares(int largura, int altura) {
    int maior = 0;
    int menor = 0;
    // passo 1: encontrar o lado maior e o menor
    if ((largura - altura) >= 0) {
        maior = largura;
        menor = altura;
    }
    else {
        maior = altura;
        menor = largura;
    }
    // passo 2: encontrar o resto da divisão do maior pelo menor.
    int resto = maior % menor;
    if (resto == 0) { // se forem múltiplos, encontrei o maior quadrado (Algoritmo de Euclides).
        return menor;
    }
    else { // se não for múltiplo, divido novamente usando um quadrado com lados Maior x Resto
        return divideAreaIntoEqualSquares(menor, resto);
    }
}

int main() {
    int maiorQuadrado = divideAreaIntoEqualSquares(1680, 640); // 80
    printf("%i", maiorQuadrado);
}