#include <stdio.h>

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

int main() {
    int n=5;
    int arr[5]={7, 12, 9, 11, 3};

    selectionSort(arr, n);

    printf("sorted array : ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}