#include <stdio.h>

#define QUEUE_MAX_SIZE 15

struct Queue {
    char arr[QUEUE_MAX_SIZE];
    int back;
    int front;
};

void enqueue(struct Queue *q, char ch) {
    if (q->back < QUEUE_MAX_SIZE) {
        q->arr[q->back] = ch;
        q->back++;
    }
}

void dequeue(struct Queue *q) {
    if (q->front < QUEUE_MAX_SIZE) {
        q->front++;
    }
}

void print_queue(struct Queue q, const char * format) {
    for (int i = q.front + 1; i < q.back; i++) {
        printf(format, q.arr[i]);
    }
}

int main() {

    struct Queue queue;
    queue.front = -1;
    queue.back = 0;

    int N = 0;

    printf("Enter number of characters:");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char val = ' ';
        printf("Enter %d char:", i + 1);
        scanf(" %c", &val);

        enqueue(&queue, val);
    }

    printf("\nEntered queue: ");
    print_queue(queue, "%c ");

    struct Queue new_queue;
    new_queue.front = -1;
    new_queue.back = 0;

    for (int i = queue.front + 1; i < queue.back; i++) {
        if (queue.arr[i] == 'S') {
            enqueue(&new_queue, i + 1);
        }
    }

    printf("\nNew queue:");
    print_queue(new_queue, "S[%d] ");

    int M = 0;

    printf("\nEnter number of elements to delete from entered queue:");
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        dequeue(&queue);
    }

    printf("Deletion completed. Final queue:");
    print_queue(queue, "%c ");

    return 0;
}