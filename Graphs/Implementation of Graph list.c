



#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node *create(int data){
    struct node*newnode=(struct node*)malloc (sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void add_value(struct node**graph,int u,int v){

    struct node * h = create(v);
    struct node * p = graph[u];

    if(p==NULL){
        graph[u]=h;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=h;
    }

}

void add_edge(struct node**graph,int u,int v){
    add_value(graph,u,v);
    add_value(graph,v,u);
    printf("Edge Established Successfully! \n");
}

int main(){
    int n=5;
    struct node **graph =  (struct node**)malloc (n * sizeof(struct node *));

    for(int i=0;i<n;i++){
        graph[i]=NULL;
    }
    add_edge(graph,0,1);
    add_edge(graph,0,4);
    add_edge(graph,1,4);
    add_edge(graph,1,3);
    add_edge(graph,1,2);
    add_edge(graph,2,3);
    add_edge(graph,3,4);

    //Display

    for(int i=0;i<n;i++){
        printf("%d -> ",i);
        struct  node * p =graph[i];
        while(p!=NULL){
            printf("%d - ",p->data);
            p=p->next;
        }
        printf("NULL\n");
    }

    printf("\n");
    return 0;
}
