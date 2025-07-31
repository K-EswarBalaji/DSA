// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int a[5];
    int temp;
    for(int i=0;i<5;i++){
        printf("Enter the value in %d position : ",i);
        scanf("%d",&a[i]);
    }

    for(int i=0;i<5;i++){
        printf("\nThe value in %d position : %d",i,a[i]);
    }

    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\n");
    printf("\nAscending Order : ");
    for(int i=0;i<5;i++){
        printf("\nThe value in %d position : %d",i,a[i]);
    }

    return 0;
}
