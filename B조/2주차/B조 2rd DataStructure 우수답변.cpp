#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct linkedlist {
	element data;
	linkedlist* link;
}linkedlist;

typedef struct List {
	linkedlist* head;
	linkedlist* tail;
	int length;
}List;
//(함수)

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(List* List) //초기화
{
	List->head = NULL;
	List->tail = NULL;
	List->length = 0;

}
void add(List* List, element val) //insert_last
{
	linkedlist* p = (linkedlist*)malloc(sizeof(linkedlist));
	if (p == NULL) {
		error("동적할당 에러");
	}

	p->data = val;
	p->link = NULL;

	if (List->tail == NULL) {
		List->head = p;
		List->tail = p;
	}

	else {
		List->tail->link = p;
		List->tail = p;
	}
	List->length++;

}
void add(List* List, int pos, element val) //insert //////////
{
	linkedlist* p = (linkedlist*)malloc(sizeof(linkedlist));
	linkedlist* replace = List->head;

	if (p == NULL) {
		error("동적할당 에러");
	}

	if (pos == 0 && List->head == NULL) {
		List->head = p;
		List->tail = p;
	}
	else if (pos == 0 && List->head != NULL) {
		p->link = List->head;
		List->head = p;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			replace = replace->link;
		}
		p->data = val;
		p->link = replace->link;
		replace->link = p;
	}

}
bool contains(List* List, element val) //search
{
	for (linkedlist* p = List->head; p != NULL; p = p->link)
		if (p->data == val) return true;
	return false;
}
element get(List* List, int pos) //get
{
	linkedlist* result = List->head;
	if (pos == 0) return List->head->data;
	else {
		for (int i = 0; i < pos; i++) {
			result = result->link;
		}
		return result->data;
	}

}
void remove(List* List, int pos) //remove
{
	linkedlist* first = List->head;
	linkedlist* second = first;

	if (pos == 0) {
		List->head = List->head->link;
		free(first);
	}
	else {
		for (int i = 0; i < pos; i++) {
			second = first;
			first = first->link;
		}
		second->link = first->link;
		free(first);
	}
	List->length--;
	//pos가 예상 범위를 넘어갔을 때, List의 데이터가 없을 때.
}
int size(List* List) //get length
{
	return List->length + 1;
}
void clear(List* List) //remove all
{
	linkedlist* p = List->head;
	while (p != NULL) {
		List->head = p->link;
		free(p);
		p = List->head;
	}
	free(List->head);
	List->length = 0;
}
bool isEmpty(List* List) // return ture / false(1 / 0)
{
	if (List->head == NULL) return true;
	else return false;
}
// (challenge)2개의 연결리스트 concat + merge를 동시에 하는 함수 구현



void print_list(List* List) {
	for (linkedlist* p = List->head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main() {
	List a;
	element data;


	init(&a);
	for (int i = 0; i < 5; i++) {
		add(&a, i + 1);
	}

	print_list(&a);
	data = get(&a, 3);
	printf("\n%d", data);
	clear(&a);
	if (isEmpty(&a) == 1) printf("\nempty\n");
}