#include <stdio.h>

void exibirElementosLista(int array[]) {
    for (int i = 0; i < 100; ++i) {
        printf(" \n indice: %i ", i);
        printf(" valor: %i ", array[i]);
    }
}

 int indexMinimumElement(int array[], int start) {
    int minimumIndex = start;
    int minimumElement = array[start];

    for (int i = start; i < 100; i++) {
        if (array[i] < minimumElement) {
            minimumElement = array[i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

// troca o menor elemento com o primeiro elemento.
void swap (int array[], int start, int indexOfMinimum) {
    int temp = array[start];
    array[start] = array[indexOfMinimum];
    array[indexOfMinimum] = temp;
}

 void selectionSort(int array[]) {
    for (int i = 0; i < 100; i++) {
        int indexOfMinimum = indexMinimumElement(array, i); // encontra o menor elemento a partir de i. a comparação fica cada vez menor.
        swap(array, i, indexOfMinimum);
    }
    exibirElementosLista(array);
}

int main() {

    int array[100] = {72, 38, 46, 92, 71, 3, 52, 57, 23, 99, 91, 73, 80, 34, 85, 15, 77, 44, 62, 32, 16,
                      12, 11, 78, 7, 26, 53, 55, 17, 33, 56, 95, 30, 64, 49, 76, 25, 86, 67, 14, 21,
                      68, 10, 75, 40, 28, 59, 20, 47, 70, 31, 37, 22, 9, 89, 29, 96, 79, 39, 87, 41,
                      48, 54, 43, 18, 35, 66, 97, 1, 65, 42, 90, 98, 74, 8, 61, 50, 27, 51, 19, 24,
                      69, 60, 36, 2, 58, 45, 13, 94, 5, 88, 6, 81, 63, 83, 4, 82, 84, 100, 93};

    selectionSort(array);
}