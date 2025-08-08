
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[50];
    int temp;
    
    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < 50; i++) {
        a[i] = rand() % 100 + 1;
    }

    printf("Random 50 Elements : ");
    for (int i = 0; i < 50; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\n\n");
    
    for(int i=1;i<50;i++){
        temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    printf("\nRandom 50 Elements after insertion sort : ");
    for(int i=0;i<50;i++){
        printf("%d ",a[i]);
    }
    return 0;
}




