#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct stackNode {  //스택의 노드를 구조체로 정의
    element data;
    struct stackNode *link;
} stackNode;

stackNode* top; //스택의 top 노드를 지정하기 위해 포인터 top 선언

int isEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

void push(element item) {
    stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top; //삽입 노드를 top의 위에 연결
    top = temp;       //top 위치를 삽입 노드로 이동
}

element pop() {
    element item;
    stackNode* temp = top;

    if (top == NULL) {
        printf("\n\nStack is empty! \n");
        return 0;
    }
    else {
        item = temp->data;
        top = temp->link;   //top 위치를 삭제 노드 아래로 이동
        free(temp);         //삭제된 노드의 메모리 반환
        return item;        //삭제된 원소 반환
    }
}

element peek() {
    if (top == NULL) {
        printf("\n\nStack is empty!\n");
        return 0;
    }
    else return(top->data);
}

void printStack() {
    stackNode* p = top;
    printf("\n STACK [ ");
    while(p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("] ");
}

void main(void) {
    element item;
    top = NULL;
    printf("\n ** linked list stack **\n");
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