#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
long long time1,time2;
long long current_timestamp(){
    struct timeval te;
    gettimeofday(&te,NULL);
    long long milliseconds=te.tv_sec*1000LL + te.tv_usec/1000;
    return milliseconds;
}

void disp(int arr[],int n)
{
    int i;
    printf("\nThe array is:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    
}

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
    // time1=current_timestamp();
    // printf("\nBefore execution:-%lld",time1);
  if (low < high) {
    int mid = (low + high) / 2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merge(A, low, mid, high);
  }
    // time2=current_timestamp();
    // printf("\nAfter execution:-%lld",time2);
  
}


void insertionsort(int a[], int n) {
    int i, j, key,arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=a[i];
    }
    time1=current_timestamp();
    printf("\nBefore execution:-%lld",time1);
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    time2=current_timestamp();
    printf("\nAfter execution:-%lld",time2);
    //disp(arr,n);
}

void bubblesort(int a[], int n) {
    int i, j, temp,arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=a[i];
    }
    time1=current_timestamp();
    printf("\nBefore execution:-%lld",time1);
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    time2=current_timestamp();
    printf("\nAfter execution:-%lld",time2);

    //disp(arr, n);
}

void selectionsort(int a[],int n){
    int i, j, min_idx, temp,arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=a[i];
    }
    time1=current_timestamp();
    printf("\nBefore execution:-%lld",time1);
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    time2=current_timestamp();
    printf("\nAfter execution:-%lld",time2);
    //disp(arr, n);
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


void main()
{
    int a[100000],n,choice;
    printf("\nEnter the size of the array:");
    scanf("%d",&n);

    read_array(a,n);
    printf("\n1.Bubble sort\n2.Selection Sort\n3.Insertion sort\n4.Mergesort\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            
            bubblesort(a,n);
            break;
        case 2:selectionsort(a,n);
            break;
        case 3:insertionsort(a,n);
            break;
        case 4:
            time1=current_timestamp();
            printf("\nBefore execution:-%lld",time1);
            mergeSort(a,0,n-1);
            time2=current_timestamp();
            printf("\nAfter execution:-%lld",time2);
            break;
        default:
            printf("Invalid choice!!!");
    }
    printf("\nDifference:%lld",(time2-time1)/1000);
}