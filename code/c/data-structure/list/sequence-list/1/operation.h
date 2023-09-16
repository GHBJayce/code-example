#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

SeqList insertSeqList(SeqList L, DataType x, int no)
{
    if (L.length >= Maxsize) {
        printf("%s\n", "表已满");
        exit(EXIT_FAILURE);
    }
    // 等同于：no <= 0 || no >= L.length + 2
    if (no < 1 || no > L.length + 1) {
        printf("%s\n", "插入位置不正确");
        exit(EXIT_FAILURE);
    }
    for (int i = L.length; i >= no; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[no - 1] = x;
    L.length++;
    return L;
}

SeqList deleteSeqList(SeqList L, int no)
{
    // 等同于：no <= 0 || no >= L.length + 1
    if (no < 1 || no > L.length) {
        printf("%s\n", "非法位置");
        exit(EXIT_FAILURE);
    }
    for (int i = no; i < L.length; i++) {
        L.data[i-1] = L.data[i];
    }
    L.length--;
    return L;
}

int locateSeqList(SeqList L, DataType x)
{
    int i = 0;
    // 为了简化运算，这里只比对DataType里的id
    while ((i < L.length) && (L.data[i].id != x.id)) {
        i++;
    }
    if (i < L.length) {
        return i + 1;
    }
    return 0;
}



DataType buildStudentInfo(int id, int age, char name[8])
{
    DataType studentInfo;
    studentInfo.id = id;
    studentInfo.age = age;
    strcpy(studentInfo.name, name);
    return studentInfo;
}

SeqList createSeqList(DataType *studentInfos, int size)
{
    SeqList L;
    L.length = 0;
    for (int i = 0; i < size; i++) {
        L = insertSeqList(L, studentInfos[i], i+1);
    }
    return L;
}

void printSeqList(SeqList L)
{
    printf("顺序表长度：%d\n", L.length);
    for (int i = 0; i < L.length; i++) {
        printf(
            "第%d个结点data:\n id: %d \n age: %d \n name: %s\n",
            i+1,
            L.data[i].id,
            L.data[i].age,
            L.data[i].name
        );
    }
}