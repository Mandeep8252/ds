#include<stdio.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head=NULL;
struct Node* newnode=NULL;
struct Node* temp=NULL;

void createnode(int val){
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
}

void insertbeg(int val){
    createnode(val);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void deleteval(int val){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
        while(temp!=NULL && temp->data!=val){
            temp=temp->next;
        }
        if(temp==NULL){
            printf("no such value");
        }
        else if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }

    else if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
    }
        else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
}

void display(){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
                printf("%d",temp->data);
                temp=temp->next;
        }
    }
}

int main(){
    int val;
    int choice;
    while(1){
        printf("enter a choice 1.insert at beg 2.delete at val 3. display 4.exit\n");
        scanf("%d",&choice);
    switch(choice){
        case 1: printf("enter a value\n");
            scanf("%d",&val);
            insertbeg(val);
            break;

        case 2:printf("enter a value\n");
            scanf("%d",&val);
            deleteval(val);
                break;

        case 3:display();
            break;
        case 4:return 0;
    }
    }

}

