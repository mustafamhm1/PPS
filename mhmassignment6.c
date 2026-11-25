#include <stdio.h>

unsigned long long factorial_iterative(int n);
unsigned long long factorial_recursive(int n);

int main() {
    int num;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1; 
    }

    if (num < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
        printf("Without recursion: %d! = %llu\n", num, factorial_iterative(num));
        printf("With recursion: %d! = %llu\n", num, factorial_recursive(num));
    }

    return 0;
}

unsigned long long factorial_iterative(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

unsigned long long factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}
