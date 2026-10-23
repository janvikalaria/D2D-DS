#include<stdio.h>
#define N 5

int F = -1;
int R = -1;

int DEQ[N];

void insert_REAR(int y){
    if(R == N-1){
        printf("Queue Overflow.");
        return;
    }
    R++;
    DEQ[R] = y;
    if(F == -1)
        F = 0;
}

int delete_FRONT(){
    if(F==-1){
        printf("Queue Underflow.");
        return -1;
    }
    else{
        int y = DEQ[F];
        if(F==R)
            F = R = -1;
        else
            F++;
    return y;
    }
}

void insert_FRONT(int y){
    if(F==0){
        printf("Double Ended Queue Overflow.\n");
        return;
    }
    else{
        if(F==-1)
            F = R = 0;
        else
            F--;
    }
    DEQ[F] = y;
}

int delete_REAR(){
    if(R==-1){
        printf("Double Ended Queue Underflow.\n");
        return -1;
    }
    else{
        int y = DEQ[R];
        if(F==R)
            F = R = -1;
        else
            R--;
        return y;
    }

}

void display(){
    if(F==-1){
        printf("Double Ended Queue Underflow.\n");
        return;
    }
    for(int i=F; i<=R; i++){
        printf("%d\t",DEQ[i]);
    }     
}

void main(){
    insert_FRONT(10);
    insert_FRONT(20);
    insert_REAR(20);
    printf("Deleted element is : %d\n",delete_REAR());
    display();
}
