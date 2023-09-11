#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#define MAX_ARRAY 5

#define ARRAY_IMPLEMENTATION 1
#define LINKED_LIST_IMPLEMENTATION 0
#define QUEUE_IMPLEMENTATION_TYPE LINKED_LIST_IMPLEMENTATION

typedef int QueueEntry;

#if QUEUE_IMPLEMENTATION_TYPE

typedef struct queue
{
    QueueEntry entry[MAX_ARRAY];  // Array to hold stack elements
    int front;
    int rear;
    int size;
}Queue;

#else

typedef struct queuenode {
    QueueEntry entry;
    struct QueueNode *next;
}QueueNode;

typedef struct queue{
    QueueNode* front;
    QueueNode* rear;
    int size;
}Queue;

#endif // QUEUE_IMPLEMENTATION_TYPE

void initializeQueue(Queue *pq);

void Append(QueueEntry e,Queue *pq);

void Serve(QueueEntry *pe,Queue *pq);

char QueueEmpty(Queue *pq);

char QueueFull(Queue *pq);

int QueueSize(Queue *pq);

void Retrieve(QueueEntry *pe,Queue *pq);

void ClearQueue(Queue *pq);

void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));

#endif // QUEUE_H
