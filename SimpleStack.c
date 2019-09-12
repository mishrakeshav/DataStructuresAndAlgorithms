#include<stdio.h>
#include<string.h>

int stack[100], top = -1;
int MAX = 100;
int pop(int stack[]){
    int val = -1;
    if(top==-1){
        printf("\nStack Underflow\n");
        return val;
    }
    else{
        val = stack[top];
        top--;
        return val;
    }
}
int push(int stack[], int p){
    if(top == MAX - 1){
        printf("\nStack Overflow\n");
    }
    else{
            top++;

            stack[top] = p;

    }

}
int peek(int stack[], int top){
    if(top==-1){
        printf("\nStack Underflow\n");
    }
    else{

        return stack[top];
    }
}
int display(int stack[]){
    int i;
    if(top == -1)
        printf("Stack Underflow");
    else{
        for(i=top; i>=0; i--){
            printf("\n%d", stack[i]);
        }
        printf("\n");
    }
}
int main(){

    int val , ch;
    do{

        printf("\n-----------------------------");
        printf("\n*********** MENU ***********\n");

        printf("-----------------------------\n");
        printf("1. PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\nEnter the number to be pushed on Stack\n");
                scanf("%d", &val);
                push(stack, val);
                break;
            case 2:
                val = pop(stack);
                if(val!=-1)
                    printf("\n The value deleted from stack is %d\n", val);
                break;
            case 3:
                val = peek(stack, top);
                if(val !=-1)
                    printf("\nThe value stored at the top of the stack is %d \n", val);
                break;
            case 4:
                display(stack);
                break;

        }
    }while(ch!=5);
    return 0;

}
