#include <stdio.h>

int sum(int array[], int size) {
    if (size <= 0) {
        return array[0];
    }
    else {
        return array[size] + sum(array, size - 1);
    }
}

int main() {
    int array[3] = {1, 2, 3};
    int size = sizeof(array)/sizeof(array[0]);
    int total = sum(array, size); // 6
    printf("total:  %i", total);

}