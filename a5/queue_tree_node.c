#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


// creating a node structure
typedef struct Node {
    TreeNode* data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// function to create a node
Node* createNode(TreeNode* data) {
    Node* newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* q=(Queue *) malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void enqueue(TreeNode* data, Queue* queue) {
    struct Node* newNode=createNode(data);

    if (queue->front==NULL) {
        queue->front=newNode;
        queue->rear=newNode;
        return;
    } 
    queue->rear->next=newNode;
    queue->rear=newNode;
    // newNode->next=*rear;
    return;
}

TreeNode* dequeue(Queue* q) {
    if (q->front==NULL) {
        return NULL;
    }
    TreeNode* x=q->front->data;
    q->front=q->front->next;
    return x;
}

TreeNode* peek(Queue* q) {
    if (q->front==NULL) {
        return NULL;
    }
    return q->front->data;
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