#include <stdio.h>

void cqInsertion(int queue[], int *front, int *rear, int item, int Max_Size) {
    if ((*rear + 1) % Max_Size == *front) {
        printf("Overflow\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
        *rear = 0;
        queue[*rear] = item;
    } else {
        *rear = (*rear + 1) % Max_Size;
        queue[*rear] = item;
    }
}

void cqDeletion(int queue[], int *front, int *rear, int Max_Size) {
    if (*front == -1) {
        printf("Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[*front]);
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % Max_Size;
    }
}

void displayQueue(int queue[], int front, int rear, int Max_Size) {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % Max_Size;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int arr[6] = {0};
    int front = -1, rear = -1;
    int Max_Size = 6;

    cqInsertion(arr, &front, &rear, 10, Max_Size);
    cqInsertion(arr, &front, &rear, 20, Max_Size);
    cqInsertion(arr, &front, &rear, 30, Max_Size);
    cqInsertion(arr, &front, &rear, 40, Max_Size);
    cqInsertion(arr, &front, &rear, 50, Max_Size);

    displayQueue(arr, front, rear, Max_Size);

    cqDeletion(arr, &front, &rear, Max_Size);

    displayQueue(arr, front, rear, Max_Size);

    cqInsertion(arr, &front, &rear, 60, Max_Size);

    displayQueue(arr, front, rear, Max_Size);
    return 0;
}
