// Write a function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Calculate sum of array elements using pointer arithmetic
int arraySum_a(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Calculate sum of array elements using pointer arithmetic
int arraySum_b(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *arr;
        arr++;
    }
    return sum;
}

// Calculate sum of array elements using pointer arithmetic
int arraySum_c(int *arr, int size) {
    int sum = 0;
    int *end = arr + size;
    while (arr < end) {
        sum += *arr++;
    }
    return sum;
}

// Implement strlen() using pointers
int myStrlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int myStrlen_a(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// Find middle element of array using pointers
// For odd length, return middle
// For even length, return first of middle two
int findMiddle(int *arr, int size) {
    if (size % 2 == 0) {
        return *(arr + (size/2 -1));
    } else {
        return *(arr +size/2);
    }
}

// Reverse array elements using only pointer arithmetic
void reverseArray_a(int *arr, int size) {
    for (int i = 0; i < (size/2); i++) {
        swap(arr + i, arr + size - 1 - i);
    }
}

#include <stdlib.h>

// Calculate sum of each row in a matrix
// matrix is n×m, return array of n sums
int* rowSums_a(int **matrix, int n, int m) {
    int *s = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int sum =  0;
        for (int j = 0; j < m; j++ ){
            sum += matrix[i][j]; 
        }
        s[i] = sum;
    }
    return s;
}

int* rowSums_b(int **matrix, int n, int m) {
    int *sums = malloc(n * sizeof(int));
    int *row;

    for (int i = 0; i < n; i++) {
        row = *matrix++;
        sums[i] = 0;
        for (int j = 0; j < m; j++) {
            sums[i] += *row++;
        }
    }
    return sums;
}
