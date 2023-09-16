#include <stdio.h>
#include "operation.h"

int main()
{
    DataType studentInfos[3];
    studentInfos[0] = buildStudentInfo(1, 18, "jayce");
    studentInfos[1] = buildStudentInfo(2, 19, "jack");
    studentInfos[2] = buildStudentInfo(3, 20, "jason");
    LinkList studentList = createLinkListByEach(studentInfos, 3);
    printf("链表长度lengthLinkList调用结果: %d\n", lengthLinkList(studentList));
    printLinkList(studentList);
    int no = 2;
    Node *studentInfo = getLinkList(studentList, no);
    printf(
        "第%d个结点data:\n id: %d \n age: %d \n name: %s\n",
        no,
        studentInfo->data.id,
        studentInfo->data.age,
        studentInfo->data.name
    );
    return 0;
}