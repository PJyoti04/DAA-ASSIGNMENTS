#include<stdio.h>
#include<stdlib.h>
int heapsize;

int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
// int size(int A[]){
//     int n=sizeof(A)/sizeof(A[0]);
//     return n;
// }
void disp(int arr[],int n)
{
    int i;
    printf("\nThe array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    
}
void max_heapify(int A[],int i){
    int l=left(i);
    int r=right(i);
    int largest;
    int heapsize;
    
    if (l<= heapsize && A[l]>=A[i])
    {
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<=heapsize && A[r]> A[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        max_heapify(A,largest);
    }
    
}
void  buildmaxHeap(int A[])
{
    int n = heapsize;
    int i;
    for(i=(n/2)-1;i>=0;i--){
        max_heapify(A,i);
    }
}
void heapsort(int A[])
{
    buildmaxHeap(A);
    int length=heapsize;
    for (int i = length - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapsize--;
        max_heapify(A, 0);
    }
    heapsize=length;
}
void read_array(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%100+1;
       // disp(arr,n);
    }
    
}

void main(){
    int A[100000];
    read_array(A,100000);
    // int A[]={16,4,10,14,7,9,3,2,8,1};
    // max_heapify(A,1
    heapsize=sizeof(A)/sizeof(A[0]);
    
    heapsort(A);
    disp(A,heapsize);
}