#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
int INT_MIN = -111;
typedef struct
{
  int arr[MAX_SIZE];
  int heap_size;
} heap;

int left(int i)
{
  return 2 * i + 1;
}

int right(int i)
{
  return 2 * i + 2;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Max_Heapify(heap *A, int i)
{
  int l = left(i);
  int r = right(i);
  int largest;

  if (l < A->heap_size && A->arr[l] > A->arr[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if (r < A->heap_size && A->arr[r] > A->arr[largest])
  {
    largest = r;
  }

  if (largest != i)
  {
    swap(&A->arr[i], &A->arr[largest]);
    Max_Heapify(A, largest);
  }
}

void Build_Max_Heap(heap *A)
{
  int i;
  for (i = A->heap_size / 2 - 1; i >= 0; i--)
  {
    Max_Heapify(A, i);
  }
}

int Maximum(heap *A)
{
  return A->arr[0];
}

int Heap_Extract_Max(heap *A)
{
  if (A->heap_size < 1)
  {
    printf("Heap Underflow");
    exit(1);
  }
  int max = A->arr[0];
  A->arr[0] = A->arr[A->heap_size - 1];
  A->heap_size--;
  Max_Heapify(A, 0);
  return max;
}

void Heap_Increase_Key(heap *A, int i, int key)
{
  if (key < A->arr[i])
  {
    printf("New key is smaller than current key");
    return;
  }
  A->arr[i] = key;
  while (i > 0 && A->arr[(i - 1) / 2] < A->arr[i])
  {
    swap(&A->arr[i], &A->arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

void Max_Heap_Insert(heap *A, int key)
{
  A->heap_size++;
  A->arr[A->heap_size - 1] = INT_MIN;
  Heap_Increase_Key(A, A->heap_size - 1, key);
}

int main()
{
  int i = 0;
  heap A;
  A.heap_size = 0;

  Max_Heap_Insert(&A, 4);
  Max_Heap_Insert(&A, 8);
  Max_Heap_Insert(&A, 2);
  Max_Heap_Insert(&A, 10);
  Max_Heap_Insert(&A, 6);

  printf("Maximum element extracted: %d\n", Heap_Extract_Max(&A));

  printf("Remaining elements in the priority queue: ");
  for (i = 0; i < A.heap_size; i++)
  {
    printf("%d ", A.arr[i]);
  }
  printf("\n");

  return 0;
}