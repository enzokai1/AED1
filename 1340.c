#include <stdio.h>
#include <string.h>

#define MAX_N 1001

int stack[MAX_N];
int top;

void stack_init() { top = -1; }
int  stack_isEmpty() { return (top == -1); }
void stack_push(int x) { stack[++top] = x; }
int  stack_pop() { return stack[top--]; }

int queue[MAX_N];
int front, rear, queue_size;

void queue_init() {
    front = 0;
    rear = -1;
    queue_size = 0;
}
int queue_isEmpty() { return (queue_size == 0); }
void queue_enqueue(int x) {
    rear = (rear + 1) % MAX_N;
    queue[rear] = x;
    queue_size++;
}
int queue_dequeue() {
    int x = queue[front];
    front = (front + 1) % MAX_N;
    queue_size--;
    return x;
}

int pq[MAX_N];
int pq_size;

void pq_init() { pq_size = 0; }
int  pq_isEmpty() { return (pq_size == 0); }
void pq_add(int x) { pq[pq_size++] = x; }

int pq_remove_max() {
    if (pq_isEmpty()) return -1; 

    int max_val = -1;
    int max_idx = -1;

    for (int i = 0; i < pq_size; i++) {
        if (pq[i] > max_val) {
            max_val = pq[i];
            max_idx = i;
        }
    }

    pq[max_idx] = pq[pq_size - 1];
    pq_size--;
    
    return max_val;
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        
        stack_init();
        queue_init();
        pq_init();

        int is_stack = 1;
        int is_queue = 1;
        int is_pq = 1;

        for (int i = 0; i < n; i++) {
            int cmd, x;
            scanf("%d %d", &cmd, &x);

            if (cmd == 1) {
                stack_push(x);
                queue_enqueue(x);
                pq_add(x);
            } else { 
                
                if (is_stack) {
                    if (stack_isEmpty() || stack_pop() != x) {
                        is_stack = 0;
                    }
                }

                if (is_queue) {
                    if (queue_isEmpty() || queue_dequeue() != x) {
                        is_queue = 0;
                    }
                }

                if (is_pq) {
                    if (pq_isEmpty() || pq_remove_max() != x) {
                        is_pq = 0;
                    }
                }
            }
        }

        int total_possivel = is_stack + is_queue + is_pq;

        if (total_possivel == 0) {
            printf("impossible\n");
        } else if (total_possivel > 1) {
            printf("not sure\n");
        } else { 
            if (is_stack) {
                printf("stack\n");
            } else if (is_queue) {
                printf("queue\n");
            } else {
                printf("priority queue\n");
            }
        }
    }

    return 0;
}
