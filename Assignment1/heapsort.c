#include<stdio.h>
void swap(int[],int,int);
void max_heapify(int arr[],int index,int size)
{
	int largest=index;
	int left,right;
	left=2*index+1;
	right=2*index+2;
	if(left<size && arr[left]>arr[largest])
	{
		largest=left;
	}
	if(right<size && arr[right]>arr[largest])
	{
		largest=right;
	}
	if(largest!=index)
	{
		swap(arr,index,largest);
		max_heapify(arr,largest,size);
	}
}
void heapsort(int arr[],int size)
{
	int index,newsize;
	for(index=(size/2)-1;index>=0;index--)
	{
		max_heapify(arr,index,size);
	}
	for(newsize=size-1;newsize>=0;newsize--)
	{
		swap(arr,0,newsize);
		max_heapify(arr,0,newsize);
	}
}
void swap(int arr[],int a,int b)
{
	int temp;
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
void main()
{
	int size,index,arr[50];
	printf("enter the size:\t");
	scanf("%d",&size);
	printf("Enter elements:\n");
	for(index=0;index<size;index++)
	{
		printf("enter %d elements:",index+1);
		scanf("%d",&arr[index]);
	}
	heapsort(arr,size);
	printf("After sorting:\n");
	for(index=0;index<size;index++)
	{
		printf("%d\t",arr[index]);
	}
}
