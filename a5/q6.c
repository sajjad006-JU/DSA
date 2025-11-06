#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (!q->rear) q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    Node* node = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void heapifyUp(Node* node) {
    while (node->parent && node->data > node->parent->data) {
        swap(node, node->parent);
        node = node->parent;
    }
}

Node* insert(Node* root, int data) {
    Node* newNode = createNode(data);

    if (root == NULL)
        return newNode;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* temp = dequeue(q);

        if (temp->left == NULL) {
            temp->left = newNode;
            newNode->parent = temp;
            break;
        } else enqueue(q, temp->left);

        if (temp->right == NULL) {
            temp->right = newNode;
            newNode->parent = temp;
            break;
        } else enqueue(q, temp->right);
    }

    heapifyUp(newNode);
    return root;
}

Node* getLastNode(Node* root) {
    Queue* q = createQueue();
    enqueue(q, root);
    Node* temp = NULL;

    while (!isEmpty(q)) {
        temp = dequeue(q);
        if (temp->left) enqueue(q, temp->left);
        if (temp->right) enqueue(q, temp->right);
    }
    return temp;
}

void heapifyDown(Node* node) {
    while (node) {
        Node* largest = node;
        if (node->left && node->left->data > largest->data)
            largest = node->left;
        if (node->right && node->right->data > largest->data)
            largest = node->right;

        if (largest == node)
            break;

        swap(node, largest);
        node = largest;
    }
}

Node* deleteRoot(Node* root) {
    if (root == NULL)
        return NULL;

    Node* last = getLastNode(root);

    if (last == root) {
        free(root);
        return NULL;
    }

    root->data = last->data;

    if (last->parent->right == last)
        last->parent->right = NULL;
    else
        last->parent->left = NULL;

    free(last);

    heapifyDown(root);
    return root;
}

void printLevelOrder(Node* root) {
    if (root == NULL) return;
    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* temp = dequeue(q);
        printf("%d ", temp->data);
        if (temp->left) enqueue(q, temp->left);
        if (temp->right) enqueue(q, temp->right);
    }
    printf("\n");
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 15);

    printf("Heap after insertions (level order): ");
    printLevelOrder(root);

    root = deleteRoot(root);
    printf("Heap after deleting root: ");
    printLevelOrder(root);

    return 0;
}
