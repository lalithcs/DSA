//Max Priority Queue
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define MAX_SIZE 10
int a[MAX_SIZE];
int front=-1,rear=-1,max=0;
int isEmpty(){
    if(front==-1&&rear==-1)
        return 1;
    else
        return 0;
}
void display(){
    int i=front;
    printf("\nMax Priority Queue: ");
    while(i<=rear){
        if(a[i]!=-2){
        printf("%d ",a[i]);
        }
        i++;
    }
    printf("\n");
}
void insert(int d){
    int e=isEmpty();
    if(e){
        a[++front]=d;
        rear++;
        printf("New queue created Inserted Succefully!!\n");
    }
    else{
        a[++rear]=d;
        printf("Inserted Succefully!!\n");
    }
}
void findMax(){
    int i,j,maxe=0;
    for(i=0;i<=rear;i++){
        for(j=0;j<=rear;j++){
            if(a[i]!=-2){
                if(a[j]>=a[i]&&a[j]>=maxe)
                {
                    maxe=a[j];
                    max=j;
                }
            }
        }
    }
    printf("%d\n",max);
}
void dequeue(){
    a[max]=-2;
    printf("Max Priority element removed Succesfully!\n");
}
int main(){
    printf("***************Max Priority Queue***************\n");
    printf("---------------------MENU--------------------------\n");
    int c=1;
    while(c!=4){
        printf("1.Insert\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter Data: ");
                int data;
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                findMax();
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter Valid Option!\n");
        }
        printf("Continue?(y=1/n=0)\n");
        printf("Choice:");
        scanf("%d",&c);
        if(c==0)
            exit(0);
    }
}