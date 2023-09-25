
#include <stdio.h>
#include <stdlib.h>
#include "define.h"

linkQueue *init()
{
    linkQueue *LQ = (linkQueue *)malloc(sizeof(linkQueue));
    linkQueueNode *node = (linkQueueNode *)malloc(sizeof(linkQueueNode));
    node->next = NULL;
    LQ->front = node;
    LQ->rear = node;
    return LQ;
}

int isEmpty(linkQueue *LQ)
{
    if (LQ->front == LQ->rear) {
        return 1;
    }
    return 0;
}

void push(linkQueue *LQ, dataType x)
{
    linkQueueNode *newNode = (linkQueueNode *)malloc(sizeof(linkQueueNode));
    newNode->data = x;
    newNode->next = NULL;
    (LQ->rear)->next = newNode;
    LQ->rear = newNode;
}

void pop(linkQueue *LQ)
{
    if (isEmpty(LQ)) {
        printf("%s\n", "队列空");
        exit(EXIT_FAILURE);
    }
    linkQueueNode *deleteNode = LQ->front->next;
    LQ->front->next = deleteNode->next;
    if (deleteNode->next == NULL) {
        LQ->rear = LQ->front;
    }
    free(deleteNode);
}

dataType *getHead(linkQueue *LQ)
{
    if (isEmpty(LQ)) {
        return NULL;
    }
    linkQueueNode *node = LQ->front->next;
    return &(node->data);
}

void printLinkQueue(linkQueue *LQ)
{
    linkQueueNode *node = LQ->front->next;
    int count = 1;
    while (node != NULL) {
        printf(
            "第%d个结点; 数据: %d\n",
            count,
            node->data.id
        );
        count++;
        node = node->next;
    }
}

dataType buildData(int id)
{
    dataType data;
    data.id = id;
    return data;
}

linkQueue *createLinkQueue(int ids[], int size)
{
    linkQueue *LQ = init();
    for (int i = 0; i < size; i++) {
        dataType data = buildData(ids[i]);
        push(LQ, data);
    }
    return LQ;
}