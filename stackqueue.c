#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insert(){
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int item;
    if(ptr==NULL){
        printf("Overflow\n");

    }
    else{
        printf("Enter the value you want to insert:");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("Node inserted\n");
    }
}
void delete(){
    struct node* ptr;
    ptr=head;
    if(head->next==NULL){
        head=NULL;
        free(head);
    
    }
    else{
        head=ptr->next;
        free(ptr);
    }
    printf("Node deleted\n");
}
void queueinsert(){
    struct node *ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Overflow");
    }
    else{
        printf("Enter the value to be inserted:");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL){
            head=ptr;
            ptr->next=NULL;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
        }
        printf("Node inserted\n");
    }
}
void show(){
    struct node*temp;
    temp=head;
    if(head==NULL){
        printf("Nothing to display\n");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    int choice;
    printf("------Menu-------\n");
    printf("1.StackInsert\n2.StackDelete\n3.QueueInsert\n4.QueueDelete\n5.Show\n6.Exit\n");
    while(1){
    printf("\nEnter choice:");
    scanf("%d",&choice);
    
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                queueinsert();
                break;
            case 4: delete();
                break;
            case 5: 
                show();
                break;
            case 6: return 0;
            default:
                printf("Invalid Input\n");
        }
    }
}