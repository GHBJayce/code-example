#include <stdio.h>
#include "operation.h"

int main()
{
    SeqList studentList;
    studentList.length = 0;
    DataType studentInfo = buildStudentInfo(1, 18, "jayce");
    studentList = insertSeqList(studentList, studentInfo, 1);
    printSeqList(studentList);
    return 0;
}