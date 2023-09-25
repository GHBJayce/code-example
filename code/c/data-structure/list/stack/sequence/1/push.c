#include <stdio.h>
#include "operation.h"

int main()
{
    int ids[] = {10100, 10201, 10301};
    int size = sizeof(ids) / sizeof(ids[0]);
    seqStack stack = create(ids, size);
    dataType data = buildData(10401);
    push(&stack, data);
    printStack(&stack);
    return 0;
}