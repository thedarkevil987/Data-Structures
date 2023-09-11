#include "stack.h"

#if STACK_IMPLEMENTATION_TYPE

/**************************************************************************
***************************************************************************
************************ Array Implementation *****************************
***************************************************************************
**************************************************************************/

void InitializeStack(Stack *ps){
    ps->top = 0;
}

void Push(StackEntry e, Stack *ps){
    ps->entry[ps->top++] = e;
}


void Pop(StackEntry *pe, Stack *ps){
    *pe = ps->entry[--ps->top];
}


char StackEmpty(Stack *ps){
    return (ps->top == 0);
}


char StackFull(Stack *ps){
    return (ps->top == MAX_ARRAY);
}


void StackTop(StackEntry *pe, Stack *ps){
    *pe = ps->entry[ps->top - 1];
}


int StackSize(Stack *ps){
    return ps->top;
}


void ClearStack(Stack *ps){
    ps->top = 0;
}


void TraverseStack(Stack *ps, void (*pf)(StackEntry)){
    int counter = 0;
    for(counter = (ps->top) - 1;counter >= 0;counter--)
        (*pf)(ps->entry[counter]);
}

#else

/**************************************************************************
***************************************************************************
************************ LinkedList Implementation ************************
***************************************************************************
**************************************************************************/

void InitializeStack(Stack *ps){
    ps->top = NULL;
    ps->size = 0;
}

void Push(StackEntry e, Stack *ps){

    StackNode* ptemp = (StackNode*)malloc(sizeof(StackNode));
    ptemp->entry = e;
    ptemp->next = NULL;

    ptemp->next = ps->top;
    ps->top = ptemp;
    ps->size++;
}

void Pop(StackEntry *pe, Stack *ps){
    StackNode* ptemp = ps->top;
    *pe = ptemp->entry;
    ps->top = ptemp ->next;
    free(ptemp);
    ps->size--;
}

char StackEmpty(Stack *ps){
    return (ps->size == 0);
}

char StackFull(Stack *ps){
    return 0;
}

void StackTop(StackEntry *pe, Stack *ps){
    *pe = ps->top->entry;
}

int StackSize(Stack *ps){
    return ps->size;
}

void ClearStack(Stack *ps){
    StackNode* ptemp = NULL;
    while(ps->top){
        ptemp = ps->top;
        ps->top = ps->top->next;
        free(ptemp);
    }
    ps->size = 0;
}

void TraverseStack(Stack *ps, void (*pf)(StackEntry)){
    StackNode* ptemp = ps->top;
    while(ptemp){
        (*pf)(ptemp->entry);
        ptemp = ptemp->next;
    }
}

#endif // STACK_IMPLEMENTATION_TYPE
