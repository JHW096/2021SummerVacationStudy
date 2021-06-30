#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
typedef char element;

typedef struct stack {
	element data[max];
	int tos;
}stack;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(stack* s) {
	s->tos = -1;
}

int length(stack* s) {
	return s->tos;
}

int isEmpty(stack* s) {
	return (s->tos == -1);
}

int isFull(stack* s) {
	return (s->tos == max - 1);
}

void push(stack* s, element item) {

	if (isFull(s)) {
		error("Error : Stack is overflow..");
	}
	else {
		s->data[++(s->tos)] = item;
	}
}

element pop(stack* s) {

	if (isEmpty(s)) {
		error("Error : Stack is Empty..");
	}
	else {
		return (s->data[(s->tos)--]);
	}

}

element peek(stack* s) {
	if (isEmpty(s)) {
		error("Error : stack is Empty..");
	}
	else {
		return (s->data[s->tos]);
	}
}

int pri(char token) {

	switch (token) {
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	}
	return -1;
}

char* infix_to_postfix(char exp[]) {

	int length = strlen(exp);
	char token;

	stack s;
	init(&s);

	char* exp2 = (char*)malloc(sizeof(exp));

	int k = 0;

	for (int i = 0; i < length; i++) {

		token = exp[i];

		switch (token) {
		case '+': case '-': case '*': case '/':
			while (!isEmpty(&s) && (pri(peek(&s)) >= pri(token))) {
				exp2[k++] = pop(&s);
			}
			push(&s, token);
			break;

		case '(':
			push(&s, token);
			break;

		case ')':
			while (peek(&s) != '(') {
				exp2[k++] = pop(&s);
			}
			if (peek(&s) == '(') {
				pop(&s);
			}
			break;

		default:
			exp2[k++] = token;
			break;
		}

	}
	while (!isEmpty(&s)) {
		exp2[k++] = pop(&s);
	}
	exp2[k++] = '\0';

	return exp2;
}

int eval(char exp[]) {

	char* result;

	result = infix_to_postfix(exp);

	int op1, op2, value, i = 0;
	int len = strlen(result);
	char token;

	stack p;
	init(&p);

	for (int i = 0; i < len; i++) {

		token = result[i];

		if (token != '+' && token != '-' && token != '*' && token != '/') {
			value = token - '0';
			push(&p, value);
		}
		else {
			op2 = pop(&p);
			op1 = pop(&p);
			switch (token) {
			case '+': push(&p, op1 + op2); break;
			case '-': push(&p, op1 - op2); break;
			case '*': push(&p, op1 * op2); break;
			case '/': push(&p, op1 / op2); break;
			}
		}
	}
	return pop(&p);
}



int main(void) {

	char exp[] = "2*3-((4+5)*2)-4+2*5";
	printf("2*3-((4+5)*2)-4+2*5 = %d", eval(exp));

	return 0;
}