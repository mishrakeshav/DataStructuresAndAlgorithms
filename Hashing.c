#include<stdio.h>
#include<stdlib.h>

#define mod 10

int hash[mod];

int getKey(data){
    return data%mod;
}

void insert(int data){
    int index = getKey(data);
    if(hash[index]==-1){
        hash[index] = data;
        return;
    }
    int i = index;
    while(i<mod){
        if(hash[i]==-1){
            hash[i] = data;
            return;
        }
        i++;
    }
    printf("\nOverflow");

}
void traverse(){
    int i;
    for(i=0; i<mod; i++){
        if(hash[i]==-1){
            printf("NULL ");
        }
        else{
            printf("%d ", hash[i]);
        }
    }
}
void Contains(int data){
    int i = getKey(data);

    if(hash[i]==data){
        printf("\nTrue");
        return;
    }
    while(i<mod){
        if(hash[i]==data){
            printf("\nTrue");
            return;
        }
        i++;
    }
    if(i==mod){
        printf("\nFalse");
    }
}
int main(){
    int i;
    for(i=0; i<mod; i++){
        hash[i] = -1;
    }
    int ch, data;
    do{
        printf("\n***MENU***");
        printf("\n1. insert");
        printf("\n2. Contains?");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\nEnter value : ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("\nEnter value to check if it is in the array: ");
                scanf("%d", &data);
                Contains(data);
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("\nBye");
                break;
            default:
                printf("\nInvalid choice!!");
                break;
        }
    }while(ch!=4);
    return 0;
}




