#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
void insertbeginning(){
    struct node* ptr;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        printf("Overflow\n");
    }
    else{
        printf("Enter the value to be addeded:\n");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("Node inserted\n");
    }
}
void insertlast(){
    struct node *ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        printf("Overflow\n");
    }
    else{
        printf("Enter the value to be added:\n");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
            printf("Node inserted");
    }
        else{
            temp=head;
            while(temp->next !=NULL){
                temp=temp->next;

            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("Node inserted\n");
    }
}
}
void insertrandom(){
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));  // Fix memory allocation
    if(ptr == NULL){
        printf("Overflow\n");
    } else {
        printf("Enter the value to be added: ");
        scanf("%d", &item);
        printf("Enter the location after which you want to add: ");
        scanf("%d", &loc);

        // Check if location is valid
        temp = head;
        for(i = 0; i < loc; i++) {
            temp = temp->next;
            if(temp == NULL) {  // If we reached the end of the list before reaching 'loc'
                printf("Can't insert, location is out of bounds.\n");
                return;
            }
        }
        
        // Now 'temp' is at the node after which we want to insert
        ptr->data = item;
        ptr->next = temp->next;  // Make new node's next point to temp's next
        temp->next = ptr;        // Make temp's next point to the new node

        printf("Node inserted\n");
    }
}

void show(){
    struct node* ptr;
    ptr=head;
    if(ptr==NULL){
        printf("Nothing to print");
    }
    else{
        while(ptr != NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }

    }
    
}
void main(){
    struct node* head=NULL;
    insertbeginning();
    insertlast();
    insertrandom();
    show();
}