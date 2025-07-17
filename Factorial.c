
#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if (n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int main() {
    int a,n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    if(n<0){
        printf("Factorial is not defined for negative numbers.\n ");
    }
    else{
    a = factorial(n);
    printf("Factorial of %d is %d\n",n,a);
    }
    return 0;
}
