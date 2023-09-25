
typedef struct
{
    int id;
} dataType;

typedef struct linkQueueNode
{
    dataType data;
    struct linkQueueNode *next;
} linkQueueNode;

typedef struct linkQueue
{
    linkQueueNode *front, *rear;
} linkQueue;