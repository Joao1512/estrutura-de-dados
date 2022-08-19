#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int CHAVE;

int TAMANHO = 3;

typedef struct {
    CHAVE chave;
    int valor;
} ELEMENTO;

typedef struct {
    ELEMENTO A[10];
    int qntdElementos;
} LISTA;

void limparElementosLista(LISTA* lista) {
    printf("Inicializando limparLista...\n ");
    lista->qntdElementos = 0;
    for (int i = 0; i < 10; ++i) {
        lista->A[i].valor = -1;
        lista->A[i].chave = i;
    }
}


void exibirElementosLista(LISTA* lista) {
    printf("Numero de elementos: %i \n", lista->qntdElementos);
    for (int i = 0; i < 10; ++i) {

        printf(" chave: %i", lista->A[i].chave);

        printf(" valor: %i \n", lista->A[i].valor);
    }
}

int buscarElementoLista(LISTA* lista, CHAVE chave) {
    printf("iniciando busca por elemento...");
    for (int i = 0; i < lista->qntdElementos; ++i) {
        if (lista->A[i].chave == chave) {
            return lista->A[i].valor;
        } else {
            return -1;
        }
    }
}

bool espacoEstaOcupado(LISTA* lista, int posicao) {
    if (lista->A[posicao].valor == -1) {
        return false;
    }
    else {
        return true;
    }
}

bool insercaoValida(LISTA* lista, int posicao) {
    if ((lista->qntdElementos == TAMANHO) || posicao < 0 || posicao >= TAMANHO) {
        printf("Nao e possivel inserir elemento nesta posicao. \n");
        return false;
    }
    else {
        return true;
    }
}

void empurrarElementos(LISTA* lista, int posicao) {
    for (int j = lista->qntdElementos; j >= posicao; --j) {
        lista->A[j + 1] = lista->A[j];
         // qntdElementos = 1, j = 0 posicao = 0, tamanho = 3
        //   "2", "1", "-1",
    }
}

bool podeEmpurrar(LISTA* lista, int posicao) {
    if (posicao + 1 > TAMANHO) {
        return false;
    }
    printf("Nao e possivel empurrar, espaco insuficiente \n");
    return true;
}

bool inserirElementosLista(LISTA* lista, ELEMENTO elemento, int posicao) {
    if (insercaoValida(lista, posicao) ) {
        if (espacoEstaOcupado(lista, posicao) && podeEmpurrar(lista, posicao)) {
            empurrarElementos(lista, posicao);
        }
        lista->A[posicao] = elemento;
        lista->qntdElementos++;
        printf("ELEMENTO inserido na posicao %i \n", posicao);
        return true;
    }
    else {
        return false;
    }
}



int main() {
    LISTA* lista1 = (LISTA*) malloc(sizeof(LISTA));
    ELEMENTO elemento1;
    elemento1.chave = 1;
    elemento1.valor = 1;

    ELEMENTO elemento2;
    elemento2.chave = 2;
    elemento2.valor = 2;

    limparElementosLista(lista1);

    inserirElementosLista(lista1, elemento1, 0);
    inserirElementosLista(lista1, elemento2, 0);
    inserirElementosLista(lista1, elemento2, 1);


    exibirElementosLista(lista1);

//    int elementoBuscado = buscarElementoLista(lista1, 2);
//    printf("Elemento buscado: %i", elementoBuscado);
}

