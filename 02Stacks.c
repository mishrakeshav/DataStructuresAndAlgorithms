#include<stdio.h>
int a[100], top = -1;
int push(int a[],int val){

	if(top == 99)
		printf("\nStack Overflow!");
	else{
		top++;
		a[top]=val;
	}

}
int pop(int a[]){
	if(top==-1)
		printf("\nStack underflow");
	else{
		val = a[top];
		top--;
		return val;
	}
}
int peek(int a[], int n){
	if(top==-1){
		printf("\nStack is Empty");
		return -1;
	}
	else{
		return a[top];
	}
}
int display(int a[]){
	int i;
	if(top==-1)
		printf("\nStack is empty");
	else{
		for(i=top; i>=0; i--){
			printf("\n%d", a[i]);
		}
	}
	
}
int main(){
	int val, ch;
	do {
		printf("*****MENU*****\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peep\n");
		printf("4.Display\n");
		printf("5. Exit\n");
		printf("Enter your choice ?\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("\nEnter the number to be pushed in");
				scanf("%d", &val);
				push(a,val);
				break;
			case 2:
				val = pop(a);
				if(val!=-1)
					printf("\nThe value deleted from the stack is %d", val);
				break;
			case 3:
				val = peek(a);
				if(val!=-1)
					printf("value stored at the top of the stack is %d", val);
				break;
			case 4:
				display(a);
				break;
		}
	}while(ch!=5);
	return 0;
}