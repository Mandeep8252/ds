#include<stdio.h>
#include<string.h>
#define n 5
char stack[n][100];
int top=-1;
void push(char x[]){
    if(top==n-1){
        printf("Stack is full\n");
        return;
    }
   else{
       top++;
        strcpy(stack[top],x);        
        printf("Inserted name\n");
   }
}
void pop(){
    if(top==-1){
        printf("Nothing to delete\n");
    }
    else{
         printf("The deleted element is %s",stack[top--]);
        
    }
   
}
void display(){
    if(top==-1){
        printf("Nothing to display\n");
        return;
    }
    else{
        for(int i=top;i!=-1;i--){
            printf("%s\n",stack[i]);
        }
    }
}
int main(){
    int choice;
    char x[100];
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    while(1){
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the name u want to insert:");
                scanf("%s",x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}

