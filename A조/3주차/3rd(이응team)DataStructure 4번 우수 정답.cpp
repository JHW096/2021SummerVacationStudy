#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct element {
	int key;
}element;

typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && item.key > h->heap[i - 1].key) {
		h->heap[i] = h->heap[i - 1];
		i -= 1;
	}
	h->heap[i] = item;
}

void middle(HeapType* h) {
	if (h->heap_size % 2 != 0)
		printf("%d\n", h->heap[h->heap_size / 2 + 1].key);

	else {
		if ((h->heap[h->heap_size / 2].key) > (h->heap[h->heap_size / 2 + 1].key))
			printf("%d\n", h->heap[h->heap_size / 2 + 1].key);
		else printf("%d\n", h->heap[h->heap_size / 2].key);
	}
}

int main() {
	HeapType* h;
	h = create();
	init(h);

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		element n;
		scanf("%d", &n.key);
		insert_max_heap(h, n);

		middle(h);
	}

}