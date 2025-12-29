#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
struct node  *insertend(struct node *head,int data){
    struct node *ptr=create(data);
    if(head==NULL){
        head=ptr;
        return head;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
        return head;
    }
}
void display(struct node *head){
    if(head==NULL){
        printf("Nothing to display\n");
        return;
    }
    else{
        while(head!=NULL){
            printf("%d",head->data);
            head=head->next;
        }
    }
    
}
void concatenate(struct node *head1,struct node *head2){
    if(head1==NULL){
        display(head2);
    }
    else if(head2==NULL){
        display(head1);
    }
    else{
        struct node *temp=head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head2;
        display(head1);
        
    }
}
void sort(struct node *head){
    struct node *i,*j;
    int temp;
    if(head==NULL){
        printf("Nothing to sort\n");
        return;
    }
    else{
        for(i=head;i!=NULL;i=i->next){
            for(j=i->next;j!=NULL;j=j->next){
                if(i->data>j->data){
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }
        }
        display(head);
    }
}
int main(){
    struct node *head1=NULL,*head2=NULL;
    int x,choice;
    printf("1.Insert in head1\n2.Insert in head2\n3.concatenate\n4.exit\n5.display\n6.sort\n");
    while(1){
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value:");
                scanf("%d",&x);
                head1=insertend(head1,x);
                break;
            case 2:
                 printf("Enter the value:");
                scanf("%d",&x);
                head2=insertend(head2,x);
                break;
            case 3:
                concatenate(head1,head2);
                break;
            case 4: return 0;
            case 6:
                sort(head1);
                break;
                
        }
    }
}
