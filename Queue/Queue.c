#include "Queue.h"

#if QUEUE_IMPLEMENTATION_TYPE

/**************************************************************************
***************************************************************************
************************ Array Implementation *****************************
***************************************************************************
**************************************************************************/

void initializeQueue(Queue *pq){
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void Append(QueueEntry e,Queue *pq){
    if((pq->rear) == (MAX_ARRAY - 1)){
        pq->rear = 0;
    }else{
        pq->rear++;
    }
    pq->entry[pq->rear] = e;
    pq->size++;
}

void Serve(QueueEntry *pe,Queue *pq){
    *pe = pq->entry[pq->front];
    if((pq->front) == (MAX_ARRAY - 1)){
        pq->front = 0;
    }else{
        pq->front++;
    }
    pq->size--;
}

char QueueEmpty(Queue *pq){
    return !pq->size;
}

char QueueFull(Queue *pq){
    return (pq->size == MAX_ARRAY);
}

int QueueSize(Queue *pq){
    return pq->size;
}

void Retrieve(QueueEntry *pe,Queue *pq){
    *pe = pq->entry[pq->front];
}

void ClearQueue(Queue *pq){
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void TraverseQueue(Queue *pq, void (*pf)(QueueEntry)){
    int counter = 0;
    int counter2 = pq->front;
    for(counter = 0;counter < pq->size;counter++){
        if(counter2 == MAX_ARRAY){
            counter2 = 0;
        }
        (*pf)(pq->entry[counter2]);
        counter2++;
    }
}

#else

/**************************************************************************
***************************************************************************
************************ LinkedList Implementation ************************
***************************************************************************
**************************************************************************/

void initializeQueue(Queue *pq){
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

void Append(QueueEntry e,Queue *pq){
    QueueNode* ptemp = (QueueNode*)malloc(sizeof(QueueNode));
    ptemp->entry = e;
    ptemp->next = NULL;
    if(pq->front == NULL){
        pq->front = ptemp;
        pq->rear = ptemp;
    }else{
        pq->rear->next = ptemp;
        pq->rear = ptemp;
    }
    pq->size++;
}

void Serve(QueueEntry *pe,Queue *pq){
    QueueNode* ptemp = pq->front;
    *pe = pq->front->entry;
    pq->front = ptemp->next;
    free(ptemp);
    pq->size--;
}

char QueueEmpty(Queue *pq){
    return !pq->size;
}

char QueueFull(Queue *pq){
    return 0;
}

int QueueSize(Queue *pq){
    return pq->size;
}

void Retrieve(QueueEntry *pe,Queue *pq){
    *pe = pq->front->entry;
}

void ClearQueue(Queue *pq){
    while(pq->front){
        pq->rear = pq->front;
        pq->front = pq->front->next;
        free(pq->rear);
    }
    pq->rear = NULL;
    pq->size = 0;
}

void TraverseQueue(Queue *pq, void (*pf)(QueueEntry)){
    QueueNode* ptemp = pq->front;
    while(ptemp){
        (*pf)(ptemp->entry);
        ptemp = ptemp->next;
    }
}

#endif // Queue_IMPLEMENTATION_TYPE
