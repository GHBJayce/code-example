
const int maxSize = 4;

typedef struct
{
    int id;
} dataType;

typedef struct
{
    dataType data[maxSize];
    int front, rear;
} cycleQueue;