/*
Write a program to check
nesting of parenthesis using a stack
*/
#include<stdio.h>
#include<string.h>
#define MAX 10
int top = -1;
int stack[MAX];
void push(char c){
    stack[++top] = c;


}
void pop()
{
    if(top==-1){
        printf("\nExpression is invalid\n");
        exit(0);
    }
    else{

        top--;
    }
}
void find_top(){
    if(top==-1){
        printf("\nExpression is valid");
    }
    else{
        printf("\nExpression is invalid");

    }
}
int main()
{
    char exp[MAX], temp;
    int i, flag = 1;
    printf("\nEnter an expression: ");
    gets(exp);
    for(i=0; exp[i]!='\0'; i++){
        if(exp[i]== '('){
            push(exp[i]);
        }
        else if(exp[i] == ')'){
            pop();
        }
    }
    find_top();

return 0;
}
/*OUTPUT:
Enter an expression: (A+B*(C-D))

Expression is valid
*/

