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
    studentList = deleteLinkList(studentList, 2);
    printLinkList(studentList);
    return 0;
}