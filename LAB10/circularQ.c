#include<stdio.h>
#define N 3

int CQ[N];
int F = -1;
int R = -1;

void enqueue(int y){
    if((R+1)%N == F){
        printf("Circular Queue Overflow.\n");
        return;
    }
    R = (R+1)%N;
    CQ[R] = y;
    if(F==-1)
        F=0;
}

int dequeue(){
    if(F==-1){
        printf("Circular Queue Underflow.\n");
        return -1;
    }
    else{
        int y = CQ[F];
        if(F==R)
            F = R = -1;
        else
            F = (F+1)%N;
        return y;
    }
}

void display(){
    if(F==-1){
        printf("Circular Queue Underflow.\n");
        return;
    }
    for(int i=F; i!=R; i=(i+1)%N){
        printf("%d\t",CQ[i]);
    }
    printf("%d\t",CQ[R]);
}

void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("Deleted element : %d\n",dequeue());
    printf("Deleted element : %d\n",dequeue());
    enqueue(50);
    enqueue(60);
    enqueue(70);
    display();
}


