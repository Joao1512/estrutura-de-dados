#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NO {
   int dado;
   struct NO *prox;
}NO;

typedef struct {
    struct NO *ini;
    struct NO *fim;
}FILA;

// Cria um elemento no fim da fila para guardar o dado especificado.
void adicionar(int dado, FILA *f) {
    // =======================================
    NO* nova = (NO*) malloc(sizeof (NO));
    nova->dado = dado;                      // Alocando memoria para novo registro a ser adicionado na fila
    nova->prox = NULL;
    // =======================================

    // =======================================
    if (f->ini == NULL) {
        f->ini = nova;                      // Se a lista estiver vazia, coloca o novo registro no inicio
    }
    // =======================================

    // =======================================
    else {
        f->fim->prox = nova;                // Se a lista NÃO estiver vazia, o ultimo registro é ligado no novo registro.
    }
    // =======================================
    f->fim = nova;
}

//Busca sequencial que retorna o índice do elemento que contem o dado especificado;
int buscar(int dado, FILA *f) {
    NO* aux = f->ini;
    int count = 0;
    while (aux != NULL) {
        if (aux->dado == dado) {
            return count;
        }
        count++;
    }
    return -1;
}

// Remove o primeiro elemento da fila.
bool remover(FILA *f) {
    if (f->ini == NULL) return false;
    NO* aux = f->ini;
    f->ini = f->ini->prox;
    if (f->ini == NULL) f->fim = NULL;
    free(aux);
    return true;
}

// remove todos so elementos da fila.
bool reinicializarFila(FILA *f) {
    NO* aux = f->ini;
    while (aux != NULL) {
        NO* apagar = aux;
        aux = aux->prox;
        free(apagar);
    }
}

// Print sequencial dos elementos da fila.
void visualizarFila(FILA *f) {
    NO* aux = f->ini;
    while (aux != NULL) {
        printf("\n Dado: %i", aux->dado);
        aux = aux->prox;
    }
}

// Retorna a quantidade de elementos na fila.
int tamanhoFila(FILA *f) {
    int count = 0;
    NO* aux = f->ini;
    while(aux->prox != NULL) {
        aux = aux->prox;
        count++;
    }
    return count;
}

FILA* inicializarFila() {
    FILA* fila = (FILA*) malloc(sizeof(FILA));
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

int main() {
    FILA* fila = inicializarFila();

    adicionar(11, fila);
    adicionar(22, fila);
    adicionar(33, fila);

    printf("\n Resultado busca: %i", busca(22, fila));
    visualizar(fila);


}