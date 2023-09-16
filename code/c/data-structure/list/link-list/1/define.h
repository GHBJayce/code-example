
typedef struct
{
    int id;
    char name[8];
    int age;
} DataType;

typedef struct node
{
    DataType data;
    struct node *next;
} Node, *LinkList;
