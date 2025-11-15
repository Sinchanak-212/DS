#include <stdio.h>
#include<string.h>
#define max 100

char stack_str[max];
int top=-1;

void push_char(char item){
    if (top==max-1)
        printf("stack overflow\n");
    else
        top++;
        stack_str[top]=item;

}

char pop_char(){
    int item;
    if (top==-1)
        printf("stack underflow\n");
    else
        item=stack_str[top];
        top--;
return item;
}

int main(){
    char str[max];
    int i;

    printf("enter the string: \n");
    gets(str);

    for (i=0;i<strlen(str);i++)
        push_char(str[i]);

    for (i=0;i<strlen(str);i++)
        str[i]=pop_char();

    printf("reversed string is %s \n",str);


return 0;



}






