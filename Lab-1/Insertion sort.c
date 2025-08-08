
#include <stdio.h>

int main() {
    int a[6]={5,4,10,1,6,2};
    int temp;

    for(int i=1;i<6;i++){
        temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    for(int i=0;i<6;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
