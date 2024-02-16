#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node *next;
};

struct node *start = NULL;
int c = 0;

void create();
void InsB();
void InsM();
void InsE();
void DelB();
void DelM();
void DelE();
void search();
void display();

int main() {
    int option;
    while (1) {
        printf("1.Create a List\n2.Insert node at Beginning\n3.Insert node at Middle\n4.Insert node at End\n");
        printf("5.Delete node at Beginning\n6.Delete node at Middle\n7.Delete node at End\n8.Search an element in the List\n9.Display the List\n10.Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &option);
        switch (option) {
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
                printf("Enter a valid choice\n");
        }
        printf("\n");
    }
    return 0;
}

void create() {
    int n, i;
    printf("Enter the number of nodes = ");
    scanf("%d", &n);
    c = n;
    struct node *temp1;

    for (i = 0; i < n; i++) {
        temp1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter a: ");
        scanf("%d", &temp1->a);
        temp1->next = NULL;
        if (start == NULL) {
            start = temp1;
            temp1->next = start;
        } else {
            struct node *temp = start;
            while (temp->next != start) {
                temp = temp->next;
            }
            temp->next = temp1;
            temp1->next = start;
        }
    }
}

void InsB() {
    if (start == NULL) {
        printf("List does not exist!\n");
    } else {
        c++;
        struct node *temp1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter a to insert: ");
        scanf("%d", &temp1->a);
        temp1->next = start;
        struct node *temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = temp1;
        start = temp1;
    }
    printf("Inserted Successfully!\n");
}

void InsM() {
    int pos, i = 1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter a to insert: ");
    struct node *temp1 = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &temp1->a);
    if (start == NULL) {
        printf("List does not exist!\n");
    } else {
        c++;
        struct node *temp = start;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        temp1->next = temp->next;
        temp->next = temp1;
    }
    printf("Inserted Successfully!\n");
}

void InsE() {
    if (start == NULL) {
        printf("List does not exist!\n");
    } else {
        c++;
        struct node *temp1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter a to insert at End: ");
        scanf("%d", &temp1->a);
        temp1->next = start;
        struct node *temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = temp1;
    }
}

void DelB() {
    if (start == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    c--;
    struct node *temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }
    struct node *temp_to_delete = start;
    start = start->next;
    temp->next = start;
    free(temp_to_delete);
    printf("Deleted Successfully!\n");
}

void DelM() {
    if (start == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    int pos, i = 1;
    printf("Enter position of node to be deleted: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > c) {
        printf("Invalid position. Node not found.\n");
        return;
    }
    c--;
    if (pos == 1) {
        struct node *temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        struct node *temp_to_delete = start;
        start = start->next;
        temp->next = start;
        free(temp_to_delete);
        printf("Deleted Successfully!\n");
        return;
    }
    struct node *temp = start;
    struct node *prevnode = NULL;
    while (i < pos) {
        prevnode = temp;
        temp = temp->next;
        i++;
    }
    prevnode->next = temp->next;
    free(temp);
    printf("Deleted Successfully!\n");
}

void DelE() {
    if (start == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    c--;
    struct node *temp = start;
    struct node *prevnode = NULL;
    while (temp->next != start) {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = start;
    free(temp);
    printf("Deleted Successfully!\n");
}

void search() {
    int count = 1, flag = 0;
    int ele;
    printf("Enter element to be searched: ");
    scanf("%d", &ele);
    if (start == NULL) {
        printf("List is empty. Element not present.\n");
        return;
    }
    struct node *temp = start;
    do {
        if (temp->a == ele) {
            printf("Element found at location %d\n", count);
            flag = 1;
            break;
        }
        count++;
        temp = temp->next;
    } while (temp != start);
    if (flag == 0) {
        printf("Element not present in the List\n");
    }
}

void display() {
    printf("\nCircular Linked List: ");
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = start;
    do {
        printf("%d  ", temp->a);
        temp = temp->next;
    } while (temp != start);
    printf("Number of nodes in the current list = %d\n", c);
}
