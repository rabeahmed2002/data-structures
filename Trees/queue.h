#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;
    int front; 
    int rear;
    struct Node **Q;
};

void Create(struct Queue *q, int size) {
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void Enqueue(struct Queue *q, struct Node *value) {
    if (q->rear==q->size-1) {
        printf("Queue is full");
    } else {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=value;
    }
}

struct Node * Dequeue(struct Queue *q) {
    struct Node* x=NULL;
    if (q->front==q->rear)
    {
        printf("Queue is already empty");
    } else {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}

