#include <stdio.h>
#include <stdlib.h>
#include "define.h"

linkStack *init()
{
    linkStack *stack = (linkStack *)malloc(sizeof(linkStack));
    stack->next = NULL;
    return stack;
}

int isEmpty(linkStack *stack)
{
    if (stack->next == NULL) {
        return 1;
    }
    return 0;
}

void push(linkStack *stack, dataType x)
{
    linkStack *newNode = (linkStack *)malloc(sizeof(linkStack));
    newNode->data = x;
    newNode->next = stack->next;
    stack->next = newNode;
}

int pop(linkStack *stack)
{
    if (!isEmpty(stack)) {
        linkStack *removeNode = stack->next;
        stack->next = removeNode->next;
        free(removeNode);
        return 1;
    }
    return 0;
}

dataType *getTop(linkStack *stack)
{
    if (isEmpty(stack)) {
        return NULL;
    }
    return &(stack->next->data);
}

void printStack(linkStack *stack)
{
    int count = 0;
    linkStack *item = stack->next;
    while (item != NULL) {
        count++;
        printf(
            "链表序号: %d; 栈数据: %d\n",
            count,
            item->data.id
        );
        item = item->next;
    }
    printf("栈结点数量: %d\n", count);
}