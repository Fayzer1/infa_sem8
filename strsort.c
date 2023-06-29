#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// функция для обмена двух строк
void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// функция для разделения массива и определения опорного элемента
int partition(char** arr, int low, int high) {
    char* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strlen(arr[j]) <= strlen(pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// функция быстрой сортировки
void quickSort(char** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// функция для сортировки массива строк по их длине с использованием сортировки Шелла
void shellSort(char** arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char* temp = arr[i];
            int j;
            for (j = i; j >= gap && strlen(arr[j - gap]) > strlen(temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    printf("Введите количество строк в массиве: ");
    scanf("%d", &n);

    char** arr = (char**)malloc(n * sizeof(char*));

    printf("Введите строки:\n");
    for (int i = 0; i < n; i++) {
        char input[100];
        scanf("%s", input);
        arr[i] = (char*)malloc((strlen(input) + 1) * sizeof(char));
        strcpy(arr[i], input);
    }

    // Используем быструю сортировку
    // quickSort(arr, 0, n - 1);

    // Используем сортировку Шелла
    shellSort(arr, n);

    printf("Отсортированный массив строк:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
        free(arr[i]);
    }
    free(arr);

    return 0;
}
