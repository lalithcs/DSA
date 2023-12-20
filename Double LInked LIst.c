#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node{
    int a;
    struct node* next;
    struct node* prev;
}*start=NULL,*temp=NULL,*temp1=NULL;
int h;
void create(int a){
    if(start==NULL){
        start=(struct node*)malloc(sizeof(struct node));
        struct node* temp=start;
        temp->next=temp->prev=NULL;
        temp->a=a;
        start=temp;
    }
    else{
        temp=start;
        struct node* temp1=(struct node*)malloc(sizeof(struct node));
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=temp1;
        temp1->prev=temp;
        temp1->a=a;
        temp1->next=NULL;

    }
}
void display(){
    temp=start;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("The Elements in the Doubly Linked List are:");
    while(temp!=NULL){
        printf("%d ",temp->a);
        temp=temp->next;
    }
    printf("\n");
}
void insert_at_beg(int a){
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1->next=start;
    temp1->a=a;
    temp1->prev=NULL;
    start=temp1;
    printf("Inserted Succesfully!!\n");
}
void insert_at_end(int a){
    temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1->next=NULL;
    temp1->a=a;
    temp1->prev=temp;
    temp->next=temp1;
    printf("Inserted Succesfully!!\n");
}
void insert_at_pos(int a){
    temp=start;
    while(temp->a!=a){
        if(temp==NULL){
            printf("a not found!!\n");
            break;
        }
        temp=temp->next;
    }
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1->next=temp->next;
    temp1->a=a;
    temp1->prev=temp;
    temp->next=temp1;
    printf("Inserted Succesfully!!\n");
}
void delete_at_beg(){
    temp=start;
    temp=temp->next;
    temp->prev=NULL;
    free(start);
    start=temp;
    printf("Deleted Succesfully!!");
}
void delete_at_end(){
    temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    printf("Deleted Succesfully!!");
}
void delete_at_pos(){
    temp=start;
    while(temp->a!=h){
        if(temp==NULL){
            printf("a not found!!\n");
            break;
        }
        temp=temp->next;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    printf("Deleted Succesfully!!\n");
}
int main(){
    int ch,c=1;
    while(c){
        printf("Please Enter Your Choice below:\n1.Create\n2.Display\n3.Insert at beg\n4.Insert at end\n5.Insert at pos\n6.Delete at beg\n7.Delete at end\n8.Delete at pos\n9.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                int a;
                printf("Enter the a:");
                scanf("%d",&a);
                create(a);
                break;
            }
            case 2:{
                display();
                break;
            }
            case 3:{
                int a;
                printf("Enter the a:");
                scanf("%d",&a);
                insert_at_beg(a);
                break;
            }
            case 4:{
                int a;
                printf("Enter the a:");
                scanf("%d",&a);
                insert_at_end(a);
                break;
            }
            case 5:{
                int a;
                printf("Enter the a:");
                scanf("%d",&a);
                insert_at_pos(a);
                break;
            }
            case 6:{
                delete_at_beg();
                break;
            }
            case 7:{
                delete_at_end();
                break;
            }
            case 8:{
                printf("Enter the a:");
                scanf("%d",&h);
                delete_at_pos(h);
                break;
            }
            case 9:
            exit(0);
            default:
            ("Incorrect Option!!");
        }
        printf("Do you want to continue?(y=1/n=0)\n");
        scanf("%d",&c);
    }
    return 0;

}
