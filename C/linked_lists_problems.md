# 1. Basic Node Creation and Memory Management

```C
// Implement a function that creates a new node with given data
// and a function that safely frees a node
node_t *create_node(int data);
void free_node(node_t *node);
```

# 2. Simple Linked List Operations

```C
typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    int size;
} list_t;

// Implement:
list_t *create_list();              // Creates empty list
void insert_front(list_t *list, int data);   // Inserts at beginning
void free_list(list_t *list);       // Frees all nodes and list

```

# 3. Insert at Position

```C
// Add these functions to your list implementation:
// Insert at given position (0-based index)
// Return 0 for success, -1 for invalid position
int insert_at_position(list_t *list, int data, int position);

// Insert in sorted order (assume list is sorted)
void insert_sorted(list_t *list, int data);
```

# 4. List Manipulation

```C
// Implement a function that:
// 1. Creates a copy of a list
// 2. Reverses the copy
// 3. Returns the reversed copy
// Original list should remain unchanged
list_t *create_reversed_copy(list_t *list);
```

# 5. Circular List with Tail

```C
typedef struct circular_list {
    node_t *head;
    node_t *tail;
    int size;
} circular_list_t;

// Implement:
circular_list_t *create_circular_list();
void insert_end(circular_list_t *list, int data);  // Insert at end
void delete_front(circular_list_t *list);          // Delete from front
void free_circular_list(circular_list_t *list);    // Free entire list
```
