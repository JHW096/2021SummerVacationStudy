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
    int T; //�׽�Ʈ ���̽�
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        QueueType q;
        init_queue(&q); //ť �����
        int N, M; //N�� ������ ����, M�� ���°�� �μ�Ǿ����� �ñ��� ������ ť ���� �����ִ� ��ġ(0<=M<=N)
        scanf("%d %d", &N, &M);
        for (int j = 0; j < N; j++) {
            int data = 0; //�켱������ ���� ����
            scanf("%d", &data); //�� �켱������ �Է¹���
            enqueue(&q, data); //�Է¹��� �켱������ ť�� ����
        }
        printf("%d\n", order(&q, M)); //���°�� �μ�� �� ã�� order �Լ� ȣ��
    }
    return 0;
}
