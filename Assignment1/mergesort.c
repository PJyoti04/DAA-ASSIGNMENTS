#include <stdio.h>
#include<stdlib.h>
#include<sys/time.h>

void merge(int A[], int low, int mid, int high) {
    int h=low,k;
    int j=mid+1,i=low;
    int B[100000];
    while((h<=mid) && (j <=high)) {
        if(A[h] <= A[j]){  
            B[i] = A[h];
            h++;
        }
        else{
            B[i]=A[j];
            j++;
        }
        i++;
    }

    if(h>mid){
        for(k=j ; k <= high; k++) {
            B[i] = A[k];
            i++;
        }
    }
    if(j>high){
        for(k=h; k <= mid; k++) {
            B[i] = A[k]; 
            i++;
        }
    }
    for(i=low;i<=high;i++)
    {
        A[i]=B[i]; 
    }
}

void mergeSort(int A[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merge(A, low, mid, high);
  }
}
void disp(int A[],int n)
{
    int i;
    printf("\nThe array is:\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    
}
void read_array(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        A[i]=rand()%2000+1;
        
    }
    
}

void main() {
  int A[100000],n;
  printf("Enter size of Array:");
  scanf("%d",&n);
  read_array(A,n);
//   disp(A,n);
  mergeSort(A, 0, n - 1);
  disp(A,n);
}