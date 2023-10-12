#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdlib.h>

#define MAX_ARRAY 50

#define STACK_IMPLEMENTATION_TYPE ARRAY_IMPLEMENTATION
#define ARRAY_IMPLEMENTATION 1
#define LINKED_LIST_IMPLEMENTATION 0

typedef int StackEntry;

#if STACK_IMPLEMENTATION_TYPE

typedef struct stack
{
    int top;                      // Index of the top element in the stack
    StackEntry entry[MAX_ARRAY];  // Array to hold stack elements
}Stack;

#else

typedef struct stacknode
{
    StackEntry entry;
    struct StackNode *next;
}StackNode;
typedef struct stack
{
    StackNode *top;
    int size;
}Stack;

#endif // STACK_IMPLEMENTATION_TYPE

/*
InitializeStack : initialize the stack to be empty
Pre  :
    -stack is created
Post :
    -stack is initialized to be empty
*/
void InitializeStack(Stack *ps);

/*
Push : push an element to the stack
Pre  :
    -stack created and initialized
    -stack is not full
Post :
    -the item e has been stored at the top of stack
    -stack size increased by one element
*/
void Push(StackEntry e, Stack *ps);

/*
Pop : pop an element from the stack
Pre  :
    -stack created and initialized
    -stack is not empty
Post :
    -the element at the top of stack has been removed and returned in *pe
    -stack size decreased by one element
*/
void Pop(StackEntry *pe, Stack *ps);

/*
StackEmpty : return 1 if stack is empty and 0 if not
Pre  :
    -stack created and initialized
Post :
    -return 1 if stack is empty and 0 if not
*/
char StackEmpty(Stack *ps);

/*
StackFull : return 1 if stack is full and 0 if not
Pre  :
    -stack created and initialized
Post :
    -return 1 if stack is full and 0 if not
*/
char StackFull(Stack *ps);

/*
StackTop : store the top element of stack in *pe
Pre  :
    -stack created and initialized
    -stack is not empty
Post :
    -the top element of stack has been stored in *pe
*/
void StackTop(StackEntry *pe, Stack *ps);

/*
StackSize : calculate the size of stack
Pre  :
    -stack created and initialized
Post :
    -returns the size of stack
*/
int StackSize(Stack *ps);

/*
ClearStack : clear all the elements of stack
Pre  :
    -stack created and initialized
Post :
    -stack is empty
*/
void ClearStack(Stack *ps);

/*
TraverseStack : visit every element in stack and apply the passed function to it
Pre  :
    -stack created and initialized
Post :
    -applied the function to every element in stack from top to down
*/
void TraverseStack(Stack *ps, void (*pf)(StackEntry));



#endif  // STACK_ARRAY_H

