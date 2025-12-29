#include<stdio.h>
#include<stdlib.h>
#define Max 5
int queue[Max];
int front=-1;
int rear=-1;
void insertbeg(int x){
    if(front==0 && rear==Max-1 || front==rear+1){
        printf("Queue is full\n");
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
        }
        else if(front==0){
            front=Max-1;
            
        }
        else{
            front=front-1;
        }
        queue[front]=x;
        
    }
}
void insertend(int x){
    if(front==0 && rear==Max-1 || front==rear+1){
        printf("Overflow\n");
        return;
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
        }
        if(rear==Max-1){
            rear=0;
        }
        else{
            rear=rear+1;
        }
    }
    queue[rear]=x;
}
void display(){
    if(front==-1){
        printf("Nothing to dispaly");
        return;
    }
    else{
       for(int i=front;;i=(i+1)%Max){
           printf("%d\n",queue[i]);
           if(i==rear){
               break;
           }
       }
    }
}
int main(){
    int x,choice;
    printf("1.insertbeg\n2.Insertend\n3.Display\n4.Exit\n");
   
    while(1){
        printf("Enter choice:");
         scanf("%d",&choice);
         switch(choice){
             case 1:
                printf("Enter the val:");
                scanf("%d",&x);
                insertbeg(x);
                break;
            case 2:
                printf("Enter the val:");
                scanf("%d",&x);
                insertend(x);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
         }
    }
}
