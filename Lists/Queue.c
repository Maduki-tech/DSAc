#include <stdio.h>
#include <stdlib.h>
typedef struct Queue Queue;
struct Queue {
    int size;
    int front;
    int rear;
    int *elements;
};

void enqueue(Queue **queue, int value) {
    Queue *internQueue = *queue;
    if (internQueue->rear < internQueue->size) {
        internQueue->elements[internQueue->rear] = value;
        internQueue->rear++;
    }
}

int dequeue(Queue **queue) {
    Queue *internQueue = *queue;
    if (internQueue->front < internQueue->rear) {
        int value = internQueue->elements[internQueue->front];
        internQueue->front++;
        return value;
    }
    return 0;
}
int main(int argc, char *argv[]) {
    Queue *queue = malloc(sizeof(Queue));

    queue->size = 10;
    queue->front = 0;
    queue->rear = 0;
    queue->elements = malloc(sizeof(int) * queue->size);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));


    return 0;
}
