#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    int priority;
    struct Node * next;
}NODE;
NODE * front;
void deQueue(){
    if(front ==NULL){
        printf("\nUnderflow");
        return;
    }
    if(front->next==NULL){
        printf("\nValue deleted is %d", front->data);
        NODE * trash = front;
        front = NULL;
        free(trash);
        return;
    }
    printf("\nValue deleted is %d", front->data);
    NODE * trash = front;
    front = front->next;
    free(trash);
}
void enQueue(int data, int priority){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nOverflow");
        return;
    }
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    if(front == NULL){
        front = newnode;
        return;
    }
    if(front->priority > priority){
        newnode->next = front;
        front = newnode;
        return;
    }
    NODE * temp = front;
    NODE * prev = NULL;
    while(temp->priority < newnode->priority){
        if(temp->next==NULL){
            temp->next = newnode;
            newnode->next = NULL;
            return;
        }
        prev = temp;
        temp = temp->next;        
    }
    
    newnode->next = prev->next;
    prev->next = newnode;
}
void traverse(){
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
int main(){
    int ch,data,priority;
    front = NULL;
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
            printf("\nEnter priority: ");
            scanf("%d", &priority);
            enQueue(data,priority);
            break;
        case 2:
            deQueue();
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
            traverse();
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