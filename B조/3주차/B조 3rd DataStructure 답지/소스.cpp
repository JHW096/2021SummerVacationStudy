#include "헤더.h"
#include<stdio.h>
#include<stdlib.h>

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(linktype* plist) {
	plist->head = NULL;
	plist->length = 0;
}

void init_queue(linktype* plist, int line) {
	Queuelist* Qnode = (Queuelist*)malloc(line * sizeof(Queuelist));
	for (int i = 0; i < line; i++) {
		if ((Qnode + i) == NULL) {
			error("init_queue 부분에서 동적할당에러");
		}
		(Qnode + i)->front = NULL;
		(Qnode + i)->rear = NULL;
		(Qnode + i)->qlink = NULL;
		plist->length++;
	}

	plist->head = Qnode;
	for (int i = 0; i < line - 1; i++) {
		(Qnode + i)->qlink = (Qnode + i + 1);
	}
}

void add_queue(linktype* plist, int num, element val) {
	linkedlist* node = (linkedlist*)malloc(sizeof(linkedlist));
	Queuelist* Qnode1 = plist->head;
	if (node == NULL) {
		error("add_queue 부분에서 동적할당에러");
	}
	node->data = val;
	node->link = NULL;
	for (int i = 0; i < num; i++) {
		Qnode1 = Qnode1->qlink;
	}
	if (Qnode1->rear == NULL) {
		Qnode1->front = node;
		Qnode1->rear = node;
	}
	else {
		Qnode1->rear->link = node;
		Qnode1->rear = node;
	}
}

void delete_queue(linktype* plist, int num) {
	Queuelist* Qnode = plist->head;
	linkedlist* node;
	for (int i = 0; i < num; i++) {
		Qnode = Qnode->qlink;
	}
	node = Qnode->front;
	Qnode->front = Qnode->front->link;
	free(node);
}

void showlist(linktype* plist) {
	Queuelist* Qnode = plist->head;
	linkedlist* node;
	int k = 0;
	for (; Qnode != NULL; Qnode = Qnode->qlink) {
		k++;
		printf("%d번째 연결리스트 : ", k);
		node = Qnode->front;
		for (; node != NULL; node = node->link) {
			printf("%d->", node->data);
		}
		printf("NULL\n");
	}
}
