//paranthesis Checker
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define MAX 100
#define SIZE 10
char stack[SIZE],input[SIZE];
int main(){
    printf("Enter the expression:");
    scanf("%s",input);
    int i=0,top=-1;
    while(input[i]!='\0'){
        if(input[i]=='{'||input[i]=='('||input[i]=='['){
            stack[++top]=input[i];
        }
        else if(input[i]=='}'||input[i]==')'||input[i]==']'){
            if(stack[top]&&input[i]){
                top--;
            }
        }
        else{
            printf("Invalid Expression!!\n");
            exit(0);
        }
        i++;
    }
    if(stack[top]=='{'||stack[top]=='('||stack[top]=='['){
        printf("Unbalanced Expression!");
        return 0;
    }
    printf("Balanced Expression!!\n");
    return 0;

}
