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
    int index = locateSeqList(studentList, studentInfos[1]);
    printf("它的位置在第%d个\n", index);
    return 0;
}