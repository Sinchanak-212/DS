#include <stdio.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;

void push(int value){
    if (top==max-1){
        printf("stack overload\n");
    }
    else
        top++;
        stack[top]=value;
        printf("insertion successful\n");

}

void pop(){
    if (top==-1)
        printf("stack is empty or underflow\n");
    else
        printf("deleted : %d \n",stack[top]);
        top--;
}

void display(){
    int i;
    if (top==-1)
        printf("stcak is empty\n");
    else

    printf("stack elements are\n");
    for (i=top;i>=0;i--)
        printf("%d\n",stack[i]);
}

void main(){
 int value,choice;
 printf("*********menu*******\n");
 printf(" 1.Push\n 2.Pop\n 3.Display\n 4.exit\n");
 while(1){

    printf("enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
    case 1 :
        printf("enter the value:\n");
        scanf("%d",&value);
        push(value);
        break;
    case 2 :
        pop();
        break;
    case 3 :
        display();
        break;
    case 4 :
        exit(0);
        break;
    default :
        printf("invalid!");
        break;
    }




 }






}
