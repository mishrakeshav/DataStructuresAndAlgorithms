#include<stdio.h>
#define MAX 100
void insertionSort(int [], int );

int main(){
    int a[MAX];
    int i, n;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    insertionSort(a,n);

    printf("\nSorted array\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}

void insertionSort(int a[], int n){
    int i, v, j;
    for(i=0; i<n; i++){
        v = a[i];
        j = i - 1;
        while(j>=0 && a[j] > v){
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = v;
    }
}