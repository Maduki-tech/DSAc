#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

struct Stack {
    int maxSize;
    int top;
    int *elements;
};

void push(Stack **stack, int value) {
    Stack *internStack = *stack;
    if (internStack->top < internStack->maxSize) {
        internStack->elements[internStack->top] = value;
        internStack->top++;
    }
}

int pop(Stack **stack) {
    Stack *internStack = *stack;
    if (internStack->top > 0) {
        internStack->top--;
        int value = internStack->elements[internStack->top];
        return value;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    Stack *stack = malloc(sizeof(Stack));
    stack->maxSize = 10;
    stack->top = 0;
    stack->elements = malloc(sizeof(int) * stack->maxSize);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);

    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));

    return EXIT_SUCCESS;
}
