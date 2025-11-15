
/* DOUBLE ENDED QUEUE */

#include <stdio.h>
#include <conio.h>
#define MAX 10

int deque[MAX];
int left = -1, right = -1;

void insert_right(void);
void insert_left(void);
void delete_right(void);
void delete_left(void);
void display(void);

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert at right");
        printf("\n2.Insert at left");
        printf("\n3.Delete from right");
        printf("\n4.Delete from left");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_right(); break;
            case 2: insert_left(); break;
            case 3: delete_right(); break;
            case 4: delete_left(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

/* INSERT AT RIGHT */
void insert_right() {
    int item;

    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("OVERFLOW\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &item);

    if (left == -1)
        left = right = 0;
    else if (right == MAX - 1)
        right = 0;
    else
        right++;

    deque[right] = item;
}

/* INSERT AT LEFT */
void insert_left() {
    int item;

    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("OVERFLOW\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &item);

    if (left == -1)
        left = right = 0;
    else if (left == 0)
        left = MAX - 1;
    else
        left--;

    deque[left] = item;
}

/* DELETE FROM RIGHT */
void delete_right() {
    if (left == -1) {
        printf("UNDERFLOW\n");
        return;
    }

    printf("Deleted element: %d\n", deque[right]);

    if (left == right)
        left = right = -1;
    else if (right == 0)
        right = MAX - 1;
    else
        right--;
}

/* DELETE FROM LEFT */
void delete_left() {
    if (left == -1) {
        printf("UNDERFLOW\n");
        return;
    }

    printf("Deleted element: %d\n", deque[left]);

    if (left == right)
        left = right = -1;
    else if (left == MAX - 1)
        left = 0;
    else
        left++;
}

/* DISPLAY */
void display() {
    int i;

    if (left == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements: ");
    i = left;

    while (1) {
        printf("%d ", deque[i]);
        if (i == right)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
