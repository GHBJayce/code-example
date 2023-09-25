#include <stdio.h>
#include <stdlib.h>
#include "define.h"


dataType buildData(int id)
{
    dataType data;
    data.id = id;
    return data;
}

cycleQueue init()
{
    cycleQueue CQ;
    CQ.front = 0;
    CQ.rear = 0;
    return CQ;
}

int isEmpty(cycleQueue *CQ)
{
    if (CQ->front == CQ->rear) {
        return 1;
    }
    return 0;
}

int isFull(cycleQueue *CQ)
{
    if ((CQ->rear + 1) % maxSize == CQ->front) {
        return 1;
    }
    return 0;
}

int push(cycleQueue *CQ, dataType x)
{
    if (isFull(CQ)) {
        printf("队列满\n");
        exit(EXIT_FAILURE);
    }
    CQ->rear = (CQ->rear + 1) % maxSize;
    CQ->data[CQ->rear] = x;
    return 1;
}

int pop(cycleQueue *CQ)
{
    if (isEmpty(CQ)) {
        return 0;
    }
    CQ->front = (CQ->front + 1) % maxSize;
    return 1;
}

dataType getHead(cycleQueue *CQ)
{
    dataType data;
    if (isEmpty(CQ)) {
        return data;
    }
    return CQ->data[(CQ->front + 1) % maxSize];
}

cycleQueue create(int ids[], int size)
{
    cycleQueue CQ = init();
    for (int i = 0; i < size; i++) {
        dataType data = buildData(ids[i]);
        push(&CQ, data);
    }
    return CQ;
}

void printfCycleQueue(cycleQueue *CQ)
{
    printf(
        "front下标: %d; rear下标: %d; 容量: %d; 下一个空间是否已满: %d\n",
        CQ->front,
        CQ->rear,
        maxSize - 1,
        (CQ->rear + 1) % maxSize == CQ->front
    );
    int index = CQ->front + 1;
    while (!(index % maxSize == CQ->front)) {
        if (isEmpty(CQ) || (index == 0 && CQ->rear == maxSize - 1)) {
            break;
        }
        printf(
            "下标: %d; 数据: %d\n",
            index,
            CQ->data[index].id
        );
        index = (index + 1) % maxSize;
    }
}