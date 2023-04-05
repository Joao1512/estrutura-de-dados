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
 ELEMENTO *ultimo;
} LISTA;

int tamanho(LISTA* l) {
    int tamanho = 0;
    ELEMENTO* elementoValido = l->cabeca; // elementoValido inicialmente guarda o endereço do primeiro elemento da lista;
    while (elementoValido != NULL) {
        tamanho++;
        elementoValido = elementoValido->prox;
    }
    return tamanho;
}

void exibir(LISTA* l) {
    ELEMENTO* elementoValido = l->cabeca;
    int index = 0;
    if (elementoValido != NULL) {
        printf("[");
        while (elementoValido != NULL) {
            printf("%i, ", elementoValido->registro.chave);
            elementoValido = elementoValido->prox;
            index++;
        }
        printf("]");
    }

}

ELEMENTO* buscaSequencial(LISTA* l, CHAVE chave) {
    ELEMENTO* elementoValido = l->cabeca;
    while(elementoValido != NULL) {
        if (elementoValido->registro.chave == chave) {
            return elementoValido;
        }
        elementoValido = elementoValido->prox;
    }
    return NULL;
}

void inserirInicio(LISTA* l, CHAVE chave) {
    ELEMENTO* novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novoElemento->registro.chave = chave;
    novoElemento->prox = l->cabeca;
    l->cabeca = novoElemento;
};


void inserirFinal(LISTA* l, CHAVE chave) {
    ELEMENTO* novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novoElemento->registro.chave = chave;
    novoElemento->prox = NULL;
    if (l->cabeca == NULL) { // Caso ainda não existam elementos na lista
        l->cabeca = novoElemento;
        l->ultimo = novoElemento; // O único elemento é o primeiro e o último ao mesmo tempo.
    }
    else {
        l->ultimo->prox = novoElemento; // último elemento passa a apontar para o novo elemento
        l->ultimo = novoElemento; // Salva a referência do novo último elemento
    }
}

int main() {
    LISTA lista ;
    lista.cabeca = NULL;
    lista.ultimo = NULL;
    inserirFinal(&lista, 1);
    inserirFinal(&lista, 2);
    inserirFinal(&lista, 3);
//    inserirInicio(&lista, 0);
    exibir(&lista);
    printf("tamanho: %i", tamanho(&lista));
    // Console output: [0, 1, 2, 3, ]tamanho: 4
}
