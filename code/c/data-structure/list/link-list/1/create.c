#include <stdio.h>
#include "operation.h"

int main()
{
    DataType studentInfos[2];
    studentInfos[0] = buildStudentInfo(1, 18, "jayce");
    studentInfos[1] = buildStudentInfo(2, 19, "jack");
    LinkList studentListTail = createLinkListByTailInsert(studentInfos, 2);
    printLinkList(studentListTail);
    LinkList studentListHead = createLinkListByHeadInsert(studentInfos, 2);
    printLinkList(studentListHead);
    return 0;
}