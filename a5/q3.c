#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    Node* node = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);

    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

void printPostorder(Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], preorder[n];
    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    int preIndex = 0;
    Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("Postorder traversal of reconstructed tree: ");
    printPostorder(root);
    printf("\n");

    return 0;
}