#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node* next;
} node_t;

typedef struct 
{
    node_t *head, *tail;
} queue;

void init_queue(queue* q) 
{
    q->head = NULL;
    q->tail = NULL;
}

node_t* init_node(void) 
{
    node_t* ptr = malloc(sizeof(node_t));
    ptr->data = 0;
    ptr->next = NULL;
    return ptr;
}

void push_back(queue* q, int data) 
{
    if (q->head == NULL && q->tail == NULL) {
        q->head = init_node();
        q->head->data = data;
        q->tail = q->head;
    } else {  
        q->tail->next = init_node();
        q->tail->next->data = data;
        q->tail = q->tail->next;
    }
}

void pop_front(queue* q) 
{
    if (q->head == NULL) {
        printf("Queue is empty\n");
        return;
    } else {
        node_t* temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
}

void print_queue(queue* q) 
{   
    if (q->head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    const node_t* current = q->head;
    while(current) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(void) 
{
    queue QUEUE;
    int query;
    int n;
    init_queue(&QUEUE);
    while(1) 
    {
        printf("\nPrint 1 to push, 2 to pop, 3 to print the whole queue, 4 to exit\n");
        scanf("%d", &query);
        if (query == 1) {
            printf("to push: ");
            scanf("%d", &n);
            push_back(&QUEUE, n);
        } else if (query == 2) {
            pop_front(&QUEUE);
        } else if (query == 3) {
            print_queue(&QUEUE);
        } else {
            break;
        }
    }
    
    return 0;
}
