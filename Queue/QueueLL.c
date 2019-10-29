#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct node * next;
}NODE;
NODE * front;
NODE * rear;
void insert(int data){
    NODE * newnode = malloc(sizeof(NODE));
    newnode->data = data;
    if(front==NULL){
        front = newnode;
        rear = newnode;
        front->next = NULL;
        return;
    }
    rear->next = newnode;
    rear = newnode;
    newnode->next = NULL;
}
void delete(){
    if(front ==NULL){
        printf("\nUnderflow");
        return;
    }
    if(front->next==NULL){
        printf("\nValue deleted is %d", front->data);
        NODE * trash = front;
        front = NULL;
        rear = NULL;
        return;
    }
    printf("\nValue deleted is %d", front->data);
    NODE * trash = front;
    front = front->next;
    free(trash);
}
void contains(int data){
    if(front==NULL){
        printf("\nFalse");
        return;
    }
    if(front->data == data){
        printf("\nTrue");
        return;
    }
    NODE * temp = front;
    while(temp !=NULL){
        if(temp->data == data){
            printf("\nTrue");
            return;
        }
        temp = temp->next;
    }
    printf("\nFalse");
}
void display(){
    if(front==NULL){
        printf("\nUnderflow");
        return;
    }
    NODE * temp = front;
    printf("\n");
    while(temp){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");

}
int main(){
    int ch,data;
    front = NULL;
    rear = NULL;
    do{
        printf("\n\n***MENU***");
        printf("\n1. enQueue");
        printf("\n2. deQueue");
        printf("\n3. Peek");
        printf("\n4. Traverse Queue");
        printf("\n5. Contains?");
        printf("\n6. Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to insert : ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            delete();
            break;
        case 3:
            if(front!=NULL){
                printf("\nValue at the front is %d", front->data);
            }
            else{
                printf("\nQueue is empty");
            } 
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nEnter value: ");
            scanf("%d", &data);
            contains(data);
            break;
        case 6:
            printf("\nBye");
            break;

        default:
            printf("\nInvalid choice");
            break;
        }
    }while(ch!=6);
    return 0;
}