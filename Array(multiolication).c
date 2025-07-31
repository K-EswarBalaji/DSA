
#include <stdio.h>

int main(){
    int a[2][2];
    int result[2][2];
    int sum=0;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
                printf("Enter the value in %d %d position : ",i,j);
                scanf("%d",&a[i][j]);

        }
    }

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
                printf("\nThe value in %d %d position : %d",i,j,a[i][j]);
        }
    }
    printf("\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                sum=sum+a[i][k]*a[k][j];
            }
            result[i][j]=sum;
            sum=0;
        }
    }

    printf("\nThe Matrix multiplication is : \n");

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
                printf("%d\t",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

