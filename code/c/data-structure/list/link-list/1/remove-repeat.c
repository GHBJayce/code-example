#include <stdio.h>
#include "operation.h"

int main()
{
    DataType studentInfos[6];
    studentInfos[0] = buildStudentInfo(4, 18, "jayce");
    studentInfos[1] = buildStudentInfo(7, 19, "jack");
    studentInfos[2] = buildStudentInfo(2, 20, "jason");
    studentInfos[3] = buildStudentInfo(5, 21, "jay");
    studentInfos[4] = buildStudentInfo(2, 19, "jason");
    studentInfos[5] = buildStudentInfo(4, 18, "jayce");
    LinkList studentList = createLinkListByTailInsert(studentInfos, sizeof(studentInfos) / sizeof(studentInfos[0]));
    printLinkList(studentList);
    studentList = removeRepeatLinkList(studentList);
    printLinkList(studentList);
    return 0;
}