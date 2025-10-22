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

//Queue for BFS
struct node*front=NULL,*rear=NULL;

void insertion(int data){
    struct node*newnode=create(data);
    if(front==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void deletion(){
    if(front!=NULL){
        struct node*temp=front;
        front=front->next;
        temp->next=NULL;
        free(temp);
        if(front==NULL){
            rear=NULL;
        }
    }
}

int peek(){
    if(front==NULL){
        return -1;
    }
    else{
        return front->data;
    }
}

int is_empty(){
    if(front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


//Creation of Graph
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

void bfs(struct node ** graph,int n,int v){
    // Reset queue before BFS
    front = rear = NULL;

    int* visited = (int*)malloc(n * sizeof(int));
    for (int i=0;i<n;i++){
        visited[i]=0;
    }
    insertion(v); //Insertion in queue
    visited[v]=1;

    while(is_empty()==0){  //If the traversal is  completed the queue is empty
        int value=peek();
        deletion();              //After insertion remove the value from queue and add their not visited adjacent vertices
        printf("%d ",value);

        struct node * temp=graph[value];
        while(temp!=NULL){
            if(visited[temp->data]==0){
                insertion(temp->data);
                visited[temp->data]=1;
            }
            temp=temp->next;
        }
    }
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

    printf("BFS starting from node 1: ");
    bfs(graph, n, 1);

    printf("BFS starting from node 2: ");
    bfs(graph, n, 2);

    return 0;
}
