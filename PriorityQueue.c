#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int priority;
    struct node * next;
}NODE;
NODE * deleteJob(NODE * start){
    if(start==NULL){
        printf("\nValue not found");
        return start;
    }
    printf("\nJOb: %d\nPriority: %d", start->data, start->priority);
    start = start->next;
    return start;
}


NODE * insertJob(NODE * start, int data, int priority){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nUnderflow");
        return start;
    }
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    if(start==NULL){
        start = newnode;
        return start;
    }
    if(start->priority>priority){
        newnode->next = start;
        start = newnode;
        return start;
    }
    NODE * temp = start;
    NODE * prev = NULL;
    while(temp->priority < newnode->priority){
        if(temp->next==NULL){
            temp->next = newnode;
            newnode->next = NULL;
            return start;
        }
        prev = temp;
        temp = temp->next;        
    }
    
    newnode->next = prev->next;
    prev->next = newnode;
    return start;
}

void traverseList(NODE * start){
    if(start==NULL){
        printf("List is empty");
    }
    else{
        NODE * temp = start;
        printf("\n");
        printf("Priority   |\t JOB \n");
        while(temp){
            printf("%d \t\t|%d", temp->priority,temp->data);
            printf("\n");
            temp = temp->next;          
        }    
    };
}

int main(){
    NODE * start = NULL;
    int ch, job, priority;
    do{
        printf("***MENU***");
        printf("\n1. Insert job");
        printf("\n2. get next Job");
        printf("\n3. Show jobs");
        printf("\n4. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\nEnter job number: ");
                scanf("%d", &job);
                printf("\nEnter priority of job: ");
                scanf("%d", &priority);
                start = insertJob(start,job,priority);
                break;
            case 2:
                start = deleteJob(start);
                break;
            case 3:
                traverseList(start);
            case 4:
                printf("\nBye");
                break;
            default:
                printf("\nInvalid ");
                break;
        }
    }while(ch!=4);
return 0;
}