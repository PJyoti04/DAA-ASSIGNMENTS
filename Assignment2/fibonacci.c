#include <stdio.h>
#include<stdlib.h>
#include <time.h>

long fibonacci_recursion(int n);
long fibonacci_iteration(int n);
int fibonacci(int n, int memo[]);
int main() {
    int choice, n;
    int memo[100];
    clock_t start, end;
    double time_taken;

    
    printf("\nMenu:\n");
    printf("1. Fibonacci Series using Recursion\n");
    printf("2. Fibonacci Series using Iteration\n");
    printf("3. Fibonacci Series using Memorization\n");
    printf("4. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of terms: ");
                scanf("%d", &n);

                start = clock();
                printf("Fibonacci Series using Recursion: ");
                for (int i = 0; i < n; i++) {
                    printf("%ld ", fibonacci_recursion(i));
                }
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("\nTime taken: %f seconds\n", time_taken);
                break;

            case 2:
                printf("Enter the number of terms: ");
                scanf("%d", &n);

                start = clock();
                printf("Fibonacci Series using Iteration: ");
                for (int i = 0; i < n; i++) {
                    printf("%ld ", fibonacci_iteration(i));
                }
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("\nTime taken: %f seconds\n", time_taken);
                break;
            case 3:
                printf("Enter the number of term: ");
                scanf("%d",&n);
                // int memo[n+1];

                printf("Fibonacci series using memorization: ");
                for (int i = 0; i <= n; i++) {
                    memo[i]=-1;
                }
                start=clock();
                for (int i = 0; i <= n; i++)
                    printf("%d\t", fibonacci(i, memo));
                printf("\n");
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("\nTime taken: %f seconds\n", time_taken);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } 

    
}

long fibonacci_recursion(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}

long fibonacci_iteration(int n) {
    long a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacci(int n, int memo[]) {
    if (n <= 1)
        return n;
    else if (memo[n] != -1)
        return memo[n];
    else {
        memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo);
        return memo[n];
    }
}