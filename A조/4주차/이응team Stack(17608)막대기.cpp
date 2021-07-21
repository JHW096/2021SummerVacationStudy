#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

typedef struct Stack {
    int top;
    int data[SIZE];
}Stack;

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int n) {
    s->data[++(s->top)] = n;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("스택공백에러");
        return 0;
    }
    return s->data[(s->top)--];
}

int count_num(Stack* s, int n) {
    int count = 0, num1 = 0, num2;
    for (int i = 0; i < n; i++) {
        num2 = pop(s);
        if (num2 > num1) {
            num1 = num2;
            count++;
        }
    }
    return count;
}

int main() {
    Stack s;
    init(&s);
    int ntest, n;
    scanf("%d", &ntest);
    for (int i = 0; i < ntest; i++) {
        scanf("%d", &n);
        push(&s, n);
    }
    printf("%d\n", count_num(&s, ntest));
    return 0;
}