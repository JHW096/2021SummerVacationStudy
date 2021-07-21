#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 1001
#define MAX_QUEUE_SIZE 10001
//큐 코드
typedef int element;
typedef struct QueueType {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, int data) {
    if (is_full(q))
        error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = data;
}

element dequeue(QueueType* q) {
    if (is_empty(q))
        error("큐가 공ㅂ개상태입니다.");
    q->front = q->front + 1 % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

//그래프 코드
typedef struct GraphType {
    int n; //정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES]; //adj_mat는 인접행렬
}GraphType;

int visited_DFS[MAX_VERTICES];
int visited_BFS[MAX_VERTICES];

void init_graph(GraphType* g) { //그래프 초기화
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
    }
}

void insert_vertex(GraphType* g, int v) { //정점 삽입 연산
    g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v) { //그래프 깊이 우선 탐색
    visited_DFS[v] = TRUE;
    printf("%d ", v);
    for (int w = 0; w <= g->n; w++) {
        if (g->adj_mat[v][w] && !visited_DFS[w])
            dfs_mat(g, w);
    }
}

void bfs_mat(GraphType* g, int v) {
    QueueType q;
    init_queue(&q);

    visited_BFS[v] = TRUE;
    printf("%d ", v);
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (int w = 0; w <= g->n; w++) {
            if (g->adj_mat[v][w] && !visited_BFS[w]) {
                visited_BFS[w] = TRUE;
                printf("%d ", w);
                enqueue(&q, w);
            }
        }
    }
}

int main() {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    init_graph(g);

    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 1; i <= N; i++)
        insert_vertex(g, i);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        insert_edge(g, a, b);
    }

    dfs_mat(g, V);
    printf("\n");
    bfs_mat(g, V);


}