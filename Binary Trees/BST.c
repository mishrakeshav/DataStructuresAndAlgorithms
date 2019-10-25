#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definition of a simple BT
typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}Tree;


//creates a new node in binary tree;
Tree * createNode(int data){
    Tree * treenode = malloc(sizeof(Tree));
    treenode->data = data;
    treenode->left = NULL;
    treenode->right = NULL;
    return treenode;
}
int largestElement(Tree * root){
    if(root==NULL){
        return -1;
    }
    else{
        Tree * temp = root;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        return temp->data;
    }
}
int smallestElement(Tree * root){
    if(root==NULL){
        return -1;
    }
    else{
        Tree * temp = root;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp->data;
    }
}
int containsHelper(Tree * Node, int value){
    if(Node==NULL){
        //base case 1: If node is null return 0, value not found
        return 0;
    }
    else if(Node->data == value){
        //base case 2: If node contains the value, return 1
        return 1;
    }
    else{
        return containsHelper(Node->left, value) || containsHelper(Node->right, value);      
    }
}
//returns 1 if the BT contains the value, else returns 0
int contains(Tree * root,int value){
    containsHelper(root,value);
}


// add a new node to BST
Tree * add(Tree * node, int data){

    if(node==NULL){
        return createNode(data);
    }
    if(data < node->data){
        node->left = add(node->left, data);
    }
    else if(data > node->data){
        node->right = add(node->right, data);
    }

    return node;
}
void printSideways(Tree * root, char indent[]){
    if(root != NULL){
        printSideways(root->left, strcat(indent , "   "));
        printf("%d %s", root->data, indent);
        printSideways(root->right, strcat(indent , "   "));
    }
}
void preorder(Tree * root){
    if(root != NULL){
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Tree * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}
void inorder(Tree * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}
Tree * delete(Tree * node, int data){
    if(data < node->data){
        node->left = delete(node->left, data);
    }
    else if(data > node->data){
        node->right = delete(node->right,data);
    }
    else{
        //if the above cases fail 
        //then node->data == data
        Tree * trash = NULL;
        if(node->left==NULL && node->right==NULL){
            //case 1: node is leaf
            trash = node;
            node = NULL;
        }
        else if(node->right==NULL){
            //case 2: node has only left child
            trash = node;
            node = node->left;
        }
        else if(node->left==NULL){
            //case 3: node has only right child
            trash = node;
            node = node->right;
        }
        else{
            //case 4: L & R are subtrees
            node->data = smallestElement(node->right);
            node->right = delete(node->right,node->data);
        }
        if(trash!=NULL){
            free(trash);
        }
    }

    return node;
}
   
void showMenu(){
    printf("\n***MENU***\n");
        printf("\n1. Add element");
        printf("\n2. Delete element");
        printf("\n3. Contains");
        printf("\n4. In-order");
        printf("\n5. Pre-order");
        printf("\n6. Post-order");
        printf("\n7. Largest element");
        printf("\n8. Smallest element");
        printf("\n9. show menu");
        printf("\n10 Printsideways");  //doesnt work
        printf("\n11. Exit\n");
        
}

int main(){
    Tree * root = NULL;
    int ch, data;
    showMenu();
    do{
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value : ");
            scanf("%d",&data);
            root = add(root,data);
            printf("\nValue added");
            break;
        case 2:
            printf("\nEnter value to delete: ");
            scanf("%d", &data);
            if(contains(root,data)){
                root = delete(root,data);
            }else{
                printf("\nValue not found");
            }
            break;
        case 3:
            printf("\nEnter value to check: ");
            scanf("%d", &data);
            if(contains(root,data)){
                printf("\nValue found");
            }
            else{
                printf("\nValue not found");
            }
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            preorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case 7:
            data  = largestElement(root);
            if(data !=-1){
                printf("\nLargest element: %d", data);
            }
            else{
                printf("\nTree is empty");
            }
            break;
        case 8:
            data  = smallestElement(root);
            if(data !=-1){
                printf("\nSmallest element: %d", data);
            }
            else{
                printf("\nTree is empty");
            }
            break;
        case 9:
            showMenu();
            break;
        case 10:
            printf("\n");
            printSideways(root, "");
            break;
        case 11:
            printf("\nBye\n");
            break;
            
        
        default:
            printf("\nInvalid option");
            break;
        }
    }while(ch!=11);
    

    return 0;
}
