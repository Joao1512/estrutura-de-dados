#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct NO {
    char dado;
    struct NO *prox;
} NO;

typedef struct {
    struct NO *topo;
} PILHA;

bool adicionar(char dado, PILHA *p ) {

    NO* nova = (NO*) malloc(sizeof(NO));
    nova->dado = dado;

    nova->prox = p->topo;
    p->topo = nova;
    return true;
}

bool remover(PILHA *p) {
    NO* removido = p->topo;
    p->topo = p->topo->prox;
    free(removido);
    return true;
}

void visualizar(PILHA *p) {
    NO* aux = p->topo;
    while (aux != NULL) {
        printf("\n Elemento: %i", aux->dado);
        aux = aux->prox;
    }
}

void inicializar(PILHA *p) {
    p->topo = NULL;
}

bool bemFormada(char str[5], PILHA *p) {
    for (int i = 0; str[i] != '\0'; ++i) {
        printf("\n dado: %s", str[i]);
        if (str[i] == ')') {
            if (str[i] == p->topo->dado) {remover(p);}
            else {return false;}
        }
        else if (str[i] == '}') {
            if (str[i] == p->topo->dado) {remover(p);}
            else {return false;}
        }
        else {
            adicionar(str[i], p);
        }
        return true;
    }
}

int main() {
    PILHA* pilha = (PILHA*) malloc(sizeof(PILHA));
    inicializar(pilha);
    char string1[5] = {'(', '{', '}', ')'}; //"({})";
    char string2[5] = {'(', '{',')', '}'}; //"({)}";
    bool ehBemFormada = bemFormada(string1, pilha);
    bool ehBemFormada2 = bemFormada(string2, pilha);
    printf("%d\n", ehBemFormada);
    printf("%d\n", ehBemFormada2);
}