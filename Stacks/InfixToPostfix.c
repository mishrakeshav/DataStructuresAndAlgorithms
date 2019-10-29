/*
Write a program to convert an
INFIX expression into its equivalent
postfix notation
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;

//function prototype
void push(char stack[], char);
char pop(char stack[]);
void InfixTOPostfix(char source[], char target[]);
int getPriority(char );

int main()
{
    char infix[MAX], postfix[MAX];
    printf("\nEnter an infix expression\n");
    gets(infix);
    strcpy(postfix,"");
    InfixToPostfix(infix,postfix);
    printf("\nThe Corresponding Postfix expression is \n%s", postfix);
    return 0;
}
void InfixToPostfix(char source[], char target[]){

    int i = 0, j = 0;
    char temp;
    while(source[i]!='\0'){
        if(source[i]=='('){
            push(stack, source[i]);
            i++;
        }
        else if(source[i] == ')')
        {
            while((top!=-1) && (stack[top]!='(')){
                target[j] = pop(stack);
                j++;

            }
            if(top == -1){
                printf("\nIncorrect Expression");
                exit(1);

            }
            temp = pop(stack);
            i++;
        }
        else if(isdigit(source[i])||isalpha(source[i])){
            target[j] = source[i];
            i++;
            j++;
        }
        else if(source[i]=='+' || source[i]== '-' || source[i]=='*' || source[i] == '/'|| source[i]== '%')
        {
           while((top !=-1) && (stack[top]!= '(') && (getPriority(stack[top]) > getPriority(source[i]))) {
                    target[j] = pop(stack);
                    j++;
                 }
            push(stack, source[i]);
            i++;
        }
        else{
            printf("\nIncorrect element in expression\n");
            exit(1);
        }



    }
    while((top!=-1) && (stack[top] != '(')){
                target[j] = pop(stack);
                j++;
    }
    target[j] = '\0';

}
int getPriority(char op){
    if(op =='/'|| op=='*' || op == '%')
        return 1;
    else if(op == '+' || op == '-'){
        return 0;
    }
}
void push(char stack[], char val){
        if(top==MAX-1){
            printf("Stack Overflow\n");
        }
        else{
            top++;
            stack[top] = val;
        }
}
char pop(char stack[]){
    char val = ' ';
    if(top==-1)
        printf("\nStack Underflow\n");
    else{
        val = stack[top];
        top--;
    }
    return val;
}










