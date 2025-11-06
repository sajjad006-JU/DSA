#include <stdio.h>

int swaps=0;

void heapify(int arr[], int n, int i) {
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if (left<n && arr[left]<arr[smallest])
        smallest=left;
    
    if (right<n && arr[right]<arr[smallest])
        smallest=right;
    
    if (smallest!=i) {
        int temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
        swaps++;
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i=n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }
} 

int main () {
    int n=10;
    int arr[] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};

    buildMinHeap(arr, n);

    printf("Heap Sorted Array : \n");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);        
    }

    printf("\nSwaps: %d ", swaps);
}