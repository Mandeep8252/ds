#include<stdio.h>
typedef struct listnode{
    int data;
    struct listnode* left;
    struct listnode* right;

}Node ;
Node* createNode(int val){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->right=NULL;
    newnode->left=NULL;
}
void insertnode(Node* newnode, Node* root){
    if(newnode->data<root->data){
        if(root->left!=NULL){
            insertnode(newnode,root->left);
        }
        else{
            root->left=newnode;
        }
    }
    else{
        if(root->right!=NULL){
            insertnode(newnode,root->right);
        }
        else{
            root->right=newnode;
        }
    }
}
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void preorder(Node* root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    int value;
    Node* root=NULL;
    Node* newnode;
    int choice;
    while(1){
        printf("Enter ypur choice\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the value\n");
                    scanf("%d",&value);
                    newnode=createNode(value);
                    if(root==NULL){
                        root=newnode;
                    }
                    else{
                        insertnode(newnode,root);
                    }
                    break;
            case 2:
                    preorder(root);
                    break;
            case 3:postorder(root);
                    break;
            case 4:inorder(root);
                    break;
            case 5:return 0;
        }
    }
}