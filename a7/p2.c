#include <stdio.h>
#include <stdlib.h>

// creating a node structure
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int data, int priority) {
    Node* newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->priority=priority;
    newNode->next=NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* q=(Queue *) malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void enqueue(int value, int priority, Queue* queue) {
    struct Node* newNode=createNode(value, priority);

    if (queue->front==NULL || priority < queue->front->priority) {
        newNode->next=queue->front;
        queue->front=newNode;
        return;
    } 
    
    Node* temp=queue->front;

    while (temp->next!=NULL && temp->next->priority<=priority) {
        temp=temp->next;
    }

    newNode->next=temp->next;
    temp->next=newNode;

    return;
}

Node* dequeue(Queue* q) {
    if (q->front==NULL) {
        return NULL;
    }
    Node* x=q->front;
    q->front=q->front->next;
    return x;
}

Node* peek(Queue* q) {
    if (q->front==NULL) {
        return NULL;
    }
    return q->front;
}

int isEmpty(Queue* q) {
    if (q->front==NULL)
        return 1;
    else
        return 0;
} 

int size(Queue* q) {
    Node* temp=q->front;
    int size=0;

    if (temp==NULL)
        return 0;

    while (temp!=q->rear) {
        size++;
        temp=temp->next;
    }
    return size+1;
}

int main () {
    Queue* q=createQueue();

    enqueue(2, 2, q);
    enqueue(3, 6, q);
    enqueue(1, 0, q);
    enqueue(5, 3, q);
    enqueue(7, 0, q);


    for (int i=0; i<5; i++) {
        Node* node=dequeue(q);
        printf("Data = %d Priority = %d\n", node->data, node->priority);
    }
}