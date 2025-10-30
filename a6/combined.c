#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {

    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int maxi=0;
        for (int j=0; j<n-i; j++) {
            if (arr[j]>arr[maxi]) {
                maxi=j;
            }
        }
        int temp=arr[n-i-1];
        arr[n-i-1]=arr[maxi];
        arr[maxi]=temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int key=arr[i];
        int j=i-1;

        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        } 
        arr[j+1]=key;
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d\n", arr[i]);
    }
}

int main () {
    srand(42);
    clock_t start, end;
    double time_taken;

    int n=150000;
    int arr[n];

    for (int i=0; i<n; i++) {
        // arr[i]=rand();
        arr[i]=i;
    }

    start = clock();
    selectionSort(arr, n);
    // quickSort(arr, 0, n-1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printArray(arr, n);
    printf("Time taken: %f seconds", time_taken);
}