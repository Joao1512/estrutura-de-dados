#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int conteudo;
    struct celula *proximo;
} celula;

void insere(int conteudo, celula *cabeca) {
    celula* nova = (celula*) malloc(sizeof(celula));
    nova->conteudo = conteudo;
    nova->proximo = cabeca->proximo;

    cabeca->proximo = nova;
}

void imprime(celula* cabeca) {
    celula* aux = cabeca;

    while (aux->proximo != NULL) {
        aux = aux->proximo;
        printf("\n Conteudo: %i", aux->conteudo);

    }
}

celula criaLista() {
    celula cabeca;
    cabeca.proximo = NULL;
    for (int i = 0; i < 3; ++i) {
        insere(rand(), &cabeca);
    }
    imprime(&cabeca);
    printf("\n --------");
    return cabeca;
}

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




