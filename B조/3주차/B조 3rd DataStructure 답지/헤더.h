#ifndef Header_H
#define Header_H

typedef int element;

typedef struct linkedlist {
	element data;
	linkedlist* link;
}linkedlist;

typedef struct Queuelist {
	linkedlist* front;
	linkedlist* rear;
	Queuelist* qlink;
}Queuelist;

typedef struct linktype {
	Queuelist* head;
	int length;
}linktype;

void error(const char* message);

void init(linktype* plist);

void init_queue(linktype* plist, int line);

void add_queue(linktype* plist, int num, element val);

void delete_queue(linktype* plist, int num);

void showlist(linktype* plist);
#endif