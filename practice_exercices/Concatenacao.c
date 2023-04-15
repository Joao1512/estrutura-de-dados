#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int conteudo;
    struct celula *proximo;
} celula;

// Insere no inicio da sequência.
void insere(int conteudo, celula *inicio) {
    celula* nova = (celula*) malloc(sizeof(celula));
    nova->conteudo = conteudo;
    nova->proximo = inicio->proximo;

    inicio->proximo = nova;
}

// Print sequencial das celulas que formam a lista.
void imprime(celula* cabeca) {
    celula* aux = cabeca;

    while (aux->proximo != NULL) {
        aux = aux->proximo;
        printf("\n Conteudo: %i", aux->conteudo);
    }
}

// cria uma lista de 3 celulas com números aleatórios.
celula criaLista() {
    celula cabeca;
    cabeca.proximo = NULL;
    for (int i = 0; i < 3; ++i) {
        insere(rand(), &cabeca);
    }
    printf("\n --------");
    return cabeca;
}

// Concatena a primeira celula na segunda celula.
void concatena(celula *cabeca1, celula *cabeca2) {
    celula* aux = cabeca1;
    aux = aux->proximo;
    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = cabeca2->proximo;

    printf("\nCONCATENADAS: \n");
    imprime(aux);
}

int main() {
    celula celula1 = criaLista();
    celula celula2 = criaLista();

    concatena(&celula1, &celula2);


}




