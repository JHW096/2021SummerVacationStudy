#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100000

typedef struct element {
	int key;
}element;

typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

//생성함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

//초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}

//삽입 함수
void insert_min_heap(HeapType* h, int item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i].key = item;
}

//삭제 함수
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) > (h->heap[child + 1].key))
			child++;
		if (temp.key <= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	HeapType* heap;
	heap = create();
	init(heap);
	int n, x;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &x);

		if (x > 0) insert_min_heap(heap, x);

		else if (x == 0) {
			if (heap->heap_size == 0) printf("0\n");
			else printf("%d\n", delete_min_heap(heap).key);

		}
	}
	return 0;
}