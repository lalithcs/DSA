#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
}*head=NULL,*newnode=NULL,*temp=NULL,*prevnode=NULL;

int c=0;

void create();
void InsB();
void InsM();
void InsE();
void DelB();
void DelM();
void DelE();
void search();
void display();

int main(){
	int option;
	while(1){
		printf("1.Create a List\n2.Insert node at Beginning\n3.Insert node at Middle\n4.Insert node at End\n");
		printf("5.Delete node at Beginning\n6.Delete node at Middle\n7.Delete node at End\n8.Search an element in the List\n9.Display the List\n10.Exit\n");
		printf("\n\nEnter your choice: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				create();
				break;
			case 2:
				InsB();
				break;
			case 3:
				InsM();
				break;
			case 4:
				InsE();
				break;
			case 5:
				DelB();
				break;
			case 6:
				DelM();
				break;
			case 7:
				DelE();
				break;
			case 8:
				search();
				break;
			case 9:
				display();
				break;
			case 10: 
				printf("Ara Ara Sayonara!");
				exit(0);
			default:
				printf("Enter valid choice\n");
		}
		printf("\n");
	}	
}

void create(){
	int n,i;
	printf("Enter number of nodes = ");
	scanf("%d",&n);
	c=n;
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&newnode->data);
		newnode->link=NULL;
		if(head==NULL){
			head=temp=newnode;
		} else {
			temp->link=newnode;
			temp=newnode;
		}
	}	
}

void InsB(){
	if(head==NULL){
		printf("List does not exist!\n");
	} else {
		c++;
		temp=head;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data to insert: ");
		scanf("%d",&newnode->data);
		newnode->link=head;
		head=newnode;
	}
	printf("Inserted Successfully!\n");
	
}

void InsM(){
	int pos,i=1;
	newnode=(struct node*)malloc(sizeof(struct node));
	temp=head;
	printf("Enter position to insert: ");
	scanf("%d",&pos);
	printf("Enter data to insert: ");
	scanf("%d",&newnode->data);
	if(head==NULL){
	printf("List does not exist!\n");
	} else {
		c++;
		
		while(i<pos-1){
			temp=temp->link;
			i++;
		}
		newnode->link=temp->link;
		temp->link=newnode;
	}
	printf("Inserted Successfully!\n");
}

void InsE(){
	if(head==NULL){
		printf("List does not exist!\n");
	} 
	else {
		c++; 
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data to insert at End: ");
		scanf("%d",&newnode->data);
		newnode->link=NULL;
		temp=head;
		while(temp->link!=NULL){
		temp=temp->link;
		}
		temp->link=newnode;
	}
}

void DelB(){
	c--;
	temp=head;
	head=head->link;
	free(temp);
}

void DelM(){
	temp=head;
	c--;
	int i=1,pos;
	printf("Enter position of node to be deleted: ");
	scanf("%d",&pos);
	while(i<pos){
		prevnode=temp;
		temp=temp->link;
		i++;
	}
	prevnode->link=temp->link;
	free(temp);
	printf("Deleted Successfully!");
}

void DelE(){
	c--;
	temp=head;
	while(temp->link!=NULL){
		prevnode=temp;
		temp=temp->link;
	}
	prevnode->link=NULL;
	free(temp);
	printf("Deleted Successfully!");

}
void search(){
	int count=1,flag;
	int ele;
	temp=head;
	printf("Enter element to be searched: ");
	scanf("%d",&ele);
	while(temp!=NULL){
		if(temp->data==ele){
			printf("Element found at location %d",count);
			flag=0;
		} else {
			flag=1;
		}
		count++;
		temp=temp->link;
	}
	if(flag==1){
		printf("Element not present in the List");
	}
	printf("\n");
}

void display(){
	printf("\nLinked List: ");
	temp=head;
	while(temp!=NULL){
		printf("%d  ",temp->data);
		temp=temp->link;
	}	
	printf("\nNumber of nodes in the current list = %d",c);
	printf("\n");
}
