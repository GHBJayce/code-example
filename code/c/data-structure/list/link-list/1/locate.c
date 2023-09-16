#include <stdio.h>
#include "operation.h"

int main()
{
    DataType studentInfos[3];
    studentInfos[0] = buildStudentInfo(1, 18, "jayce");
    studentInfos[1] = buildStudentInfo(2, 19, "jack");
    studentInfos[2] = buildStudentInfo(3, 20, "jason");
    LinkList studentList = createLinkListByEach(studentInfos, 3);
    printLinkList(studentList);
    int index = locateLinkList(studentList, studentInfos[1]);
    printf("它的位置在第%d个\n", index);
    return 0;
}