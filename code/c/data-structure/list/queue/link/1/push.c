
#include <stdio.h>
#include "operation.h"

int main()
{
    linkQueue *LQ = init();
    dataType data1 = buildData(1);
    dataType data2 = buildData(2);
    push(LQ, data1);
    push(LQ, data2);
    printLinkQueue(LQ);

    return 0;
}