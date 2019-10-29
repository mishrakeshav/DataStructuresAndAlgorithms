//Array implementation of simple queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int front = -1,rear = -1;
int queue[MAX];

void enQueue(int data){
    if(rear == MAX-1){
        printf("\nOverflow");
        return;
    }
    if(front==-1){
        front = 0;
        rear = 0;
        queue[rear] = data;
        return;
    }
    queue[++rear] = data;
}
void deQueue(){
    if(front == -1){
        printf("\nQueue is empty");
        return;
    }
    if(front==rear){
        printf("\nValue deleted is %d", queue[front]);
        front = -1;
        rear = -1;
        return;
    }
    printf("\nValue deleted is %d", queue[front]);
    front++;
}
void traverse(){
    if(front==-1){
        printf("\nQueue is empty");
        return;
    }
    int i;
    printf("\n");
    for(i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
}
void contains(int data){
    if(front==-1){
        printf("\nFalse");
        return;
    }
    int i;
    for(i=front; i<=rear; i++){
        if(queue[i] == data){
            printf("\nTrue");
            return;
        }
    }
    printf("\nFalse");
}
int main(){
    int ch,data;
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
            enQueue(data);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            if(front==-1){
                printf("\nQueue is empty");
            }
            else{
                printf("\nValue at front is %d", queue[front]);
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