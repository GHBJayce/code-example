#include <stdio.h>
#include "operation.h"

linkStack *reverse(linkStack *stack)
{
    linkStack *newStack = init();
    linkStack *stackNode = stack->next;
    while (stackNode != NULL) {
        push(newStack, stackNode->data);
        stackNode = stackNode->next;
    }
    stackNode = stack->next;
    while (!isEmpty(newStack)) {
        dataType *data = getTop(newStack);
        if (data != NULL) {
            stackNode->data = *data;
            pop(newStack);
        }
        stackNode = stackNode->next;
    }
    return stack;
}

int main()
{
    linkStack *stack = init();
    dataType data1;
    data1.id = 1;
    push(stack, data1);
    dataType data2;
    data2.id = 2;
    push(stack, data2);
    dataType data3;
    data3.id = 3;
    push(stack, data3);
    printStack(stack);
    printf("\n");
    stack = reverse(stack);
    printStack(stack);
    return 0;
}