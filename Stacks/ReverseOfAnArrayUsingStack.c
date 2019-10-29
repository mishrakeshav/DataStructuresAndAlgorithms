/*
Write a program to reverse a list of given
numbers using stack
*/
#include<stdio.h>
#include<stdlib.h>
int stack[10];
int top = -1;
int pop(){
    int val = stack[top];
    top--;
    return val;
}
int push(int val){
    top++;
    stack[top] = val;
}
int main()
{
    int val, n, i;
    int arr[10];
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array: \n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n; i++){
        push(arr[i]);
    }
    for(i=0; i<n; i++){
        val = pop();
        arr[i] = val;
    }
    printf("\nThe reversed array is \n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
