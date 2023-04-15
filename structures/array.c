#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int CHAVE;

int TAMANHO = 10;

typedef struct {
    CHAVE chave;
    int valor;
} ELEMENTO;

typedef struct {
    ELEMENTO A[10];
    int qntdElementos;
} LISTA;

// Remove os valores de todos os elementos.
void limparElementosLista(LISTA* lista) {
    lista->qntdElementos = 0;
    for (int i = 0; i < 10; ++i) {
        lista->A[i].valor = -1;
        lista->A[i].chave = i;
    }
}

// Print Sequencial dos elementos. 
void exibirElementosLista(LISTA* lista) {
    printf("Numero de elementos: %i \n", lista->qntdElementos);
    for (int i = 0; i < lista->qntdElementos; ++i) {
        printf(" indice: %i ", i);
        printf(" chave: %i ", lista->A[i].chave);
        printf(" valor: %i \n", lista->A[i].valor);


    }
}

// Pesquisa sequencial que retorna o úndice do primeiro elemento que contem a chave especificada. Retorna -1 caso não encontre.  
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

// Verifica se há um elemento no índice especificado.
bool espacoEstaOcupado(LISTA* lista, int posicao) {
    if (lista->A[posicao].valor == -1) {
        return false;
    }
    else {
        return true;
    }
}

// Verifica se o elemento especificado pode ser inserido.
bool insercaoValida(LISTA* lista, int posicao) {
    if ((lista->qntdElementos >= TAMANHO) || posicao < 0 || posicao >= TAMANHO) {
        printf("Nao e possivel inserir elemento na posicao %i. \n", posicao);
        return false;
    }
    else {
        return true;
    }
}

// Desloca todos os elementos uma casa a direita a partir da posição especificada.
void empurrarElementos(LISTA* lista, int posicao) {
    for (int j = lista->qntdElementos; j >= posicao; --j) {
        lista->A[j] = lista->A[j - 1];
    }
}

// Verifica se  é possível deslocar todos os elementos uma casa a direita a partir da posição especificada.
bool podeEmpurrar(LISTA* lista, int posicao) {
    if (lista->qntdElementos == TAMANHO) {
        printf("Nao e possivel empurrar, espaco insuficiente \n");
        return false;
    }
    return true;
}

/*
 * lista - ponteiro que aponta para uma LISTA.
 * elemento - será inserido na LISTA.
 * posicao - um int que determina em qual posicao da LISTA o elemento vai ser inserido.
 */
bool inserirElemento(LISTA* lista, ELEMENTO elemento, int posicao) {
    if (insercaoValida(lista, posicao) ) {
        if (espacoEstaOcupado(lista, posicao) && podeEmpurrar(lista, posicao)) {
            empurrarElementos(lista, posicao);
            lista->A[posicao] = elemento;
            lista->qntdElementos++;
            return true;
        }
        else if (!espacoEstaOcupado(lista, posicao)) {
            lista->A[posicao] = elemento;
            lista->qntdElementos++;
            return true;
        }
        else {
            printf("impossivel inserir o elemento de chave %i \n", elemento.chave);
            return false;
        }
    }
    else {
        return false;
    }
}

int main() {
    LISTA* lista1 = (LISTA*) malloc(sizeof(LISTA));
    limparElementosLista(lista1);
    for (int i = 10; i >= 1; i--) { // loop para testar a inserção de elementos 10 vezes.
        ELEMENTO elemento;
        elemento.chave = i;
        elemento.valor = i;
        inserirElemento(lista1, elemento, 0);
    }
    exibirElementosLista(lista1);
}

