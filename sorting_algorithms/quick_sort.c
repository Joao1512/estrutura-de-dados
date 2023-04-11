#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int lastMinor = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            lastMinor++; // para colocar a esquerda +1 elemento menor que o pivot, e guardar seu indice
            int temp = arr[j];
            arr[j] = arr[lastMinor];
            arr[lastMinor] = temp;
        }
    }
    int temp = arr[lastMinor + 1];
    arr[lastMinor + 1] = arr[end];
    arr[end] = temp;
    return lastMinor + 1;
}

int* quickSort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int indexPivot = partition(array, inicio, fim);
        quickSort(array, inicio, indexPivot - 1);
        quickSort(array, indexPivot + 1, fim);
    }
}

int* fillWithRandomInts(int array[]) {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Gera um número aleatório entre 1 e 1000000 e preenche o array com o número
    for (int i =0; i < 10000; i++) {
        int random_num = (rand() % 100000) + 1;
        array[i] = random_num;
    }
}

void printArray(int array[]) {
    for (int i = 0; i < 10000; i++) {
        printf("%i ", array[i]);
    }
}

int main() {
    // inicializa e preenche um array com 100000 de números.
    int array[10000] = {};
    fillWithRandomInts(array);

    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, sizeOfArray - 1);

    printArray(array);
}