// bfs implementation

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *array;
};

int isempty(struct Queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

int isfull(struct Queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int val)
{
    q->rear++;
    q->array[q->rear] = val;
}

int dequeue(struct Queue *q)
{
    int a = 0;
    q->front++;
    a = q->array[q->front];
    return a;
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.rear = q.front = 0;
    q.array = (int *)malloc(q.size * sizeof(int));

    int u;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    printf("%d", i);

    visited[i] = 1;

    enqueue(&q, i);

    while (!isempty(&q))
    {
        int u = dequeue(&q);

        for (int j = 0; j < 7; j++)
        {
            if (a[u][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}
