#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {      //Use of the nested struct function
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

// initialize the priority queue
void initializeQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// check if the queue is empty
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// check if the queue is full
int isFull(PriorityQueue *pq) {
    return pq->size == MAX_SIZE;
}

// enqueue with sorted insertion (smaller number = higher priority)
void enqueue(PriorityQueue *pq, int value, int priority) {
    if (isFull(pq)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    int i;
    for (i = pq->size - 1; i >= 0; i--) {
        if (pq->elements[i].priority > priority) {
            pq->elements[i + 1] = pq->elements[i];
        } else {
            break;
        }
    }
    pq->elements[i + 1].data = value;
    pq->elements[i + 1].priority = priority;
    pq->size++;
    printf("Enqueued %d with priority %d.\n", value, priority);
}

// dequeue the highest-priority element (always at index 0)
int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = pq->elements[0].data;
    for (int i = 1; i < pq->size; i++) {
        pq->elements[i - 1] = pq->elements[i];
    }
    pq->size--;
    printf("Dequeued %d.\n", value);
    return value;
}

// display the queue
void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue: \n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
    }
}

int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    display(&pq);

    dequeue(&pq);
    display(&pq);

    enqueue(&pq, 40, 0);
    display(&pq);

    return 0;
}