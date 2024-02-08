#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node* next;
} node_t;

node_t* push(node_t* top, int data)
{
    node_t* ptr = malloc(sizeof(node_t));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

node_t* pop(node_t* top)
{   
    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    node_t* ptr = top->next;
    free(top);
    return ptr;
}

void lookup(node_t* top)
{   
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack:\n");
    const node_t* current = top;
    while(current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int peek(node_t* top)
{   
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    return top->data;
}

int main(void)
{   
    node_t* top = NULL;
    int query;
    int n;
    while(1) 
    {
        printf("\nPrint 1 to push, 2 to pop, 3 to print the whole stack, 4 to peek, 5 to exit\n");
        scanf("%d", &query);
        if (query == 1) {
            printf("to push: ");
            scanf("%d", &n);
            top = push(top, n);
        } else if (query == 2) {
            top = pop(top);
        } else if (query == 3) {
            lookup(top);
        } else if (query == 4) {
            printf("First element: %d", peek(top));
        } else {
            break;
        }
    }

    return 0;
}