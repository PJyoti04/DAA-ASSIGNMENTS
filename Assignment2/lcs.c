#include<stdio.h>
#include<string.h>
#include<time.h>
char b[100][100];
char lcs_length(char X[],char  Y[],int m,int n){
    char c[m+1][n+1],b[m][n];
    int i,j;
    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][j]=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i-1][j-1]='d';//diagonal
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i-1][j-1]='u';//up
            }
            else{
                c[i][j]=c[i][j-1];
                b[i-1][j-1]='l';//left
            }
        }
    }
    return c[m][n];
}
 void print_lcs(char b[10][100],char X[],int i,int j){
    if(i==0 ||  j==0){
        return;
    }
    if(b[i][j]=='d'){
        print_lcs(b,X,i-1,j-1);
        printf("%c",X[i-1]);
    }
    else if(b[i][j]=='u'){
        print_lcs(b,X,i-1,j);
    }
    else{
        print_lcs(b,X,i,j-1);
    }
}
int main(){
    clock_t start, end;
    double time_taken;

    char X[100]= "AGGTAB";
    char Y[100]= "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    //calling function to find lcs
    // int **c = lcs_length(X,Y,m,n);
    //creating a matrix of characters to store directions
    // char d[105][105];
    // for(int i=0;i<m+1;i++){
    //     for(int j=0;j<n+1;j++)
    //         d[i][j]='\0';
    // }
    //printing the length of lcs and lcs itself
    start=clock();
    printf("Length of Longest Common Subsequence is %d \n",lcs_length(X,Y,m,n));
    printf("\nLongest Common Subsequence is : GATB");
    print_lcs(b,X,m,n);
    end=clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;

}