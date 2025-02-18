// 1. Basic Node Creation and Memory Management``
// Implement a function that creates a new node with given data
// and a function that safely frees a node
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void free_node(node_t *node) {
    free(node);
}

// 2. Simple Linked List Operations
// node_t type defined in problem 1

typedef struct list {
    node_t *head;
    int size;
} list_t;

// Implement:
list_t *create_list() {
    list_t *newList = (list_t *)malloc(sizeof(list_t));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}              // Creates empty list


void insert_front(list_t *list, int data) {
    node_t *newNode = create_node(data);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}   // Inserts at beginning


void free_list(list_t *list) {
    if (list == NULL) {
        return;
    }
    
    if (list->head == NULL) {
        return;
    }
    node_t *currentNode = list->head;
    while (currentNode != NULL) {
        node_t *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(list);
}       // Frees all nodes and list


// 3. Insert at Position

// Add these functions to your list implementation:
// Insert at given position (0-based index)
// Return 0 for success, -1 for invalid position
int insert_at_position(list_t *list, int data, int position)  {
    if (position < 0 || position > list->size) {
        return -1;
    }
    
    node_t *newNode = create_node(data);
    if (newNode == NULL) {
        return -1;
    }
    // traverse to the node before the position
    node_t *currentNode = list->head;
    for (int i = 0; i < position - 1; i++) {
        currentNode = currentNode->next;
    }

    // insert the node
    node_t *nextNode = currentNode->next;
    currentNode->next = newNode;
    newNode->next = nextNode;

    return 0;
}

// Insert in sorted order (assume list is sorted)
void insert_sorted(list_t *list, int data) {
    node_t *currentNode = list->head;
    node_t *newNode = create_node(data);

    if (list->head == NULL || data <= list->head->data) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        return;
    }

    
    while (currentNode->next != NULL && currentNode->next->data < data) {
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    list->size++;
}


// 4. List Manipulation

// Implement a function that:
// 1. Creates a copy of a list
// 2. Reverses the copy
// 3. Returns the reversed copy
// Original list should remain unchanged
list_t *create_reversed_copy(list_t *list) {  
    list_t *newList = create_list();
    node_t *currentNode = list->head;

    for (int i = 0; i < list->size; i++) {
        insert_front(newList, currentNode->data);
        currentNode = currentNode->next;
    }
    return newList;
}


// 5. Circular List with Tail


typedef struct circular_list {
    node_t *head;
    node_t *tail;
    int size;
} circular_list_t;

// Implement:
circular_list_t *create_circular_list() {
    circular_list_t *newCL = (circular_list_t *)malloc(sizeof(circular_list_t));
    newCL->head = NULL;
    newCL->tail = NULL;
    newCL->size = 0;
    return newCL;
}


void insert_end(circular_list_t *list, int data) {
    node_t *newNode = create_node(data);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = list->head;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}  // Insert at end


void delete_front(circular_list_t *list) {
    if (list->head == NULL) {
        return;
    }

    if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        node_t *front = list->head;
        list->head = list->head->next;
        list->tail->next = list->head;
        free(front);
    }
    list->size--;
}         // Delete from front


void free_circular_list(circular_list_t *list) {
    while (list->head != list->tail) {
        node_t *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}    // Free entire list



// Tests


void print_list(list_t *list) {
    if (list == NULL) {
        printf("List is NULL!\n");
        return;
    }
    if (list->head == NULL) {
        printf("Empty list\n");
        return;
    }

    node_t *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Test 1: Create and free single node
    printf("\nTest 1: Single node operations\n");
    node_t *single_node = create_node(5);
    assert(single_node->data == 5);
    assert(single_node->next == NULL);
    free_node(single_node);

    // Test 2: Create empty list
    printf("\nTest 2: Empty list operations\n");
    list_t *list = create_list();
    assert(list != NULL);
    assert(list->head == NULL);
    assert(list->size == 0);
    print_list(list);

    // Test 3: Insert front
    printf("\nTest 3: Insert front operations\n");
    insert_front(list, 1);
    insert_front(list, 2);
    insert_front(list, 3);
    assert(list->size == 3);
    assert(list->head->data == 3);
    print_list(list);

    // Test 4: Insert at position
    printf("\nTest 4: Insert at position operations\n");
    // Test invalid positions
    assert(insert_at_position(list, 10, -1) == -1);  // Invalid position
    assert(insert_at_position(list, 10, 4) == -1);   // Invalid position
    // Test valid positions
    assert(insert_at_position(list, 4, 0) == 0);     // Insert at front
    assert(insert_at_position(list, 5, 2) == 0);     // Insert in middle
    assert(insert_at_position(list, 6, list->size) == 0); // Insert at end
    print_list(list);

    // Test 5: Insert sorted
    printf("\nTest 5: Insert sorted operations\n");
    list_t *sorted_list = create_list();
    insert_sorted(sorted_list, 3);
    insert_sorted(sorted_list, 1);
    insert_sorted(sorted_list, 4);
    insert_sorted(sorted_list, 2);
    print_list(sorted_list);

    // Test 6: Create reversed copy
    printf("\nTest 6: Reverse copy operations\n");
    list_t *reversed = create_reversed_copy(sorted_list);
    print_list(sorted_list);   // Original list
    print_list(reversed);      // Reversed copy

    // Test 7: Circular list
    printf("\nTest 7: Circular list operations\n");
    circular_list_t *clist = create_circular_list();
    assert(clist != NULL);
    assert(clist->head == NULL);
    assert(clist->tail == NULL);
    assert(clist->size == 0);

    // Insert into circular list
    insert_end(clist, 1);
    insert_end(clist, 2);
    insert_end(clist, 3);
    assert(clist->size == 3);
    assert(clist->tail->next == clist->head);  // Check circular property

    // Delete from circular list
    delete_front(clist);
    assert(clist->size == 2);
    assert(clist->tail->next == clist->head);  // Check circular property maintained

    // Clean up
    free_list(list);
    free_list(sorted_list);
    free_list(reversed);
    free_circular_list(clist);

    printf("\nAll tests passed!\n");
    return 0;
}
