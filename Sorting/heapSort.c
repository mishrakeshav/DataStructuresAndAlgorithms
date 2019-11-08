#include<stdio.h>
#define MAX 100
void buildheap(int a[], int n);
void heapify(int a[], int i, int n);
void heapSort(int a[], int n);
int main(){
    int a[MAX], i,n, flag, swap;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    heapSort(a,n);
    printf("\nSorted array\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

}

void heapify(int a[], int i, int n){
    int l, r, largest, swap;
    l = 2*i + 1;
    r = 2*i + 2;
    //take largest as the root node
    largest = i;

    if(l< n && a[l] > a[largest]){
        largest = l;
    }
        
    if(r< n && a[r] > a[largest]){
        largest = r;
    }
    if(largest!=i){
        swap = a[i];
        a[i] = a[largest];
        a[largest] = swap;
        heapify(a,largest,n);
    }
}
void buildheap(int a[], int n){
    int i;

    for(i=n/2 - 1;i>=0;i--){
        heapify(a,i,n);
    }
}

void heapSort(int a[], int n){
    buildheap(a,n);
    int i, swap;
    for(i=n-1;i>=0;i--){
        swap = a[i];
        a[i] = a[0];
        a[0] = swap;

        heapify(a,0,i);
    }
}

