//Design a program to print a lower priority process among the set of processes using binary heap.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int pid;
    int priority;
} Process;

Process heap[MAX];
int heapSize = 0;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].priority < heap[smallest].priority)
        smallest = left;

    if (right < heapSize && heap[right].priority < heap[smallest].priority)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

void insertProcess(int pid, int priority) {
    if (heapSize >= MAX) {
        printf("Heap overflow\n");
        return;
    }

    int i = heapSize++;
    heap[i].pid = pid;
    heap[i].priority = priority;

    while (i != 0 && heap[(i - 1) / 2].priority > heap[i].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Process extractMin() {
    if (heapSize <= 0) {
        printf("Heap underflow\n");
        Process p = {-1, -1};
        return p;
    }

    if (heapSize == 1) {
        return heap[--heapSize];
    }

    Process root = heap[0];
    heap[0] = heap[--heapSize];
    minHeapify(0);

    return root;
}


void printLowestPriorityProcess() {
    if (heapSize > 0) {
        Process minProcess = extractMin();
        printf("Process with the lowest priority:\n");
        printf("PID: %d, Priority: %d\n", minProcess.pid, minProcess.priority);
    } else {
        printf("No processes in the heap.\n");
    }
}


int main() {
    insertProcess(1, 5);
    insertProcess(2, 3);
    insertProcess(3, 8);
    insertProcess(4, 1);
    insertProcess(5, 6);


    printLowestPriorityProcess();

    return 0;
}
