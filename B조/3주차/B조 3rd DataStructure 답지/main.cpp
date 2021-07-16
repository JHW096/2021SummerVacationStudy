#include "헤더.h"
#include<stdio.h>
int main(void) {

	linktype list1;
	
	init(&list1);
	
	int line;
	
	printf("how many lines?\n");
	
	scanf("%d", &line);
	
	init_queue(&list1, line);
	
	printf("생성된 Queue연결리스트의 개수는 %d개 입니다.\n", list1.length);
	
	printf("\n");
	add_queue(&list1, 0, 1);
	add_queue(&list1, 0, 2);
	add_queue(&list1, 0, 3);
	add_queue(&list1, 1, 11);
	add_queue(&list1, 1, 22);
	add_queue(&list1, 1, 33);
	add_queue(&list1, 2, 111);
	add_queue(&list1, 2, 222);
	add_queue(&list1, 2, 333);
	showlist(&list1);
	printf("\n");
	delete_queue(&list1, 0);
	delete_queue(&list1, 1);
	delete_queue(&list1, 2);
	delete_queue(&list1, 2);
	showlist(&list1);
	return 0;

}