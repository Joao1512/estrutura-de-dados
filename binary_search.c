#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int TAMANHO = 100;

//retorna o índice do elemento buscado. Caso não ache, retorna -1.
int binary_search(char *elementoProcurado,  char *array[]) {

    int inicio = 0;
    int fim = TAMANHO;
    int meio = TAMANHO / 2;
    int count = 0;
    while (inicio <= fim) {
        int comparar = strcmp(elementoProcurado, array[meio]);
        if (comparar == 0) {
            printf("numero de passos: %i. \n", count);
            return meio;
        }
        else if (comparar > 0) {
            inicio = meio + 1;
        }
        else if (comparar < 0) {
            fim = meio - 1;
        }
        meio = (fim + inicio) / 2;
        count++;
    }
    printf("elemento nao encontrado. \n");
    return -1;
}

int main() {
    char *array[100] = {"Alice", "Amelia", "Anastasia", "Angelica", "Ariana", "Aurora", "Beatriz", "Bianca", "Bruna", "Camila", "Carla", "Carolina", "Catarina", "Cecilia", "Clarice", "Claudia", "Dalila", "Daniela", "Denise", "Diana", "Eduarda", "Elena", "Elisabete", "Elisangela", "Elisete", "Eloisa", "Elsa", "Elvira", "Emilia", "Erika", "Esmeralda", "Estela", "Esther", "Fabiana", "Fernanda", "Flavia", "Gabriela", "Geovana", "Giovanna", "Giselle", "Gloria", "Guilhermina", "Helena", "Hortencia", "Ines", "Irene", "Isabel", "Isabela", "Isadora", "Jacqueline", "Janaina", "Jessica", "Joana", "Josefina", "Julia", "Juliana", "Jussara", "Karen", "Karina", "Katarina", "Katia", "Lais", "Lara", "Larissa", "Laura", "Leila", "Leticia", "Lia", "Liliana", "Lorena", "Lorraine", "Lourdes", "Luana", "Lucia", "Luciana", "Luiza", "Luna", "Maira", "Manuela", "Mara", "Marcia", "Mariana", "Marina", "Marisa", "Marta", "Maya", "Melissa", "Mercedes", "Milena", "Miriam", "Monica", "Nadia", "Naiara", "Natalia", "Nayara", "Neusa", "Nicole", "Nina", "Noemi", "Olga", "Patricia", "Paula", "Paulina", "Perla", "Priscila", "Raissa", "Rebeca", "Regina", "Renata", "Roberta", "Rosa", "Rosana", "Rose", "Roseli", "Rosilene", "Sabrina", "Samanta", "Samantha", "Sandra", "Sara", "Sarah", "Selma", "Silvana", "Silvia", "Simone", "Sofia", "Solange", "Sonia", "Sophia", "Stella", "Suely", "Tais", "Tania", "Tatiana", "Thais", "Thalita", "Tiffany", "Tulio", "Valeria", "Vanessa", "Vera", "Veronica", "Victoria", "Viviane", "Yara", "Yasmin", "Yeda", "Yolanda", "Zelia", "Zilda"};

    char *procurado = "Beatriz";

    int indiceDoProcurado = binary_search(procurado, array);

    printf("indice: %i", indiceDoProcurado);

}
