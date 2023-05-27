//Write a program to convert an postfix expression to its corresponding infix expression.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Global Variable
char stack[50];
int top=-1;
//Function to Push Elements into Stack
void push(char ch)
{
    stack[++top]=ch;
}
//Function to Pop Element From The Stack
char pop()
{
    return stack[top--];
}
//function to convert from postfix to infix
void convert(char exp[])
{
    int l,i,j=0;
    char tmp[20];
    strrev(exp);
    l=strlen(exp);
    for(i=0;i<50;i++){
        stack[i]='\0';
    }
    printf("\nThe Infix Expression is : : ");
    for(i=0;i<l;i++){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
            push(exp[i]);
        else{
            tmp[j++]=exp[i];
            tmp[j++]=pop();
        }
    }
    tmp[j]=exp[top--];
    strrev(tmp);
    puts(tmp);
}
//Main Function
int main()
{
    char exp[50];
    //taking postfix expression
    printf("\nEnter the Postfix Expression : : ");
    gets(exp);
    //calling the function to convert the expression
    convert(exp);
    return 0;
}
