#include <stdio.h>
#define SIZE 500000
typedef struct { // 큐 타입
    int  data[SIZE];
    int  front, rear;
} QueueType;


void init_queue(QueueType* q)
{
    q->front = 0;
    q->rear = -1;
}

int result(QueueType* q) {
    return q->data[q->rear];
}

int end(QueueType* q)
{
    return (q->front == q->rear);
}

// 삽입 함수
void enqueue(QueueType* q, int item)
{
    q->rear = (q->rear + 1) % SIZE;
    q->data[q->rear] = item;
}

void dequeue1(QueueType* q)
{
    q->front = (q->front + 1) % SIZE;
}

int dequeue2(QueueType* q)
{
    int result = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    return result;
}

int main(void)
{
    QueueType queue;
    init_queue(&queue);
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        enqueue(&queue, i);
    }
    while (1) {
        dequeue1(&queue);
        if (end(&queue))
            break;
        enqueue(&queue, dequeue2(&queue));
        if (end(&queue))
            break;
    }
    printf("%d\n", result(&queue));
    return 0;
}
