/*
    -Código do quicksort selecionado para ser transformado em Assembly Mips
    -Nele, definimos o pivô como ultimo elemento e definimos um array a ser ordenado (afim de facilidar a implementação em mips).
    -O array está definido como o pior caso do quicksort ()
*/

#include <stdio.h>


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printarrayay(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/**
 * reorganiza os elementos de acordo com o valor do pivô
*/
int partition(int array[], int low, int high) {
    int pivot = array[high]; // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do elemento menor que o pivô

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (array[j] <= pivot) {
            i++; // Incrementa o índice do elemento menor
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}


/**
 * Função recursiva que vai separando o array em subpartes e vai as organizando
 * com a função "partition"
*/
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Encontra o índice do pivô
        int pi = partition(array, low, high);

        // Ordena as duas subpartes
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

/**
 * Inicia o array a ser ordenado, pega o seu tamanho e
 * realiza a chamada do quicksort
*/
int main() {
    int array[] = {22, 15, 12, 8, 7, 6, 4, 1, 14, 3, 25, 11};
    int n = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, n - 1);
    printf("array ordenado: \n");
    printarrayay(array, n);
    return 0;
} 
