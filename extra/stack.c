#include<stdio.h>
#define N 3

int S[N];
int TOP = -1;

void push(int x){
    if(TOP >= N-1){
        printf("Stack overflow");
        return;
    }
    TOP++;
    S[TOP] = x;
}

int pop(){
    if(TOP==-1){
        printf("Stack underflow");
        return -1;
    }
    TOP--;
    return S[TOP+1];
}

int peek(){
    if(TOP==-1){
        printf("Stack underflow");
        return -1;
    }
    return S[TOP];
}

int peep(int i){
    if(TOP-i+1 <= -1){
        printf("Element Not Available.");
        return -1;
    }
    return S[TOP-i+1];
}

void change(int i, int x){
    if(TOP-i+1 <= -1){
        printf("Element Not Available.");
        return;
    } 
    S[TOP-i+1] = x;
}

void display(){
    if(TOP==-1){
        printf("Stack Empty.");
        return;
    }
    for(int i=TOP; i>=0; i--){
        printf("%d\t",S[i]);
    }
}

void main(){
    push(10);
    push(20);
    push(30);
    push(40);
    display();
}