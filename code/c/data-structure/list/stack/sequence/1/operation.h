#include <stdio.h>
#include <stdlib.h>
#include "define.h"

seqStack init()
{
    seqStack stack;
    stack.top = 0;
    return stack;
}

int isEmpty(seqStack *stack)
{
    if (stack->top == 0) {
        return 1;
    }
    return 0;
}

int isFull(seqStack *stack)
{
    if (stack->top == maxSize-1) {
        return 1;
    }
    return 0;
}

int push(seqStack *stack, dataType x)
{
    if (isFull(stack)) {
        printf("%s\n", "栈已满");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->data[stack->top] = x;
    return 1;
}

int pop(seqStack *stack)
{
    if (isEmpty(stack)) {
        printf("%s\n", "栈空");
        exit(EXIT_FAILURE);
    }
    stack->top--;
    return 1;
}

dataType getTop(seqStack *stack)
{
    if (isEmpty(stack)) {
        printf("%s\n", "栈空");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

void printStack(seqStack *stack)
{
    printf("栈顶位置: %d\n", stack->top);
    int length = sizeof(stack->data) / sizeof(stack->data[1]);
    printf("栈结点数量: %d\n", length);
    for (int i = 1; i < length; i++) {
        printf(
            "栈位置: %d; 栈数据: %d\n",
            i,
            stack->data[i].id
        );
    }
}

dataType buildData(int id)
{
    dataType data;
    data.id = id;
    return data;
}

seqStack create(int ids[], int size)
{
    seqStack stack = init();
    for (int i = 0; i < size; i++) {
        dataType data = buildData(ids[i]);
        push(&stack, data);
    }
    return stack;
}