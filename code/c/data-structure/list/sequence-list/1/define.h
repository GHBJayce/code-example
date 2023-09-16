
typedef struct
{
    int id;
    char name[8];
    int age;
} DataType;

const int Maxsize = 100;

typedef struct
{
    DataType data[Maxsize];
    int length;
} SeqList;