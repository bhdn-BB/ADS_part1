#include <stdbool.h>
#include <stdio.h>
#define ROWS 6
#define COLUMNS 4
void insertionSort(double arr[], double N);
bool set(const bool direction, double matrix[ROWS][COLUMNS], const int x, const int y, const double val);
void initMatrix(double matrix[ROWS][COLUMNS]);
void printArray(const double arr[], const int size);
void printMatrix(const double matrix[ROWS][COLUMNS]);

int main() {
    double matrix[ROWS][COLUMNS];
    initMatrix(matrix);
    printf("input matrix:\n");
    printMatrix(matrix);
    double arr[ROWS];
    for (int i = 0; i < ROWS; i++) {
        double sum = 0;
        for (int j = 0; j < COLUMNS; j++) {
            sum += matrix[i][j];
        }
        arr[i] = sum;
    }
    printf("array before sort:\n");
    printArray(arr, ROWS);
    insertionSort(arr, ROWS);
    printf("array after sort:\n");
    printArray(arr, ROWS);

    return 0;
}

void printMatrix(const double matrix[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%7.3lf\t\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printArray(const double arr[], const int size) {
    for (int i = 0; i < size; i++) {
        printf("%.3lf ", arr[i]);
    }
    printf("\n");
}

void initMatrix(double matrix[ROWS][COLUMNS]) {
    int val = 1;
    const int mid = ROWS / 2;
    bool direction = true;;
    for (int step = 0; mid + step < ROWS; step++) {
        for (int i = 0; i < COLUMNS; i++) {
            if (set(direction, matrix, i, mid + step, val)) val++;

            if (set(!direction, matrix, i, mid - step - 1, val)) val++;
        }
        direction = !direction;
    }
}

bool set(const bool direction, double matrix[ROWS][COLUMNS], const int x, const int y, const double val) {
    if (x >= COLUMNS || x < 0 || y >= ROWS || y < 0) return false;
    if (direction) {
        matrix[y][x] = val;
    }
    else {
        matrix[y][COLUMNS - 1 - x] = val;
    }
    return true;
}

void insertionSort(double arr[], double N) {
    for (int i = 1; i < N; i++) {
        const double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}