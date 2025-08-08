


#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>

int b[50];


void merge(int a[],int lb,int mid,int ub){
    int k=lb;
    int i=lb;
    int j=mid+1;
    while(i<=mid && j<=ub){
        if(a[i]>a[j]){
            b[k]=a[j];
            j++;
        }
        else{
            b[k]=a[i];
            i++;
        }
        k++;
    }

    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }

    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }


    for(int i=lb;i<=ub;i++){
        a[i]=b[i];
    }

}

void mergesort(int a[],int lb,int ub){
    if(lb<ub){
       int mid = (lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

int main() {
    int a[50];
    
    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < 50; i++) {
        a[i] = rand() % 100 + 1;
    }

    printf("Random 50 Elements : ");
    for (int i = 0; i < 50; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\n\n");
    int lb=0;
    int ub = (sizeof(a)/sizeof(a[0]))-1;

    // Time measurement starts
    clock_t start = clock();

    mergesort(a, lb, ub);

    // Time measurement ends
    clock_t end = clock();
    
     // Calculate time taken in milliseconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

     printf("\nRandom 50 Elements after merge sort : ");
    for(int i=lb;i<=ub;i++){
        printf("%d ",a[i]);
    }

    printf("\n\nTime taken: %.3f ms", time_taken);
    printf("\nTime modulo 1000: %.0f", fmod(time_taken, 1000));  // modulo 1000
    return 0;
}



