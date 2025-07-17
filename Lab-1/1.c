#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[50];
    int n,num,index,s;
    printf("Number of elements in Array : ");
    scanf("%d",&n);
    if (n>50){
        printf("Overflow of Array");
    }
    else{
        for(int i =0;i<=n-1;i++){
            printf("Enter the value at %d index : ",i);
            scanf("%d",&a[i]);
        }
        for (int i=0;i<=n-1;i++){
            printf("%d\n",a[i]);
        }
        // Insertion
        printf("Enter the number you want to insert : ");
        scanf("%d",&num);
        printf("Enter the index to insert an element in Array : ");
        scanf("%d",&index);
        if(index<0 || index>n+1){ //We cannot insert element by giving gap in an array
            printf("Invalid Position\n");
        }
        else{
            for (int i=n-1;i>=index;i--){
                a[i+1]=a[i];
            }
            a[index]=num;
            n++;
            for (int i=0;i<=n-1;i++){
                printf("%d\n",a[i]);
            }
        }

        // Delection
        printf("Enter the index to delete the element in Array : ");
        scanf("%d",&index);
        if(index<0 || index>n+1){ //We cannot insert element by giving gap in an array
            printf("Invalid Position\n");
        }
        else{
            for (int i=index+1;i<=n-1;i++){
                a[i-1]=a[i];
            }
            n--;
            for (int i=0;i<=n-1;i++){
                printf("%d\n",a[i]);
            }
        }

        // Searching
        printf("Enter the element to search : ");
        scanf("%d",&s);
        int found=0;
        for (int i=0;i<=n-1;i++){
            if(a[i]==s){
                printf("Element Founded at index %d \n",i);
                found=1;
                break;
            }

        }
        if(found==0){
                printf("Element is not founded in array\n");
        }

        //Update
        a[3]=4;
        printf("Array after updating value at index 3 : ");
        for (int i=0;i<=n-1;i++){
                printf("%d ",a[i]);
            }

    }
    return 0;

}
