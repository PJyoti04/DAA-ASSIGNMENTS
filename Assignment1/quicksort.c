#include<stdio.h>
#include<stdlib.h>
void swap(int arr[],int a,int b)
{
	int temp;
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
void disp(int arr[],int p,int q)
{
    int i;
    printf("\nThe array is: ");
    for(i=p;i<=q;i++)
    {
        printf("%d\t",arr[i]);
    }
    
}

int partition(int arr[],int p,int q)
{
    // disp(arr,p,q);
	int pivot,i,temp,j;
	j=p;
	i=j-1;
	pivot=arr[q];
	for(j=p;j<=q;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
            swap(arr,i,j);
			
		}
		
	}
    swap(arr,i+1,q);
	return i+1;
}
void quicksort(int arr[],int p,int q)
{
	int pos;
	if(p<q)
	{
        disp(arr,p,q);
		pos=partition(arr,p,q);
		quicksort(arr,p,pos-1);
		quicksort(arr,pos+1,q);
	}
}


void main()
{
	int arr[50],size,i;
	printf("Enter the size:");
	scanf("%d",&size);
	printf("Enter the values:\n");
	for(i=0;i<size;i++)
	{
		printf("%d elemnt :",i+1);
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,size-1);
	printf("the sorted array is:");
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
}
