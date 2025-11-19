#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function declarations
void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();

int main() {
    int choice = 0;

    while (choice != 8) {
        printf("\n************* LINKED LIST MENU *************\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position (Random Insert)\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position (Random Delete)\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: begin_insert(); break;
            case 2: last_insert(); break;
            case 3: random_insert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: display(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

//////////////////////// INSERT AT BEGINNING ////////////////////////
void begin_insert() {
    struct node *ptr;
    int item;

    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = head;
    head = ptr;

    printf("Node inserted at beginning.\n");
}

//////////////////////// INSERT AT END ////////////////////////
void last_insert() {
    struct node *ptr, *temp;
    int item;

    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
        printf("Node inserted at end.\n");
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = ptr;
    printf("Node inserted at end.\n");
}

//////////////////////// RANDOM INSERT ////////////////////////
void random_insert() {
    struct node *ptr, *temp;
    int item, pos, i = 1;

    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &item);

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    ptr->data = item;
    ptr->next = NULL;

    if (pos == 1) {
        ptr->next = head;
        head = ptr;
        printf("Node inserted at position 1.\n");
        return;
    }

    temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(ptr);
    } else {
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Node inserted at position %d.\n", pos);
    }
}

//////////////////////// DELETE FROM BEGINNING ////////////////////////
void begin_delete() {
    struct node *ptr;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    ptr = head;
    head = head->next;
    free(ptr);

    printf("Node deleted from beginning.\n");
}

//////////////////////// DELETE FROM END ////////////////////////
void last_delete() {
    struct node *ptr, *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        ptr = head;
        head = NULL;
        free(ptr);
        printf("Last node deleted.\n");
        return;
    }

    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    ptr = temp->next;
    temp->next = NULL;
    free(ptr);

    printf("Last node deleted.\n");
}

//////////////////////// RANDOM DELETE ////////////////////////
void random_delete() {
    struct node *ptr, *temp;
    int pos, i = 1;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Node deleted from position 1.\n");
        return;
    }

    temp = head;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) {
        printf("Position out of range!\n");
    } else {
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
        printf("Node deleted from position %d.\n", pos);
    }
}

//////////////////////// DISPLAY ////////////////////////
void display() {
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("\nLinked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);  // FIXED: ASCII SYMBOL
        ptr = ptr->next;
    }
    printf("NULL\n");
}
