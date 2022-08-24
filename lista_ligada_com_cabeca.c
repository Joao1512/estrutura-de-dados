//
// Created by joao on 16/08/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
typedef int CHAVE;

typedef struct {
    CHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO registro;
    struct aux *prox;
} ELEMENTO;

typedef struct {
 ELEMENTO *cabeca; // cabeca guarda o endereço de onde está uma estrutura do tipo ELEMENTO.
} LISTA;

int tamanho(LISTA* l) {
    int tamanho = 0;
    ELEMENTO* elementoValido = l->cabeca; // elementoValido guarda o endereço de um ELEMENTO;
    while (elementoValido != NULL) {
        tamanho++;
        elementoValido = elementoValido->prox;
    }
    return tamanho;
}

void exibir(LISTA* l) {
    ELEMENTO* elementoValido = l->cabeca;
    while (elementoValido != NULL) {
        printf("%i \n", elementoValido->registro.chave);
        elementoValido = elementoValido->prox;
    }
}

}

void inserirInicio(LISTA* l, CHAVE chave) {
    ELEMENTO* novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novoElemento->registro.chave = chave;
    novoElemento->prox = l->cabeca;
    l->cabeca = novoElemento;
};

int main() {

void inserirFinal(LISTA* l, CHAVE chave) {
    ELEMENTO* novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novoElemento->registro.chave = chave;
    novoElemento->prox = NULL;
    if (l->cabeca == NULL) {
        l->cabeca = novoElemento;
    }
    else {
        ELEMENTO* elementoValido = l->cabeca;
        while (elementoValido->prox != NULL) {
            elementoValido = elementoValido->prox;
        }
        elementoValido->prox = novoElemento;
    }
}
}
