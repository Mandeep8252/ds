#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[100];
    int roll;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node* create(char x[],int y){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name,x);
    newnode->roll=y;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insertbeg(char x[],int y){
    struct node *newnode=create(x,y);
    if(head==NULL){
        head=newnode;
        newnode->prev=NULL;
        newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        newnode->prev=NULL;
        
        
    }
    printf("Node inserted at the beginning\n");
}
void insertlast(char x[],int y){
    struct node *newnode=create(x,y);
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }
    printf("Node inserted at the end\n");
}
void deletebeg(){
    if(head==NULL){
        printf("Nothing to delete\n");
        return;
    }
    else{
        struct node *temp=head;
        head=temp->next;
        head->prev=NULL;
        free(temp);
        printf("Node deleted at the beginning\n");
    }
}
void deletelast(){
    if(head==NULL){
        printf("Nothing to delete\n");
        return;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
        printf("Node deleted from the end\n");
    }
}
void display(){
    if(head==NULL){
        printf("Nothing to display\n");
        return;
    }
    else{
        struct node *temp=head;
        while(temp!=NULL){
            printf("%s\n%d\n\n",temp->name,temp->roll);
            temp=temp->next;
        }
    }
}
void insertrandom(char x[],int y){
    struct node *newnode=create(x,y);
    int loc;
    printf("enter the location at which you want to insert:");
    scanf("%d",&loc);
    if(head==NULL && loc!=1){
        printf("Invalid location\n");
        return;
    }
    if(loc==1){
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=NULL;
        head=newnode;
        return;
        
    }
    else{
        struct node *temp=head;
        for(int i=1;i<loc;i++){
            if(temp->next==NULL){
                printf("Invalid location:\n");
                return;
            }
            temp=temp->next;
            
        }
        temp->prev->next=newnode;
        newnode->next=temp;
        
        newnode->prev=temp->prev;
        temp->prev=newnode;
        printf("Node inserted at location\n");
    }
}
void deleterandom(){
    struct node *temp=head;
    int loc;
    printf("enter the location at which you want to delete:");
    scanf("%d",&loc);
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    else if(loc==1){
        head=temp->next;
        head->prev=NULL;
        free(temp);
        return;
    }
    else{
        for(int i=1;i<loc;i++){
            if(temp==NULL){
                printf("Invalid location\n");
            }
            temp=temp->next;
        }
        if(temp->next==NULL){
            temp->prev->next=NULL;
            free(temp);
        }
        else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            
        }
        printf("Node deleted\n");
    }
}

int main(){
    char x[100];
    int y,choice;
    printf("1.Insertbeg\n2.Insertlast\n3.deletebeg\n4.deletelast\n5.display\n6.insertrandom\n7.Deleterandom\n8.exit\n");
   
   while(1){
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the name:");
                scanf("%s",x);
                printf("Enter roll:");
                scanf("%d",&y);
                insertbeg(x,y);
                break;
            case 2:
                printf("Enter the name:");
                scanf("%s",x);
                printf("Enter roll:");
                scanf("%d",&y);
                insertlast(x,y);
                break;
            case 3:
                deletebeg();
                break;
            case 4:
                deletelast();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Enter the name:");
                scanf("%s",x);
                printf("Enter roll:");
                scanf("%d",&y);
                insertrandom(x,y);
                break;
                
            case 7:
                deleterandom();
                break;
            case 8:
                return 0;
                
        
    }
   }
}
