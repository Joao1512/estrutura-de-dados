//
// Created by joao on 16/08/2022.
//
#include <stdio.h>
#include <stdlib.h>
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

// Retorna a quantidade de elementos presentes na lista.
int tamanho(LISTA* l) {
    int tamanho = 0;
    ELEMENTO* elementoValido = l->cabeca; // elementoValido inicialmente guarda o endereço do primeiro elemento da lista;
    while (elementoValido != NULL) {
        tamanho++;
        elementoValido = elementoValido->prox;
    }
    return tamanho;
}

// Monta um print da lista no formato [1, 2, 3].
void exibir(LISTA* l) {
    ELEMENTO* elementoValido = l->cabeca;
    int index = 0;
    if (elementoValido != NULL) {
        printf("[");
        while (elementoValido != NULL) {
            if (elementoValido->prox == NULL) {
                printf("%i", elementoValido->registro.chave);
            }
            else {
                printf("%i, ", elementoValido->registro.chave);
            }
            elementoValido = elementoValido->prox;
            index++;
        }
        printf("]");
    }
}

// Retorna, sem remover, o primeiro elemento da lista.
int exibirPrimeiro(LISTA* l) {
    return l->cabeca->registro.chave;
}

// Retorna, sem remover, o último elemento da lista.
int exibirUltimo(LISTA* l) {
    return l->ultimo->registro.chave;
}

// Remove da lista o elemento da posição especificada, se a posição for válida.
LISTA* remover(LISTA* l, int index) {
    if (index < tamanho(l)) {
        ELEMENTO* elementoAux = l->cabeca;
        if (index == 0) {
            l->cabeca = l->cabeca->prox;
            return l;
        }
        for (int i = 0; i < index - 1; i++) {
            elementoAux = elementoAux->prox;
        }
        ELEMENTO* remover = elementoAux->prox;
        elementoAux->prox = remover->prox;
        free(remover);

        return l;
    }
    return NULL;
}

// Remove da lista a primeira ocorrência da chave especificada, se existir.
LISTA* removerOcorrencia(LISTA* l, CHAVE chave) {
    ELEMENTO* elementoAux = l->cabeca;
    if (elementoAux->registro.chave == chave) {
        l->cabeca = l->cabeca->prox;
        return l;
    }
    while (elementoAux != NULL) {
        if (elementoAux->prox->registro.chave == chave) {
            ELEMENTO* remover = elementoAux->prox;
            elementoAux->prox = remover->prox;
            free(remover);
            return l;
        }
        elementoAux = elementoAux->prox;
    }
    return NULL;
}

// Insere a chave especificada na posição especificada, se a posição for válida.
LISTA* inserir(LISTA* l, CHAVE chave, int index) {
    if (index <= tamanho) {
        ELEMENTO* elementoAux = l->cabeca;

        ELEMENTO* novoElemento = (ELEMENTO*) malloc(sizeof (ELEMENTO));
        novoElemento->registro.chave = chave;

        if (index == 0) {
            novoElemento->prox = l->cabeca;
            l->cabeca = novoElemento;
            return l;
        }
        for (int i = 0; i < index - 1; ++i) {
            elementoAux = elementoAux->prox;
        }
        ELEMENTO* prox = elementoAux->prox;
        elementoAux->prox = novoElemento;
        novoElemento->prox = prox;

        return l;
    }
    return NULL;
}

// Retorna o primeiro elemento que tem ocorrência da chave especificada.
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

// Insere a chave especificada no início da lista.
LISTA* inserirInicio(LISTA* l, CHAVE chave) {
    ELEMENTO* novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novoElemento->registro.chave = chave;
    novoElemento->prox = l->cabeca;
    l->cabeca = novoElemento;
    return l;
};

// Retorna o índice da primeira ocorrência da chave especificada, ou -1 caso a chave não exista.
int indexOf(LISTA* l, CHAVE chave) {
    ELEMENTO* elementoAux = l->cabeca;
    if (chave == elementoAux->registro.chave) {
        return 0;
    }
    int index = 0;
    while (elementoAux != NULL) {
        if (elementoAux->registro.chave == chave) {
            return index;
        }
        elementoAux = elementoAux->prox;
        index++;
    }
    return -1;
}

// Insere a chave especificada no fim da lista.
LISTA* inserirFinal(LISTA* l, CHAVE chave) {
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
    return l;
}

int main() {
    LISTA lista ;
    lista.cabeca = NULL;
    lista.ultimo = NULL;
    inserirInicio(&lista, 3);
    inserirInicio(&lista, 2);
    inserirInicio(&lista, 1);
    exibir(&lista);
    printf("tamanho: %i", tamanho(&lista));
    // Console output: [1, 2, 3, ]tamanho: 4
}
