#include<stdio.h>
#include<string.h>
#define N 20

char S[N];
int TOP = -1;

void push(char x){
    S[++TOP] = x;
}

char pop(){
    return S[TOP--];
}

void main(){
    char str[] = "aabcbaa";
    int i = 0;
    push('c');
    while(str[i] != 'c'){
        push(str[i]);
        i++;
    }
    i++;
    while(S[TOP] != 'c'){
        char c = pop();
        if(str[i] != c){
            printf("Invalid.\n");
            break;
        }
        i++;
    }
    if(str[i]!='\0'){
        printf("Invalid.\n");
    }
    else{
        printf("Valid");
    }
}