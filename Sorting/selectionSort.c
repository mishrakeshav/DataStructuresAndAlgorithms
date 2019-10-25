#include<stdio.h>
#define MAX 100
void selectionSort(int [], int);


int main(){
    int i,n,a[MAX];
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    selectionSort(a,n);

    printf("\nSorted array: \n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}

void selectionSort(int a[], int n){

    int min = -1, i, j, swap;

    for(i = 0; i<=n-2; i++){
        min = i;
        for(j = i + 1; j<= n-1; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }

        if(min!=i){
            swap = a[i];
            a[i] = a[min];
            a[min] = swap;
        }

    }
}