//C implementation of doubly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
}NODE;
NODE * start = NULL;
void insertBegin(int data){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nUnderflow");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(start==NULL){
        start = newnode;
        return;
    }
    newnode->next = start;
    start->prev = newnode;
    start = newnode;
}
void insertAfter(int data, int value){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nUnderflow");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(start==NULL){
        printf("\nValue not found");
    }
    NODE * temp = start;
    while(temp){
        if(temp->data==value){
            break;
        }
        temp = temp->next;
    }
    if(temp==NULL){
        printf("\nValue not found");
        return;
    }
    if(temp->next!=NULL){
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        return;
    }
    if(temp->next==NULL){
        temp->next = newnode;
        newnode->prev = temp;
        return;
    }

}
void insertEnd(int data){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nUnderflow");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(start==NULL){
        start = newnode;
        return;
    }
    NODE * temp;
    temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return;
}
void deleteBegin(){
    if(start==NULL){
        printf("\nList is empty");
        return;
    }
    NODE * trash;
    if(start->next==NULL){
        printf("\nvalue deleted is %d", start->data);
        trash = start;
        start = NULL;
        free(trash);
        return;
    }
    printf("\nValue deleted is %d", start->data);
    trash = start;
    start = start->next;
    start->prev = NULL;
    free(trash);
}
void deleteEnd(){
    if(start==NULL){
        printf("\nList is empty");
        return;
    }
    NODE * trash;
    if(start->next==NULL){
        printf("\nValue deleted is %d", start->data);
        trash = start;
        start = NULL;
        free(trash);
        return;
    }
    NODE * temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    trash = temp;
    printf("\nValue deleted is %d", temp->data);
    temp->prev->next = NULL;
    free(trash);
}
void deleteValue(int value){
    if(start==NULL){
        printf("\nValue not found");
        return;
    }
    NODE * trash;
    if(start->data == value){
        trash = start;
        start = start->next;
        start->prev = NULL;
        free(trash);
        return;
    }
    NODE * temp = start;
    while(temp!=NULL && temp->data !=value){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("\nValue not found");
        return;
    }
    trash = temp;
    temp->prev->next = temp->next;
    free(trash);
}
void traverse(){
    if(start==NULL){
        printf("\nList is empty");
        return;
    }
    NODE * temp = start;
    printf("\n");
    while(temp){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void contains(int data){
    if(start==NULL){
        printf("\nFalse");
        return;
    }
    if(start->data == data){
        printf("\nTrue");
        return;
    }
    NODE * temp = start;
    while(temp !=NULL){
        if(temp->data == data){
            printf("\nTrue");
            return;
        }
        temp = temp->next;
    }
    printf("\nFalse");
}
int main(){
    int ch,data,value;
    do{
        printf("\n\n***MENU***");
        printf("\n1. Insert at the Beginning");
        printf("\n2. Insert at the End");
        printf("\n3. Insert after a node");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from end");
        printf("\n6. Delete by value");
        printf("\n7. Traverse");
        printf("\n8. Contains?");
        printf("\n9. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value: ");
            scanf("%d", &data);
            insertBegin(data);
            break;
        case 2:
            printf("\nEnter value: ");
            scanf("%d", &data);
            insertEnd(data);
            break;
        case 3:
            printf("\nEnter value to insert: ");
            scanf("%d", &data);
            printf("\nEnter value after which you want to insert: ");
            scanf("%d", &value);
            insertAfter(data,value);
            break;
        case 4:
            deleteBegin();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("\nEnter value to delete: ");
            scanf("%d", &value);
            deleteValue(value);
            break;
        case 7:
            traverse();
            break;
        case 8:
            printf("\nEmter value to check: ");
            scanf("%d", &value);
            contains(value);
            break;
        case 9:
            printf("\nBye");
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    }while(ch!=9);

    return 0;
}