
#include <stdio.h>
#include "operation.h"

int main()
{
    int ids[] = {1,2,3};
    int size = sizeof(ids) / sizeof(ids[0]);
    cycleQueue CQ = create(ids, size);
    pop(&CQ);
    // pop(&CQ);
    // pop(&CQ);
    
    printfCycleQueue(&CQ);
    printf("队列首元素数据: %d\n", getHead(&CQ).id);
    return 0;
}