#include <stdio.h>
#define Max 5
int queue[Max];
int front=-1,rear=-1;
 void insert(){
    int item;
    if(rear==Max-1){
        printf("Overflow, Can't insert element\n");

    }
    printf("Enter the element you want to insert:");
    scanf("%d",&item);
    if(front==-1)
    front=0;
    queue[++rear]=item;
    printf("Inserted %d element into the queue\n",item);
 }
 void delete(){
    if(front==-1 ||  front>rear){
        printf("Underflow, satck is empty\n");
    }
    printf("Deleted element is %d\n",queue[front]);
    front++;
 }
 void display(){
    if(front==-1){
        printf("Queue is empty, nothing to display\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d",queue[i]);
        }
    }
 }
 int main(){
    int ch;
    while(1){
        printf("\n-------Menu-------\n");
        printf("1.Insert\n2.Delete\n3.Display\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
    
    switch(ch){
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;    
        case 3:
            display();
            break;
        default:
            printf("Invalid Choice, Please Enter a Valid Choice"); 

    }
    return 0;
 }
 }