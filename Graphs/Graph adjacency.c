#include <stdio.h>
#include <stdlib.h>
#define n 4

void init(int matrix[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=0;
        }
    }
}

void addEdge(int matrix[n][n],int v,int u){
    matrix[v][u]=1;
    matrix[u][v]=1;    //For undirected graph

}

void display(int matrix[n][n]){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

}

int main(){

    int matrix[n][n];

    init(matrix);

    addEdge(matrix,0,1);
    addEdge(matrix,0,2);
    addEdge(matrix,0,3);
    addEdge(matrix,1,2);

    display(matrix);


    return 0;
}
