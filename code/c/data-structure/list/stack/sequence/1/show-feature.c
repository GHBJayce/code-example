#include <stdio.h>
#include <stdlib.h>

const int maxSize = 30;
typedef struct
{
    char data[maxSize];
    int top;
} seqStack;

seqStack init()
{
    seqStack stack;
    stack.top = 0;
    return stack;
}

void push(seqStack *stack, char str)
{
    if (stack->top >= maxSize -1) {
        printf("%s\n", "上溢");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->data[stack->top] = str;
}

void printStack(seqStack *stack)
{
    printf("栈顶位置: %d\n", stack->top);
    int length = sizeof(stack->data) / sizeof(stack->data[1]);
    int i;
    for (i = 1; i < length; i++) {
        if (stack->data[i] == 0) {
            break;
        }
        printf(
            "栈位置: %d; 栈数据: %c\n",
            i,
            stack->data[i]
        );
    }
    printf("栈结点数量: %d\n\n", i-1);
}

char getTop(seqStack *stack)
{
    return stack->data[stack->top];
}

int isEmpty(seqStack *stack)
{
    if (stack->top == 0) {
        return 1;
    }
    return 0;
}

void pop(seqStack *stack)
{
    if (!isEmpty(stack)) {
        stack->top--;
    }
}

int main()
{
    char letter;
    seqStack stack = init();
    for (letter = 'A'; letter <= 'A' + 10; letter++) {
        push(&stack, letter);
        printf("进栈数据: %c\n", letter);
    }
    printf("\n");
    while (!isEmpty(&stack)) {
        letter = getTop(&stack);
        pop(&stack);
        printf("出栈数据: %c\n", letter);
    }
    printf("\n栈顶位置: %d\n", stack.top);
    return 0;
}