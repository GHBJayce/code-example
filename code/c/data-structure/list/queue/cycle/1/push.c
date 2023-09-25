
#include <stdio.h>
#include "operation.h"

int main()
{
    int ids[] = {1,2,3};
    int size = sizeof(ids) / sizeof(ids[0]);
    cycleQueue CQ = create(ids, size);
    dataType data4 = buildData(4);
    dataType data5 = buildData(5);
    pop(&CQ);
    push(&CQ, data4);
    pop(&CQ);
    push(&CQ, data5);
    
    printfCycleQueue(&CQ);
    printf("队列首元素数据: %d\n", getHead(&CQ).id);
    return 0;
}