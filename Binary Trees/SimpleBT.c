#include<stdio.h>
#include<stdlib.h>

//Definition of a simple BT
typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}TreeNode;


void printHelper(TreeNode * Node){
    // implicit base case: if null, do nothing
    if(Node!=NULL){
        printHelper(Node->left);
        printHelper(Node->right);
    }
}
//this function prints the binary tree
void print(TreeNode * root){
    return printHelper(root);
}


int containsHelper(TreeNode * Node, int value){
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
int contains(TreeNode * root,int value){
    containsHelper(root,value);
}




//creates a new node in binary tree;
TreeNode * createNode(int data, TreeNode * treenode, TreeNode * left, TreeNode * right){
    treenode->data = data;
    treenode->left = left;
    treenode->right = right;
    return treenode;
}

int main(){
    TreeNode * Node = malloc(sizeof(TreeNode));
    
    Node->data = 42;
    Node->left = malloc(sizeof(TreeNode));
    Node->left->data = 12;
    Node->right = malloc(sizeof(TreeNode));
    Node->right->data = 67;
    Node->left->left = malloc(sizeof(TreeNode));
    Node->left->left->data = 90;
    Node->left->right->data = 27;


}