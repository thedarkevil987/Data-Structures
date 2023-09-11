#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#define MAX_ARRAY 50

#define ARRAY_IMPLEMENTATION 1
#define LINKED_LIST_IMPLEMENTATION 0
#define QUEUE_IMPLEMENTATION_TYPE LINKED_LIST_IMPLEMENTATION

typedef int ListEntry;

#if QUEUE_IMPLEMENTATION_TYPE

typedef struct list
{
    ListEntry entry[MAX_ARRAY];  // Array to hold stack elements
    int size;
}List;
#else

typedef struct listnode {
    ListEntry entry;
    ListNode *next;
}ListNode;

typedef struct list {
    ListNode *head;
    int size;
}List;

#endif // QUEUE_IMPLEMENTATION_TYPE

void InitializeList(List *pl);

void InsertList(int p, ListEntry e, List *pl);

void DeleteList(int p, ListEntry *pe, List *pl);

char ListEmpty(List *pl);

char ListFull(List *pl);

int ListSize(List *pl);

void DestroyList(List *pl);

void TraverseList(List *pl, void (*pf)(ListEntry));

void RetrieveList(int p, ListEntry *pe, List *pl);

void ReplaceList(int p, ListEntry e,List *pl);

#endif // LIST_H
