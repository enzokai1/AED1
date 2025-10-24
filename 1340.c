#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1001


typedef struct {
    int data[MAX_SIZE];
    int top;
} Pilha;


typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Fila;


typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;


void pilha_init(Pilha *p) {
    p->top = -1;
}

void pilha_push(Pilha *p, int x) {
    p->data[++(p->top)] = x;
}

int pilha_pop(Pilha *p) {
    return p->data[(p->top)--];
}

bool pilha_empty(Pilha *p) {
    return p->top == -1;
}


void fila_init(Fila *f) {
    f->front = 0;
    f->rear = -1;
    f->size = 0;
}

void fila_push(Fila *f, int x) {
    f->rear = (f->rear + 1) % MAX_SIZE;
    f->data[f->rear] = x;
    f->size++;
}

int fila_pop(Fila *f) {
    int x = f->data[f->front];
    f->front = (f->front + 1) % MAX_SIZE;
    f->size--;
    return x;
}

bool fila_empty(Fila *f) {
    return f->size == 0;
}


void pq_init(PriorityQueue *pq) {
    pq->size = 0;
}

void pq_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pq_heapify_up(PriorityQueue *pq, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (pq->data[idx] > pq->data[parent]) {
            pq_swap(&pq->data[idx], &pq->data[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

void pq_heapify_down(PriorityQueue *pq, int idx) {
    while (true) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        
        if (left < pq->size && pq->data[left] > pq->data[largest]) {
            largest = left;
        }
        if (right < pq->size && pq->data[right] > pq->data[largest]) {
            largest = right;
        }
        
        if (largest != idx) {
            pq_swap(&pq->data[idx], &pq->data[largest]);
            idx = largest;
        } else {
            break;
        }
    }
}

void pq_push(PriorityQueue *pq, int x) {
    pq->data[pq->size] = x;
    pq_heapify_up(pq, pq->size);
    pq->size++;
}

int pq_pop(PriorityQueue *pq) {
    int max = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    pq_heapify_down(pq, 0);
    return max;
}

bool pq_empty(PriorityQueue *pq) {
    return pq->size == 0;
}


int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        Pilha pilha;
        Fila fila;
        PriorityQueue pq;
        
        pilha_init(&pilha);
        fila_init(&fila);
        pq_init(&pq);
        
        bool is_pilha = true;
        bool is_fila = true;
        bool is_pq = true;
        bool impossible = false;
        
        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);
            
            if (op == 1) {
                
                pilha_push(&pilha, x);
                fila_push(&fila, x);
                pq_push(&pq, x);
            } else {
                
                
                
                if (pilha_empty(&pilha) || fila_empty(&fila) || pq_empty(&pq)) {
                    impossible = true;
                }
                
                
                if (is_pilha && !pilha_empty(&pilha)) {
                    int val = pilha_pop(&pilha);
                    if (val != x) {
                        is_pilha = false;
                    }
                }
                
                
                if (is_fila && !fila_empty(&fila)) {
                    int val = fila_pop(&fila);
                    if (val != x) {
                        is_fila = false;
                    }
                }
                
                
                if (is_pq && !pq_empty(&pq)) {
                    int val = pq_pop(&pq);
                    if (val != x) {
                        is_pq = false;
                    }
                }
            }
        }
        
        
        if (impossible) {
            printf("impossible\n");
        } else {
            int count = is_pilha + is_fila + is_pq;
            
            if (count == 0) {
                printf("impossible\n");
            } else if (count > 1) {
                printf("not sure\n");
            } else if (is_pilha) {
                printf("stack\n");
            } else if (is_fila) {
                printf("queue\n");
            } else {
                printf("priority queue\n");
            }
        }
    }
    
    return 0;
}
