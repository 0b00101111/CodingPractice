#include <stdlib.h>

typedef struct dynamic_array {
    int *data;
    int size;
    int capacity;
} array_t;

// Implement:
array_t *create_array(int initial_capacity) {
    if (initial_capacity <= 0) {
        return NULL;
    }
    array_t *new_array = (array_t *)malloc(sizeof(array_t));
    if (new_array == NULL) {
        return NULL;
    }

    int *new_data = (int *)malloc(initial_capacity * sizeof(int));
    if (new_data == NULL) {
        free(new_array);
        return NULL;
    }

    new_array->data = new_data;
    new_array->size = 0;
    new_array->capacity = initial_capacity;
    
    return new_array;
}

int insert(array_t *arr, int value) {
    if (arr->size >= arr->capacity) {
        int new_capacity = arr->capacity * 2;
        int *new_data = (int *)malloc(new_capacity * sizeof(int));
        if (new_data == NULL) {
            return -1;
        }

        for (int i = 0; i < arr->size; i++) {
            new_data[i] = arr->data[i];
        }

        free(arr->data);
        arr->data = new_data;
        arr->capacity = new_capacity;
    }

    arr->data[arr->size] = value;
    arr->size++;

    return 0;
}     // Resize if full


void free_array(array_t *arr) {
    free(arr->data);
    free(arr);
}    // Clean deletion


