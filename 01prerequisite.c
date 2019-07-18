#include<stdio.h>
int display(int a[50], int n){

	int i;
	for(i=0; i<n; i++){
            
	printf("%d\n",a[i]);
	
	}
}
int insert(int a[50],int n){
	int val, pos, i;
	printf("Enter the position at which you want to insert element\n");
	scanf("%d", &pos);
	if(pos>n){
		printf("Entered number exceeds index number");
		return 0;
	}
	printf("Enter the value of element: ");
	scanf("%d", &val);
	for(i=n; i>pos; i--){
		a[i] = a[i-1];

	}
	a[pos-1] = val;
	for(i=0; i<=n; i++){
		printf("%d\n", a[i]);
	}

}
int delete(int a[50], int n){
	int pos, i;
	printf("Enter the position of element you want to delete\n");
	scanf("%d", &pos);
	if(pos>n){
		printf("Enterd number exceeds maximum index value");
		return 0;
	}
	for(i=pos-1; i<n; i++){
		a[i]= a[i+1];
	}
	printf("After deletion\n");
	display(a, n-1);


}

int delete_by_value(int a[50], int n){

	int val, i;
	printf("Enter the value of the element you want to delete: ");
	scanf("%d", &val);
	for(i=0; i<n; i++){

		if(a[i]==val){
			break;
		}
	}
	if(i==n){
		printf("Entered value is not found in the array");
		return 0;
	}
	int pos = i;
	for(i = pos; i<n; i++){
		a[i] = a[i+1];
	}
	printf("After deletion\n");
	display(a,n-1);
}
reverse(int a[50], int n){

	int i, j, temp;
	for(i=0, j=n-1;i<n/2; i++, j--){
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	printf("After reversing : \n");
	display(a,n);

}
duplicate(int a[50], int n){

    int i, j;
    for(i=0; i<n; i++){
        for(j=i+1; j<n-1; j++){

            if(a[i]==a[j]){
                printf("%d\t", a[i]);
                break;
            }
        }
    }
}

int main()
{
	int ch, a[50], n, i;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	printf("Enter elements\n");
	for(i=0; i<n; i++){
		printf("Enter element[%d]: ", i);
		scanf("%d", &a[i]);
	}

	printf("Enter choice\n");
	printf("1. Insert an Element by position\n");
	printf("2. Delete an Element\n");
	printf("3. Delete an Element by value\n");
	printf("4. Reverse an Array\n");
	printf("5. Print duplicate element of an array\n");
	scanf("%d", &ch);
	switch(ch){
		case 1:
			insert(a,n);
			break;
		case 2:
			delete(a,n);
			break;
		case 3:
			delete_by_value(a,n);
			break;
		case 4:
			reverse(a, n);
			break;
		case 5:
			printf("Duplicate values are: \n");
			duplicate(a, n);
			break;
		default :
			printf("Invalid choice!");

	}
return 0;
}
