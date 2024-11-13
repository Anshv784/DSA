#include <stdio.h>

void lqInsertion(int queue[], int *front, int *rear, int item, int Max_Size) {
    if (*rear == Max_Size - 1) {
        printf("Overflow\n");
        return;
    }
    else {
        if (*front == -1) {
            *front = 0;
            *rear = 0;
            queue[*rear] = item;
        }
        else {
            *rear = *rear + 1;
            queue[*rear] = item;
        }
    }
}

void lqDeletion(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Underflow\n");
        return;
    }
    else {
        printf("Dequeued: %d\n", queue[*front]);
        for (int i = 0; i < *rear; i++) {
            queue[i] = queue[i + 1];
        }
        (*rear)--;
        if (*rear == -1) {
            *front = -1;
        }
    }
}

void displayQueue(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[6] = {0};
    int front = -1, rear = -1;

    lqInsertion(arr, &front, &rear, 10, 6);
    lqInsertion(arr, &front, &rear, 20, 6);
    lqInsertion(arr, &front, &rear, 30, 6);
    lqInsertion(arr, &front, &rear, 40, 6);
    lqInsertion(arr, &front, &rear, 50, 6);

    displayQueue(arr, front, rear);

    lqDeletion(arr, &front, &rear);

    displayQueue(arr, front, rear);

    lqInsertion(arr, &front, &rear, 60, 6);

    displayQueue(arr, front, rear);
    return 0;
}
