#include <stdio.h>
#include <stdlib.h>
#include "queue_tree_node.c"

// typedef struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// } TreeNode;

TreeNode* createTreeNode(int value) {
    TreeNode* node=(TreeNode *) malloc(sizeof(TreeNode));
    node->val=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void dfs(TreeNode* node) {
    if (node==NULL)
        return;
    printf("%d", node->val);
    dfs(node->left);
    dfs(node->right);
    return;
}

int main (int argc, char *argv[]) {    
    FILE *fp;

    if (argc!=2) {
        printf("provide file name");
        return 0;
    }

    fp=fopen(argv[1], "r");

    if (!fp) {
        printf("Invalid file name!");
        return 0;
    }

    int x, n=1;
    Queue* q=createQueue();
    fscanf(fp, "%d", &x);
    TreeNode* root=createTreeNode(x);
    enqueue(root, q);

    while (!isEmpty(q)) {
        TreeNode* node=dequeue(q);

        for (int i=0; i<2; i++) {
            if(fscanf(fp, "%d ", &x)) {
                printf("%d", x);
                TreeNode* leftNode=createTreeNode(x);
                node->left=leftNode;
                enqueue(leftNode, q);
            } else {
                break;
            }

            if(fscanf(fp, "%d ", &x)) {
                printf("%d", x);
                TreeNode* rightNode=createTreeNode(x);
                node->right=rightNode;
                enqueue(rightNode, q);
            } else {
                break;
            }
        }

        if (feof(fp))
            break;
    }

    // dfs(root);
}