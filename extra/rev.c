#include<stdio.h>
#include<string.h>
#define N 10

char S[N];
int TOP = -1;

void push(char x){
    S[++TOP] = x;
}

char pop(){
    return S[TOP--];
}

void main(){
    char str[] = "abcd";
    char ans[strlen(str)];
    int i=0;
    int j=0;
    while(str[i] != '\0'){
        push(str[i]);
        i++;
    }
    while(TOP!=-1){
        ans[j] = pop();
        j++;
    } 
    ans[j] = '\0';
    printf("Reversed string is : %s",ans);
}