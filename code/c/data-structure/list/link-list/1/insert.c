#include <stdio.h>
#include "operation.h"

int main()
{
    LinkList head = initLinkList();
    DataType studentInfo = buildStudentInfo(2, 20, "jack");
    DataType studentInfo1 = buildStudentInfo(3, 21, "jayce");
    head = insertLinkList(head, studentInfo, 1);
    head = insertLinkList(head, studentInfo1, 2);
    printLinkList(head);
    return 0;
}