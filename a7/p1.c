#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../a6/quicksort.c"

void linearSearch(int n, int *arr, int value) {
    int comparisons=0;

    for (int i=0; i<n; i++) {
        comparisons++;
        if (arr[i]==value) {
            printf("Linear Search: key=%d found with %d comparisons.\n", value, comparisons);
            return;
        }
    }
    printf("Linear Search: key=%d not found with %d comparisons\n", value, comparisons);
    return;
}

void binarySearch(int n, int *arr, int value) {
    int low=0, high=n-1, comparisons=0;

    while (low<=high) {
        int mid = low + (high-low)/2;

        if (comparisons++ && value>arr[mid]) {
            low = mid+1;
        } else if (comparisons++ && value<arr[mid]) {
            high = mid-1;
        } else {
            printf("Binary Search: key=%d found with %d comparisons.\n", value, comparisons);
            return;
        }
    }
    printf("Binary Search: key=%d not found with %d comparisons!\n", value, comparisons);
}

void compareAlgorithms (int n) {
    srand(time(NULL));
    int *arr=(int *)malloc(n*sizeof(int));
    int key=rand() % (100 - 0 + 1);
    
    printf("\nComparing Binary Search and Linear Search for n=%d and key=%d \n", n, key);
    
    printf("Array : ");
    for (int i=0; i<n; i++) {
        arr[i]=rand() % (100 - 0 + 1);
        printf("%d ", arr[i]);
    }
    printf("\n");

    linearSearch(n, arr, key);
    
    quickSort(arr, 0, n-1);
    binarySearch(n, arr, key);
}

int main () {
    compareAlgorithms(50);
}