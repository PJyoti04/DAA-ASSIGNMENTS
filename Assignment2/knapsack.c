#include <stdio.h>

#define MAX 100

void swap(float *a, float *b)
{
  float temp = *a;
  *a = *b;
  *b = temp;
}
void swapi(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(float arr[], int n, float p[], float w[], int it[])
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] < arr[j + 1])
      { // Change this line to sort in descending order
        swap(&arr[j], &arr[j + 1]);
        swap(&p[j], &p[j + 1]);
        swap(&w[j], &w[j + 1]);
        swapi(&it[j], &it[j + 1]);
      }
    }
  }
}

int main()
{
  int n, i;
  float maxwt;
  int item[MAX];
  float profit[MAX];
  float weight[MAX];
  float pw_ratio[MAX];

  printf("Enter the number of items: ");
  scanf("%d", &n);

  printf("Enter the profit of items\n");
  for (i = 0; i < n; i++)
  {
    printf("Profit of item %d: ", i + 1);
    scanf("%f", &profit[i]);
    item[i] = i + 1;
  }

  printf("Enter the weight of items (weights can't be 0)\n");
  for (i = 0; i < n; i++)
  {
    printf("Weight of item %d: ", i + 1);
    scanf("%f", &weight[i]);
  }

  printf("Enter the weight constraint: ");
  scanf("%f", &maxwt);

  for (i = 0; i < n; i++)
  {
    pw_ratio[i] = profit[i] / weight[i];
  }

  bubble_sort(pw_ratio, n, profit, weight, item);

  float x[MAX] = {0};
  float totalprofit = 0.0;
  int u = maxwt;

  for (i = 0; i < n; i++)
  {
    if (weight[i] > u)
      break;
    x[i] = 1.0;
    u = u - weight[i];
    totalprofit += x[i] * profit[i];
  }

  if (i < n)
  {
    x[i] = u / weight[i];
    totalprofit += x[i] * profit[i];
  }

  printf("Items taken:\n");
  for (i = 0; i < n; i++)
  {
    printf("Item %d: %.2f\n", item[i], x[i]);
  }

  printf("Total profit: %.2f\n", totalprofit);

  return 0;
}