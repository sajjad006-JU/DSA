#include "linkedlist.c"

int isConnected(int n, Node* adjList, int v1, int v2 ) {
    int visited[n];
    for (int i=0; i<n; i++)
        visited[i]=0;

    
}

int main () {
    int nodes=5;

    Node* adjList=(Node *)malloc(nodes*sizeof(Node));

    for (int i=0; i<nodes; i++) {
        Node* head=createLinkedList();
        adjList[i]=*head;

        print("enter the connections of node %d: ", i);
        int input=0;

        while (input!=-1) {
            scanf("%d", &input);
            insert(head, input);
        }
    }
    
    
}