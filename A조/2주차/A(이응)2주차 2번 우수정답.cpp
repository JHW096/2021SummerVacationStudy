#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000

typedef int element;
typedef struct QueueType {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = q->rear = -1;
}

int is_empty(QueueType* q) {
    if (q->front == q->rear)
        return 1;
    else return 0;
}

int is_full(QueueType* q) {
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else return 0;
}

void enqueue(QueueType* q, element data) {

    q->data[++(q->rear)] = data;
}

void dequeue(QueueType* q) {
    element item = q->data[++(q->front)];
    //return item;
}

int isMax(QueueType* q, int i) {
    for (int j = i + 1; j <= q->rear; j++) {
        if (q->data[i] < q->data[j])
            return 0;
    }
    return 1;
}

int order(QueueType* q, int n) {
    int count = 0;

    for (int i = 0; i <= q->rear; i++) {
        if (isMax(q, i) == 1) {
            dequeue(q);
            count++;
            if (i == n) return count;
        }
        else {
            enqueue(q, q->data[i]);
            dequeue(q);
            if (i == n) n = q->rear;
        }
    }
    return count;
}

int main() {
    int T; //테스트 케이스
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        QueueType q;
        init_queue(&q); //큐 만들고
        int N, M; //N은 문서의 개수, M은 몇번째로 인쇄되었는지 궁금한 문서가 큐 내에 놓여있는 위치(0<=M<=N)
        scanf("%d %d", &N, &M);
        for (int j = 0; j < N; j++) {
            int data = 0; //우선순위를 받을 변수
            scanf("%d", &data); //각 우선순위를 입력받음
            enqueue(&q, data); //입력받은 우선순위를 큐에 저장
        }
        printf("%d\n", order(&q, M)); //몇번째로 인쇄될 지 찾는 order 함수 호출
    }
    return 0;
}
