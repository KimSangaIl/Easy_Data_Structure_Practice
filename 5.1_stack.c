#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;    //스택 원소의 자료형을 int로 정의

element stack[STACK_SIZE];  //1차원 배열 스택 선언
int top = -1;

int isEmpty() {
    if (top == -1) return 1;
    else return 0;
}

int isFull() {
    if (top == STACK_SIZE -1) return 1;
    else return 0;
}

void push(element item) {
    if (isFull()) {
        printf("\n\n Stakc is Full! \n");
        return;
    }
    else stack[++top] = item;
}

element pop() {
    if (isEmpty()) {
        printf("\n\n Stack is Empty! \n");
        return 0;
    }
    else return stack[top--];
}

element peek() {
    if (isEmpty()) {
        printf("\n\n Stack is Empty! \n");
        exit(1);
    }
    else return stack[top];
}

void printStack() {
    printf("\n Stack [ ");
    for (int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
    printf("] ");
}

void main(void) {
    element item;
    printf("\n** Stack top pop **\n");
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();

    item = peek();
    printStack();
    printf("peek => %d", item);

    item = pop();
    printStack();
    printf("\tpop => %d", item);

    item = pop();
    printStack();
    printf("\tpop => %d", item);

    item = pop();
    printStack();
    printf("\tpop => %d", item);

    getchar();
}