#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
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

int testPair(char *exp){
    char symbol, open_pair;
    int i, length = strlen(exp);
    top = NULL;

    for (i = 0; i < length; i++) {
        symbol = exp[i];
        switch (symbol) {
            case '(':
            case '{':
            case '[':
                push(symbol);
                break;
            
            case ')':
            case '}':
            case ']':
                if (top == NULL) return 0;
                else {
                    open_pair = pop();
                    if ((open_pair == '(' && symbol != ')') || (open_pair == '{' && symbol != '}') || (open_pair == '[' && symbol != ']')) return 0;
                    else break;
                }
                
        }
    }
    if (top == NULL) return 1;
    else return 0;
}

void main(void) {
    char* express = "{(A+B-3}*5[{cos(x+y)+7]*4";
    printf("%s", express);

    if (testPair(express) == 1) printf("\n\n수식의 괄호가 맞게 사용되었습니다.");
    else printf("\n\n수식의 괄호가 틀렸습니다.");

    getchar();
}