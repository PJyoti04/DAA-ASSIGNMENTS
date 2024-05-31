#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

long long current_timestamp(){
    struct timeval te;
    gettimeofday(&te,NULL);
    long long milliseconds=te.tv_sec*1000LL + te.tv_usec/1000;
    return milliseconds;
}

int linearsearch(long a[],int n,int e){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==e){
            return 1;
        }
    }
    return -1;
}

void sort(long a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int binarysearch(long a[],int n,int e){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==e){
            return 1;
        }
        else if(a[mid]<e){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

void main(){
    long arr[100000];
    int element,size,choice;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the array:");
    for(int i=0;i<size;i++){
        int num=rand()%100+1;
        printf("%d\t",num);
        arr[i]=num;
    }
    printf("\nEnter the element to be searched:");
    scanf("%d",&element);
    printf("1. Linear Search\n2. Binary Search\n");
    scanf("%d",&choice);
    if(choice==1){
        long long milliseconds=current_timestamp();
        printf("Current time:%lld\n",milliseconds);
        int ans=linearsearch(arr,size,element);
        if(ans==1){
            printf("Element Found !!!!\n");
        }
        else{
            printf("Element  not Found !!!!\n");
        }
    }
    else if(choice==2){
        sort(arr,size);
        long long milliseconds=current_timestamp();
        printf("Current time:%lld\n",milliseconds);
        int ans=binarysearch(arr,size,element);
        if(ans==1){
            printf("Element Found !!!!\n");
        }
        else{
            printf("Element  not Found !!!!\n");
        }
    }
    else{
        printf("Invalid choice !!!!\n");
    }
    long long milliseconds1=current_timestamp();
    printf("Current time:%lld",milliseconds1);
}