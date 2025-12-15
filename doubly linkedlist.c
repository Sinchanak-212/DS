#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node* lptr;
struct node *rptr;
};

struct node *head=NULL;

void insert_begin(int item){
 struct node *newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=item;
 newnode->lptr=NULL;
 newnode->rptr=NULL;

 if (head==NULL)
 {
     head=newnode;
 }
 else{
     newnode->rptr=head;
    head->lptr=newnode;
    head=newnode;
 }
printf("\nNode Inserted\n");
}

void insert_last(int item)
{
 struct node *newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=item;
 newnode->lptr=NULL;
 newnode->rptr=NULL;

 if (head==NULL)
 {
     head=newnode;
 }
 else
 {
     struct node *current=head;
     while(current->rptr!=NULL)
     {
         current=current->rptr;
     }
     current->rptr=newnode;
     newnode->rptr=NULL;
     newnode->lptr=current;
 }
  printf("\nNode Inserted\n");
}

void deletefirst()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        temp=head;
        if(head->rptr==NULL)
        {
            head=NULL;
        }
        else
        {
            head=head->rptr;
            head->lptr=NULL;
        }
        free(temp);
        printf("\nNode Deleted\n");
    }

}

void delete_last()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        temp = head;
        if(temp->rptr == NULL)
        {
            head = NULL;
            free(temp);
            printf("\nNode Deleted\n");
        }
        else
        {
            while(temp->rptr != NULL)
            {
                temp = temp->rptr;
            }
            temp->lptr->rptr = NULL;
            free(temp);
            printf("\nNode Deleted\n");
        }
    }
}
void display()
{
    struct node *current;

    if(head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        current = head;
        printf("\nDoubly Linked List\n");
        while(current != NULL)
        {
            printf("%d <-> ", current->data);
            current = current->rptr;
        }
        printf("NULL\n");
    }
}

/* Main Function */
int main()
{
    int choice, item;

    while(1)
    {
        printf("\n1.Insert at Beginning");
        printf("\n2.Insert at Last");
        printf("\n3.Delete from Beginning");
        printf("\n4.Delete from Last");
        printf("\n5.Display");
        printf("\n6.Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                insert_begin(item);
                break;

            case 2:
                printf("Enter item: ");
                scanf("%d", &item);
                insert_last(item);
                break;

            case 3:
                deletefirst();
                break;

            case 4:
                delete_last();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid Choice\n");
        }
    }
    return 0;
}










