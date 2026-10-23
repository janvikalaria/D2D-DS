#include<stdio.h>
#define N 5

struct PriorityQueue{
    int data;
    int priority;
};

struct PriorityQueue PQ[N];

int F = -1;
int R = -1;

void enqueue(int x, int y){
    if(R == N-1){
        printf("Priority Queue Overflow.\n");
        return;
    }
    R++;
    PQ[R].data = x;
    PQ[R].priority = y;
    if(F==-1)
        F = 0;
}

void dequeue(){
    if(F==-1){
        printf("Priority Queue Underflow.\n");
        return;
    }
    else{
        if(F==R){
            printf("Element Deleted : %d\nPriority : %d\n",PQ[F].data, PQ[F].priority);
            F = R = -1;
            return;
        }
        else{
            // Descending Priority Queue
            int max_index = F;
            for(int i = F+1; i<=R; i++){
                if(PQ[i].priority > PQ[max_index].priority){
                    max_index = i;
                }
            }
            printf("Element Deleted : %d\nPriority : %d\n",PQ[max_index].data, PQ[max_index].priority);
            for(int i=max_index; i<R; i++){
                PQ[i] = PQ[i+1];
            }
            R--;
        }
    }    
}

void display(){
    if(F==-1){
        printf("Priority Queue Underflow.\n");
        return;
    }
    printf("PRIORITY QUEUE:\n");
    for(int i=F; i<=R; i++){
        printf("{%d : %d}\n",PQ[i].data,PQ[i].priority);
    }
}


void main(){
    enqueue(10,5);
    enqueue(20,3);
    enqueue(30,10);
    dequeue();
    dequeue();
    display();
}

