#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int recursiveBinarySearch(char *array[], char *elementoProcurado, int inicio, int fim) {
    int meio = (fim + inicio) / 2;

    int comparar = strcmp(elementoProcurado, array[meio]);

    if (comparar == 0) {
        return meio;
    } else if (comparar > 0) {
        inicio = meio + 1;
    }
    else {
        fim = meio - 1;
    }
    return recursiveBinarySearch(array, elementoProcurado, inicio, fim );
}

int main() {
    char *array[100] = {"Alice", "Amelia", "Anastasia", "Angelica", "Ariana", "Aurora", "Beatriz", "Bianca", "Bruna", "Camila", "Carla", "Carolina", "Catarina", "Cecilia", "Clarice", "Claudia", "Dalila", "Daniela", "Denise", "Diana", "Eduarda", "Elena", "Elisabete", "Elisangela", "Elisete", "Eloisa", "Elsa", "Elvira", "Emilia", "Erika", "Esmeralda", "Estela", "Esther", "Fabiana", "Fernanda", "Flavia", "Gabriela", "Geovana", "Giovanna", "Giselle", "Gloria", "Guilhermina", "Helena", "Hortencia", "Ines", "Irene", "Isabel", "Isabela", "Isadora", "Jacqueline", "Janaina", "Jessica", "Joana", "Josefina", "Julia", "Juliana", "Jussara", "Karen", "Karina", "Katarina", "Katia", "Lais", "Lara", "Larissa", "Laura", "Leila", "Leticia", "Lia", "Liliana", "Lorena", "Lorraine", "Lourdes", "Luana", "Lucia", "Luciana", "Luiza", "Luna", "Maira", "Manuela", "Mara", "Marcia", "Mariana", "Marina", "Marisa", "Marta", "Maya", "Melissa", "Mercedes", "Milena", "Miriam", "Monica", "Nadia", "Naiara", "Natalia", "Nayara", "Neusa", "Nicole", "Nina", "Noemi", "Olga", "Patricia", "Paula", "Paulina", "Perla", "Priscila", "Raissa", "Rebeca", "Regina", "Renata", "Roberta", "Rosa", "Rosana", "Rose", "Roseli", "Rosilene", "Sabrina", "Samanta", "Samantha", "Sandra", "Sara", "Sarah", "Selma", "Silvana", "Silvia", "Simone", "Sofia", "Solange", "Sonia", "Sophia", "Stella", "Suely", "Tais", "Tania", "Tatiana", "Thais", "Thalita", "Tiffany", "Tulio", "Valeria", "Vanessa", "Vera", "Veronica", "Victoria", "Viviane", "Yara", "Yasmin", "Yeda", "Yolanda", "Zelia", "Zilda"};

    char *procurado = "Beatriz";

    int inicio = 0;
    int fim = sizeof(array)/sizeof(array[0]);

    int indiceDoProcurado = recursiveBinarySearch(array, procurado, inicio, fim);

    printf("elemento procurado encontra-se no indice %i", indiceDoProcurado);
}