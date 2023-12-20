#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*head=NULL,*temp=NULL,*newnode=NULL;
void create();
void insertatbeg();
void insertatloc();
void display();
void insertatend();
int n;
int main()
{
    int c,ch;
    printf("Please enter number of nodes: ");
    scanf("%d",&n);
    c=1;
    create(n);
    while(c)
    {
        printf("Please enter your place to insert at:1.Begin, 2.Certain Location, 3.End");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                insertatbeg();
                break;
            }
            case 2:
            {
                insertatloc();
                break;
            }
            case 3:
            {
                insertatend();
                break;
            }
            default:
            printf("Invalid Option!!");
        }
        printf("If you wish to continue enter 1, else 0: ");
        scanf("%d",&c);
        if(c==0)
        {
            printf("Thank you!!");
        }
    }
    return 0;
}
void create()
{
    
    int i;
    for(i=0;i<n;i++)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("Enter data:");
        scanf("%d",&(newnode->data));
        if(head==NULL)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    printf("LIST CREATED SUCCESSFULLY\n");
}
void insertatbeg()
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("Please enter the data:");
    scanf("%d",&data);
    newNode->data=data;
    newNode->next=head;
    head=newNode;
    n++;
    display();
}
void insertatloc()
{
    int data,i,pos;
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("Enter the data:");
    scanf("%d",&data);
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    temp=head;
    for(i=0;i<pos-1;i++)
    {
        if(temp!=NULL)
        {
            temp=temp->next;
        }
    }
    newNode->next=temp->next;
    temp->next=newNode;
    printf("SUCCESSFULLY ADDED ELEMENT\n");
    display();
}
void display()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Linked list elements:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertatend()
{
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        // If the list is empty, make the new node as the head
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Attach the new node at the end of the list
        temp->next = newNode;
    }
    printf("Node inserted at the end successfully.\n");
    display();
}

