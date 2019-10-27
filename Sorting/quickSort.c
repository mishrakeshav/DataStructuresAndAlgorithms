#include<stdio.h>
#include<stdlib.h>
#define Max 100
void quickSort(int [], int, int);
int partition(int [], int, int);

int main(){
    int a[Max];
    int i, n;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    quickSort(a,0,n-1);

    printf("\nSorted array\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
int partition(int a[], int start,int end){
    int pivot = a[start];
    int i, j, swap;
    i = start + 1;
    j = end - 1;

    while(1){
        while(i<=j && a[i]<=pivot){
            i++;
        }
        while(i<=j && a[j]>=pivot){
            j--;
        }

        if(i<=j){
            swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
        else{
            swap = a[start];
            a[start] = a[j];
            a[j] = swap;
            return j;
        }
    }
}
void quickSort(int a[], int start, int end){
    int p;
    if(end-start>1){
        p = partition(a,start,end);
        quickSort(a,start,p);
        quickSort(a,p+1,end);
    }
}
