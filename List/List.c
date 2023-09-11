
#include "List.h"

#if QUEUE_IMPLEMENTATION_TYPE
void InitializeList(List *pl){
    pl->size = 0;
}

void InsertList(int p, ListEntry e, List *pl){
    int i;
    for(i = pl->size - 1;i >= p;i--){
        pl->entry[i + 1] = pl->entry[i];
    }
    pl->entry[p] = e;
    pl->size++;
}

void DeleteList(int p, ListEntry *pe, List *pl){
    int i;
    *pe = pl->entry[p];
    for(i = p + 1;i < pl->size;i++){
        pl->entry[i - 1] = pl->entry[i];
    }
    pl->size--;
}

char ListEmpty(List *pl){
    return !pl->size;
}

char ListFull(List *pl){
    return (pl->size == MAX_ARRAY);
}

int ListSize(List *pl){
    return pl->size;
}

void DestroyList(List *pl){
    pl->size = 0;
}

void TraverseList(List *pl, void (*pf)(ListEntry)){
    int i;
    for(i = 0;i < pl->size;i++){
        (*pf)(pl->entry[i]);
    }
}

void RetrieveList(int p, ListEntry *pe, List *pl){
    *pe = pl->entry[p];
}

void ReplaceList(int p, ListEntry e,List *pl){
    pl->entry[p] = e;
}
#else

void InitializeList(List *pl){
    pl->head = NULL;
    pl->size = 0;
}

void InsertList(int p, ListEntry e, List *pl){
    ListNode* ptemp = (ListNode*)malloc(sizeof(ListNode));
    ptemp->entry = e;
    ptemp->next = NULL;
    ListNode* ptemp2 = head;

    if(p == 0){
        ptemp->next = pl->head;
        pl->head = ptemp;
    }else{
        int i;
        for(i = 0;i < p-1;i++){
            ptemp2 = ptemp2->next;
        }
        ptemp->next = ptemp2->next;
        ptemp2->next = ptemp;
    }
    pl->size++;
}

void DeleteList(int p, ListEntry *pe, List *pl){
    ListNode* ptemp = pl->head;
    ListNode* ptemp2 = NULL;
    if(p == 0){
        *pe = pl->head->entry;
        pl->head = pl->head->next;
        free(ptemp);
    }else{
        int i;
        for(i = 0;i < p-1;i++){
            ptemp = ptemp->next;
        }
        ptemp2 = ptemp->next;
        *pe = ptemp2->entry;
        ptemp->next = ptemp->next->next;
        free(ptemp2);
    }
    pl->size--;
}

char ListEmpty(List *pl){
    return !pl->size;
}

char ListFull(List *pl){
    return 0;
}

int ListSize(List *pl){
    return pl->size;
}

void DestroyList(List *pl){
    ListNode* ptemp = pl->head;
    while(pl->head){
        pl->head = pl->head->next;
        free(ptemp);
        ptemp = pl->head;
    }
    pl->size = 0;
}

void RetrieveList(int p, ListEntry *pe, List *pl){
    ListNode* ptemp = pl->head;
    int i;
    for(i = 0;i < pl->size;i++){
        ptemp = ptemp->next;
    }
    *pe = ptemp->entry;
}

void ReplaceList(int p, ListEntry e,List *pl){
    ListNode* ptemp = pl->head;
    int i;
    for(i = 0;i < pl->size;i++){
        ptemp = ptemp->next;
    }
    ptemp->entry = e;
}

void TraverseList(List *pl, void (*pf)(ListEntry)){
    ListNode ptemp = pl->head;
    while(ptemp){
        (*pf)(ptemp->entry);
        ptemp = ptemp->next;
    }
}
#endif // QUEUE_IMPLEMENTATION_TYPE
