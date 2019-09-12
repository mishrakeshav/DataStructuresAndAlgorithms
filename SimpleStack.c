#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int stack[100];
int MAX = 100;
int topA = -1, topB = 100;
int pushA(int stack[], int p){
    if(topA == topB - 1){
        printf("\nStack Overflow\n");
    }
    else{
            topA++;

            stack[topA] = p;

    }

}
int popA(int stack[]){
    int val = -999;
    if(topA==-999){
        printf("\nStack Underflow\n");
        return val;
    }
    else{
        val = stack[topA];
        topA--;
        return val;
    }
}

int peekA(int stack[], int top){
    if(topA==-1){
        printf("\nStack Underflow\n");
        return -999;
    }
    else{

        return stack[topA];
    }
}
int display_stackA(int stack[]){
    int i;
    if(topA == -1)
        printf("Stack Underflow");
    else{
        for(i=topA; i>=0; i--){
            printf("\n%d", stack[i]);
        }
        printf("\n");
    }
}
int pushB(int stack[], int p){
    if(topA == topB - 1){
        printf("\nStack Overflow\n");
    }
    else{
            topB--;

            stack[topB] = p;

    }

}
int popB(int stack[]){
    int val = -999;
    if(topB == MAX){
        printf("\nStack Underflow\n");
        return val;
    }
    else{
        val = stack[topB];
        topB++;
        return val;
    }
}
int peekB(int stack[], int top){
    if(topB==MAX){
        printf("\nStack Underflow\n");
        return -999;
    }
    else{

        return stack[topB];
    }

}
int display_stackB(int stack[]){
    int i;
    if(topB == MAX)
        printf("Stack Underflow");
    else{
        for(i=topB; i<MAX; i++){
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
        printf("1.PUSH IN STACK A\n");
        printf("2.POP IN STACK A\n");
        printf("3.PEEK IN STACK A\n");
        printf("4.DISPLAY STACK A\n");
        printf("5.PUSH IN STACK B\n");
        printf("6.POP IN STACK B\n");
        printf("7.PEEK IN STACK B\n");
        printf("8.DISPLAY STACK B\n");
        printf("9.EXIT\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\nEnter the value to push  on stack A: ");
                scanf("%d", &val);
                pushA(stack, val);
                break;
            case 2:
                val = popA(stack);
                if(val!=-999)
                    printf("\n The value deleted from stack A is %d\n", val);
                break;
            case 3:
                val = peekA(stack, topA);
                if(val !=-999)
                    printf("\nThe value stored at the top of the stack A is %d \n", val);
                break;
            case 4:
                display_stackA(stack);
                break;
            case 5:
                printf("\nEnter the value to push  on stack B: ");
                scanf("%d", &val);
                pushB(stack, val);
                break;
            case 6:
                val = popB(stack);
                if(val!=-999)
                    printf("\n The value deleted from stack  B is %d\n", val);
                break;
            case 7:
                val = peekB(stack, topB);
                if(val !=-999)
                    printf("\nThe value stored at the top of the stack B is %d \n", val);
                break;
            case 8:
                display_stackB(stack);
                break;



        }
    }while(ch!=9);
    return 0;

}
