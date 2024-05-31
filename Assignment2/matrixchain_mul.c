#include <stdio.h>
#include <stdlib.h>
int p[50];
int len;
int m[50][50];
int s[50][50];
void matrix_chain_order()
{
  int n, i, j, k, l, q;
  n = len - 1;
  for (i = 1; i <= n; i++)
    m[i][i] = 0;
  for (l = 2; l <= n; l++)
  {
    for (i = 1; i <= n - l + 1; i++)
    {
      j = i + l - 1;
      m[i][j] = 999999;
      for (k = i; k <= j - 1; k++)
      {
        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
        {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
}
void print_optimal_paren(int i, int j)
{
  if (i == j)
    printf("A%d", i);
  else
  {
    printf("(");
    print_optimal_paren(i, s[i][j]);
    print_optimal_paren(s[i][j] + 1, j);
    printf(")");
  }
}
int main()
{
  int i;
  printf("Enter the length of p[] : ");
  scanf("%d", &len);
  printf("Enter the dimention of the matrices : \n");
  for (i = 0; i < len; i++)
  {
    printf("p[%d] = ", i);
    scanf("%d", &p[i]);
  }
  matrix_chain_order();
  printf("The min number of scalar multiplication needed are : %d\n", m[1][len - 1]);
  printf("The matrices after parenthesisation is : ");
  print_optimal_paren(1, len - 1);
  printf("\n");
  return 0;
}