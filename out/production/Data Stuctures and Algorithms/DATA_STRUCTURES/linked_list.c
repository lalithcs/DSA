#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
struct node
{
    int n;
    int* data;
    struct node* next;
};

struct node* head = NULL; // Global variable for the head of the linked list

void create();
void display();
void insertatbeg();
int main()
{
    int c = 1, ch;
    
    while(c)
    {
        printf("Enter choice: 1. Create 2. Display, 3.Insert at location, 4.Insert at Beginning, 5.Insert at end: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                create();
                break;
                
            case 2:
                display();
                break;
            case 3:
                insertatbeg();
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        
        printf("If you wish to continue, enter 1. Otherwise, enter 0: ");
        scanf("%d", &c);
        if(c==0)
        printf("\n Thank you!!!");
    }
    
    return 0;
}
void create()
{
    int t = 0;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Please enter n: ");
    scanf("%d", &newnode->n);
    newnode->data = (int*)malloc(newnode->n * sizeof(int));
    printf("Enter data: ");
    while(t < newnode->n)
    {
        scanf("%d", &newnode->data[t]);
        t++;
    }
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
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
        int t = 0;
        while (t < temp->n)
        {
            printf("%d ", temp->data[t]);
            t++;
        }
        printf("\n");
        
        temp = temp->next;
    }
}
void insertatbeg()
{
    int data;
    printf("Please enter the data: ");
    scanf("%d", &data);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->n = 1;
    newNode->data = (int*)malloc(sizeof(int));
    newNode->data[0] = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted at the beginning.\n");
    display();
}


