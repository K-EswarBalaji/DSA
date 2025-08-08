


#include <stdio.h>
#include <stdlib.h>

int b[100];


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
    int a[]={15,5,24,8,1,3,16,10,20};
    int lb=0;
    int ub = (sizeof(a)/sizeof(a[0]))-1;

    mergesort(a,lb,ub);

    for(int i=lb;i<=ub;i++){
        printf("%d ",a[i]);
    }

    return 0;
}

