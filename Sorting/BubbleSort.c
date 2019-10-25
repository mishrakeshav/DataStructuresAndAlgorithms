#include<stdio.h>
#define MAX 100

int main(){
    int a[MAX], i, j, n, flag, swap;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    while(1){

        flag = 0;
        for(i=0; i<n-1; i++){

            if(a[i]>a[i+1]){
                swap = a[i];
                a[i] = a[i+1];
                a[i+1] = swap;
                flag = 1;
            }
        }

        if(flag==0){
            break;
        }
    }
    printf("\nSorted array\n");
    for(i=0; i<n; i++){
        printf("%d\n", a[i]);
    }

}
