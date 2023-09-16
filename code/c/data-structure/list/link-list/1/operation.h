#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

DataType buildStudentInfo(int id, int age, char name[8])
{
    DataType studentInfo;
    studentInfo.id = id;
    studentInfo.age = age;
    strcpy(studentInfo.name, name);
    return studentInfo;
}

LinkList initLinkList()
{
    LinkList head;
    head = malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

int lengthLinkList(LinkList head)
{
    Node *point = head;
    int count = 0;
    while (point->next != NULL)
    {
        point = point->next;
        count++;
    }
    return count;
}

Node *getLinkList(LinkList head, int no)
{
    Node *point;
    point = head->next;
    int position = 1;
    while (point != NULL && position < no) {
        point = point->next;
        position++;
    }
    if (position == no) {
        return point;
    }
    return NULL;
}

int locateLinkList(LinkList head, DataType x)
{
    Node *locateNode;
    locateNode = head->next;
    int no = 1;
    // 为了简化运算，这里只比对id
    while (locateNode != NULL && locateNode->data.id != x.id)
    {
        locateNode = locateNode->next;
        no++;
    }
    if (locateNode->data.id == x.id) {
        return no;
    }
    return 0;
}

LinkList insertLinkList(LinkList head, DataType x, int no)
{
    Node *queryNode, *newNode;
    if (no == 1) {
        queryNode = head;
    } else {
        queryNode = getLinkList(head, no-1);
    }
    if (queryNode == NULL) {
        printf("%s\n", "插入位置有误");
        exit(EXIT_FAILURE);
    }
    newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = queryNode->next;
    queryNode->next = newNode;
    return head;
}

LinkList deleteLinkList(LinkList head, int no)
{
    Node *deleteNode, *queryNode;
    if (no == 1) {
        queryNode = head;
    } else {
        queryNode = getLinkList(head, no-1);
    }
    if (queryNode == NULL || queryNode->next == NULL) {
        printf("%s\n", "删除的位置错误");
        exit(EXIT_FAILURE);
    }
    deleteNode = queryNode->next;
    queryNode->next = deleteNode->next;
    free(deleteNode);
    return head;
}

LinkList createLinkListByEach(DataType *arr, int size)
{
    LinkList head = initLinkList();
    for (int i = 0; i < size; i++) {
        DataType item = buildStudentInfo(arr[i].id, arr[i].age, arr[i].name);
        insertLinkList(head, item, i+1);
    }
    return head;
}

LinkList createLinkListByTailInsert(DataType *arr, int size)
{
    LinkList head;
    Node *lastNode, *newNode;
    head = malloc(sizeof(Node));
    lastNode = head;
    for (int i = 0; i < size; i++) {
        DataType item = buildStudentInfo(arr[i].id, arr[i].age, arr[i].name);
        newNode = malloc(sizeof(Node));
        newNode->data = item;
        lastNode->next = newNode;
        lastNode = newNode;
    }
    lastNode->next = NULL;
    return head;
}

LinkList createLinkListByHeadInsert(DataType *arr, int size)
{
    LinkList head;
    Node *newNode;
    head = malloc(sizeof(Node));
    head->next = NULL;
    for (int i = 0; i < size; i++) {
        DataType item = buildStudentInfo(arr[i].id, arr[i].age, arr[i].name);
        newNode = malloc(sizeof(Node));
        newNode->data = item;
        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
}

LinkList removeRepeatLinkList(LinkList head)
{
    Node *searchNode, *checkNode, *deleteNode;
    searchNode = head->next;
    while (searchNode != NULL) {
        checkNode = searchNode;
        while(checkNode->next != NULL) {
            if (searchNode->data.age == checkNode->next->data.age) {
                deleteNode = checkNode->next;
                checkNode->next = deleteNode->next;
                free(deleteNode);
            } else {
                checkNode = checkNode->next;
            }
        }
        searchNode = searchNode->next;
    }
    return head;
}

void printLinkList(LinkList head)
{
    printf("\n------------\n");
    Node *item;
    item = head->next;
    int count = 0;
    while (item != NULL) {
        printf(
            "第%d个结点data:\n id: %d \n age: %d \n name: %s\n",
            count+1,
            item->data.id,
            item->data.age,
            item->data.name
        );
        count++;
        item = item->next;
    }
    printf("链表长度：%d\n------------\n\n", count);
}