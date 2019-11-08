#include<stdio.h>
#define MAX 100
void shellSort(int a[], int n);
int main(){
    int a[MAX], i, j, n, flag, swap;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    shellSort(a,n);
    printf("\nSorted array\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

}
void shellSort(int a[], int n){
    int i, j, key;
    int gap = n/2;

    while(gap>0){
        for(i=gap;i<n;i++){
            key = a[i];
            j = i;
            while(j>=gap && a[i-gap] > key){
                a[j] = a[j-gap];
                j = j - gap;
            }
            a[j] = key;
        }
        gap = gap/2;
    }
}

