#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
struct node* head2=NULL;
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
            printf("Node inserted\n");
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
    ptr = (struct node*)malloc(sizeof(struct node));  
    if(ptr == NULL){
        printf("Overflow\n");
    } else {
        printf("Enter the value to be added: ");
        scanf("%d", &item);
        printf("Enter the location after which you want to add: ");
        scanf("%d", &loc);

        
        temp = head;
        for(i = 0; i < loc; i++) {
            temp = temp->next;
            if(temp == NULL) {  
                printf("Can't insert, location is out of bounds.\n");
                return;
            }
        }
        
        
        ptr->data = item;
        ptr->next = temp->next;  
        temp->next = ptr;

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
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }

    }
    
}
void delete(){
    struct node *ptr;
    ptr=head;
    head=ptr->next;
    free(ptr);
    printf("Node deleted\n");
}
void delete_end(){
    struct node *ptr,*temp;
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head->next==NULL){
        
        free(head);
        head=NULL;
        printf("The only node deleted\n");
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            temp=ptr;
            ptr=ptr->next;

        }
        temp->next=NULL;
        free(ptr);
        printf("Node deleted from end\n");

    }
}
void delete_random(){
    struct node *ptr,*temp;
    int loc,i;
    printf("Enter the position at which you want to delete:");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++){
        temp=ptr;
        ptr=ptr->next;
        if(temp->next==NULL){
            printf("Not enough elemenst in the list\n");
            return;
        }
    }
    temp->next=ptr->next;
    free(ptr);
    printf("Deleted at location %d",loc);
}
void sort(){
    struct node *i,*j;
    int temp;
    for(i=head ;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

}
void insert_list_2(){
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
        if(head2==NULL){
            ptr->next=NULL;
            head2=ptr;
            printf("Node inserted\n");
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
struct node* concatenate(){
    if(head==NULL){
        head=head2;
        printf("List 1 is empty");
        return;
    }
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    return head;

}
void reverse(){
    struct node *current=head,*prev=NULL,*next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
int main(){
    struct node* head=NULL;
    int choice;
    printf("Menu:\n");
    printf("1.insertbeginning\n2.insertend\n3.insertrandom\n4.deletebeginning\n5.deleteend\n6.deleterandom\n7.show\n8.sort\n9.insert_list_2\n10.concatenate\n11.reverse\n12.EXIT\n");
    
    while(1){

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:insertbeginning();
                    break;
            case 2:insertlast();
                    break;
            case 3:insertrandom();
                    break;
            case 4:delete();
                    break;
            case 5:delete_end();
                    break;
            case 6: delete_random();
                    break;
            case 7:show();
                    break;
            case 8:sort();
                    break;
            case 9:insert_list_2();
                    break;
            case 10:concatenate();
                    break;
            case 11:reverse();
                    break;
            case 12:return 0;
            default:
                printf("Invaid choice.");
        }
    }
}