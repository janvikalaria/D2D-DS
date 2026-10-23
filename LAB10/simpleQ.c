#include<stdio.h>
#define N 3

int Q[N];
int F = -1;
int R = -1;

void enqueue(int y){
    if(R == N-1){
        printf("Queue Overflow.");
        return;
    }
    R++;
    Q[R] = y;
    if(F == -1)
        F = 0;
}

int dequeue(){
    if(F==-1){
        printf("Queue Underflow.");
        return -1;
    }
    else{
        int y = Q[F];
        if(F==R){
            F = R = -1;
            return y;
        }
        else{
            F++;
            return y;
        }
    }
}

void display(){
    if(F==-1){
        printf("Queue Underflow.");
        return;
    }
    for(int i=F; i<=R; i++){
        printf("%d\t",Q[i]);
    }
}

void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("\nDeleted element is : %d", dequeue());
    printf("\nUpdated Queue : ");
    display();
}