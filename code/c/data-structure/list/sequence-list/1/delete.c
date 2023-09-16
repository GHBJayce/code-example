#include <stdio.h>
#include "operation.h"

int main()
{
    SeqList studentList;
    DataType studentInfos[3];
    studentInfos[0] = buildStudentInfo(1, 18, "jayce");
    studentInfos[1] = buildStudentInfo(2, 19, "jack");
    studentInfos[2] = buildStudentInfo(3, 20, "jason");
    studentList = createSeqList(studentInfos, 3);
    printSeqList(studentList);
    studentList = deleteSeqList(studentList, 2);
    printSeqList(studentList);
    return 0;
}