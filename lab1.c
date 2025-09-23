#include<stdio.h>
#define n 5
int stack[5];
int top=-1;
void push(){
    int x;
    printf("Enter the no.:");
    scanf("%d",&x);
    if(top==n-1){
        printf("Stack is full, Overflow");

    }
    else{
        ++top;
        stack[top]=x;

        
        printf("%d",x);

    }
}
void pop(){
    int item;
    if(top==-1){
        printf("Stack is empty, Underflow");
    }
    else{
        item=stack[top];
        top--;
        printf("%d",item);
    }

}
int peek(){
    if(top==-1){
        printf("Empty stack, Underflow");
    }
    else{
        return stack[top];
    }
}
int display(){
    int i;
    if(top==-1){
        printf("Empty stack, Underflow");
    }
    else{
        for(i=0;i<=n-1;i++){
            return stack[i];
        }
    }
}
int main(){
    int ch;
    printf("--------Menu-------\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:peek();
        break;
        case 4:display();
        break;
        default:
        printf("Enter a valid choice");

    }
    return 0;


}



