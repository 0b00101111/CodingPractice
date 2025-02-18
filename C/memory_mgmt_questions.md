# Memory Management Practice Problems

## 1. Dynamic Array Implementation

```c
typedef struct dynamic_array {
    int *data;
    int size;
    int capacity;
} array_t;

// Implement:
array_t *create_array(int initial_capacity);
int insert(array_t *arr, int value);      // Resize if full
void free_array(array_t *arr);            // Clean deletion
```


## 2. String Buffer Management

```c
typedef struct string_buffer {
    char *buffer;
    int length;
    int capacity;
} buffer_t;

// Implement:
buffer_t *create_buffer(int initial_size);
int append(buffer_t *buf, const char *str);  // With reallocation
void clear_buffer(buffer_t *buf);            // Reset without freeing
void free_buffer(buffer_t *buf);             // Complete cleanup
```


## 3. Matrix Operations with Memory Management

```c
typedef struct matrix {
    int **data;
    int rows;
    int cols;
} matrix_t;

// Implement:
matrix_t *create_matrix(int rows, int cols);
matrix_t *matrix_multiply(matrix_t *m1, matrix_t *m2);  // Returns new matrix
void free_matrix(matrix_t *m);                          // Free all levels
```
