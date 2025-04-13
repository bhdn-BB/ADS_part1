#include <stdbool.h>
#include <stdio.h>

int binarySearch(const char mas[], const int size, const int key);

void linearSearch(const int size, const char *arr, const char target);

void generate_first_array(char *arr, const int size);

void generate_second_array(char *arr, const int size);

void print_array(const char *arr, const int size);

int merge(const char *a, const char *b, char *out, const int size);

int main() {
    const int size = 10;
    char a[size];
    char b[size];

    generate_first_array(a, size);
    generate_second_array(b, size);

    printf("First array (55 - 2 * i):\n");
    print_array(a, size);

    printf("Second array (40 + 3 * i):\n");
    print_array(b, size);

    char c[size];

    const int merged_array_size = merge(a, b, c, size);

    printf("Merged array:\n");
    print_array(c, merged_array_size);

    printf("Minimal number %d\n", c[0]);

    printf("Enter P:");
    int P = 0;
    scanf("%d", &P);


    printf("numbers > P:");
    linearSearch(merged_array_size, c, P);

    return 0;
}

int binarySearch(const char mas[], const int size, const int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        const int mid = (right + left) / 2;
        if (mas[mid] == key) return mid;
        if (mas[mid] > key) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

void linearSearch(const int size, const char *arr, const char target) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (arr[i] > target) {
            found = true;
            printf("%d ",arr[i]);
        }
    }

    if (!found) {
        printf("Not Found\n");
    }
}

void generate_first_array(char *arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 55 - 2 * i;
    }
}

void generate_second_array(char *arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 40 + 3 * i;
    }
}

void print_array(const char *arr, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int merge(const char *a, const char *b, char *out, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        const int result = binarySearch(a, size, b[i]);
        if (result != -1) {
            out[count] = a[result];
            count++;
        }
    }

    return count;
}