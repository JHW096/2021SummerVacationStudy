#include <stdio.h>
#include <stdlib.h>
#define SIZE 5001

typedef struct Queuetype {
    int data[SIZE];
    int front, rear;
}Queuetype;

void init(Queuetype* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queuetype* q, int n) {
    q->rear = (q->rear + 1) % SIZE;
    q->data[q->rear] = n;
}

void count_num(Queuetype* q, int ntest, int n) {
    int count, end = 0;
    printf("<");
    while (1) {
        count = 0;
        while (1) {
            if (q->data[q->front] != 0) {
                count++;
                if (count == n)
                    break;
            }
            q->front += 1;
            q->front %= (ntest + 1);
        }
        printf("%d", q->data[q->front]);
        q->data[q->front] = 0;
        end++;
        if (end == ntest) {
            printf(">\n");
            break;
        }
        printf(", ");
    }
}

int main() {
    Queuetype queue;
    init(&queue);
    int ntest, n;
    scanf("%d %d", &ntest, &n);
    for (int i = 0; i <= ntest; i++) {
        enqueue(&queue, i);
    }
    count_num(&queue, ntest, n);
    return 0;
}