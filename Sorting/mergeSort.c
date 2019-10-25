#include<stdio.h>
#define Max 100
void mergeSort(int [], int, int); 
void merge(int [], int ,int ,int);

int main(){
    int a[Max];
    int i, n;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a,0,n-1);

    printf("\nSorted array\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}

void mergeSort(int a[], int p, int r){
    int q;
    if(p<r){
        q = (p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}

void merge(int a[], int p, int q, int r){
    int i, j, k, k1;
    k = p;
    i = p;
    j = q + 1;
    int temp[Max];
    while((i<=q) && (j<=r)){
        if(a[i] <= a[j]){
            temp[k] = a[i];
            i++;
        }
        else{
            temp[k] = a[j];
            j++;
        }
        k++;       
    }

    if(i>q){
        for(k1=j; k1 <= r; k1++){
            temp[k] = a[k1];
            k++;
        }
    }
    else{
        for(k1=i; k1<=q; k1++){
            temp[k] = a[k1];
            k++;
        }
    }

    for(k = p; k<=r; k++){
        a[k] = temp[k];
    }
}