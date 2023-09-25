
typedef struct
{
    int id;
} dataType;

const int maxSize=10;

typedef struct sequenceStack
{
    dataType data[maxSize];
    int top;
} seqStack;