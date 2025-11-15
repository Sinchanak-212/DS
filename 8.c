#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1) return 1;
    return 0;
}

void enqueue(int element) {
    if (isFull())
        printf("\nQueue is full\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d", element);
    }
}

int dequeue() {
    int element;

    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return -1;
    } else {
        element = items[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;

        return element;
    }
}

void display() {
    if (isEmpty())
        printf("\nEmpty Queue\n");
    else {
        int i = front;
        printf("\nFront -> %d\n", front);
        printf("Items -> ");

        while (1) {
            printf("%d ", items[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\nRear -> %d\n", rear);
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    printf("\nDeleted value = %d", dequeue());
    display();
    return 0;
}
