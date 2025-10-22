#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node*next;
};


struct node*create(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void add_value(struct node ** graph,int u,int v){
    struct node*p=graph[u];
    struct node*g=create(v);

    if(p==NULL){
        graph[u]=g;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=g;
    }
}

void  add_edge(struct node**graph,int u,int v){
    add_value(graph,u,v);
    add_value(graph,v,u);
    printf("Edge Established Successfully!\n");
}

void dfs_helper(struct node**graph,int*visited,int v){
    printf("%d ",v);
    visited[v]=1;   //1 == Visited.So again it will not visit
    struct node*temp=graph[v];
    while(temp!=NULL){
        if(visited[temp->data]==0){
            dfs_helper(graph,visited,temp->data);
        }
        temp=temp->next;
    }
}

 void dfs(struct node ** graph,int n,int v){
    int * visited = (int*)malloc(n*sizeof(int)); //Used array
    for(int i=0;i<n;i++){
        visited[i]=0; //0 = not visited
    }
    printf("DFS : ");
    dfs_helper(graph,visited,v);
    printf("\n");
}

int main(){
    int n=7;
    struct node ** graph = (struct node**) malloc (n*sizeof(struct node *));

    for(int i=0;i<n;i++){
        graph[i]=NULL;
    }

    add_edge(graph,1,2);
    add_edge(graph,1,3);
    add_edge(graph,2,4);
    add_edge(graph,3,4);
    add_edge(graph,3,5);
    add_edge(graph,4,5);
    add_edge(graph,4,6);

    printf("\nAdjacency List Representation:\n");
    for (int i = 1; i <n; i++) {
        printf("%d -> ", i);
        struct node* p = graph[i];
        while (p != NULL) {
            printf("%d - ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }

    printf("\n");

    dfs(graph,n,1);
    dfs(graph,n,2);

    return 0;
}
