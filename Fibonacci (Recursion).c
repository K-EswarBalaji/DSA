#include<stdio.h>
#include<stdlib.h>

int fibo(int n){
    if(n==0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}
int main(){
    int n,a;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    if(n<0){
        printf("Fibonacci is not possible");
    }
    else{
        printf("\nFibonacci Series : ");
        for (int i=0;i<n;i++){
            printf("%d ",fibo(i));
        }
    }

    return 0;
}
