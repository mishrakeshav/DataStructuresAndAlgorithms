#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}NODE;

NODE * insertBeg(NODE * start, int data){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nUnderflow");
        return start;
    }
    newnode->data = data;
    newnode->next = NULL;
    if(start==NULL){  
        start = newnode;       
        return start;
    }
    newnode->next = start;
    start = newnode;
    return start;

}

NODE * insertEnd(NODE * start, int data){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nUnderflow");
        return start;
    }
    newnode->data  = data;
    if(start==NULL){
        start = newnode;
        newnode->next = NULL;
        return start;
    }
    NODE * temp;
    temp = start;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    newnode->next = NULL;
    temp->next = newnode;
    return start;
}

NODE * insertAfter(NODE * start, int data, int value){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nUnderflow");
        return start;
    }
    newnode->data = data;

    if(start==NULL){
        printf("\nValue not found");
        return start;
    }
    NODE * temp = start;
    while(temp!=NULL){
        if(temp->data == value){
            break;
        }
        temp = temp->next;
    }

    if(temp==NULL){
        printf("\nValue not found");
        return start;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return start;
    
}

NODE * deleteBegin(NODE * start){
    if(start==NULL){
        printf("\nValue not found");
        return start;
    }
    printf("\nValue deleted is %d", start->data);
    start = start->next;
    return start;
}

NODE * deleteEnd(NODE * start){
    if(start==NULL){
        printf("\nValue not found");
        return start;
    }
    if(start->next==NULL){
        printf("\nValue deleted is %d", start->data);
        start = NULL;
        return start;
    }

    NODE * temp = start;
    NODE * prev = NULL;

    while(temp->next !=NULL){
        prev = temp;
        temp = temp->next;
    }
    printf("\nValue deleted is %d", temp->data);
    prev->next = NULL;
    return start;
}
NODE * deleteValue(NODE * start, int value){
    if(start==NULL){
        printf("\nValue not found");
        return start;
    }
    if(start->data == value){
        printf("\n%d deleted", start->data);
        start=start->next;
        return start;
    }

    NODE * temp = start;
    NODE * prev;
    while(temp->data!=value ){
        prev = temp;
        temp = temp->next;
        if(temp==NULL){
            printf("\nValue not found");
            return start;
        }
    
    }
    if(temp->next==NULL && temp->data!=value){
        printf("\nValue not found");
        return start;
    }
    
    printf("\n%d deleted", temp->data);
    prev->next = temp->next;
    return start;
}

void traverseList(NODE * start){
    if(start==NULL){
        printf("List is empty");
    }
    else{
        NODE * temp = start;
        printf("\n");
        while(temp){
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}
int main(){
    int ch, data, value;
    NODE * start = NULL;
    do{
        printf("\n***MENU***\n");
        printf("\n1. Push");
        printf("\n2. Insert after a node");
        printf("\n3. Append");
        printf("\n4. Delete a node");
        printf("\n5. Pop");
        printf("\n6. Delete end");
        printf("\n7. Display linked list");
        printf("\n8. Peek");
        printf("\n9. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value to be pushed: ");
                scanf("%d", &data);
                start = insertBeg(start,data);
                break;
            case 2:
                printf("\nEnter value to be inserted: ");
                scanf("%d", &data);
                printf("\nEnter Value of previous node: ");
                scanf("%d", &value);
                start = insertAfter(start,data,value);
                break;
            case 3:
                printf("\nEnter value to append: ");
                scanf("%d", &data);
                start = insertEnd(start,data);
                break;
            case 4:
                printf("\nEnter value to be deleted: ");
                scanf("%d", &value);
                start = deleteValue(start,value);
                break;
            case 5:
                start = deleteBegin(start);
                break;
            case 6:
                start = deleteEnd(start);
                break;
            case 7:
                traverseList(start);
                break;
            case 8:
                break;
            case 9:
                printf("\nBye");
                break;
            default :
                printf("\nInvalid option");



            
        }
    }while(ch!=9);

    return 0;
}