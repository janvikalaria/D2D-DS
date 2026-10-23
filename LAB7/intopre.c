#include<stdio.h>
#include<string.h>
#define N 15

char S[N];
int TOP = -1;

void push(char x){
    S[++TOP] = x;
}

char pop(){
    return S[TOP--];
}
int G(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 3;
    else if(c=='^')
        return 6;
    else if(c=='(')
        return 0;
    else
        return 8;
}

int F(char c){
    if(c=='+' || c=='-')
        return 2;
    else if(c=='*' || c=='/')
        return 4;
    else if(c=='^')
        return 5;
    else if(c=='(')
        return 9;
    else if(c==')')
        return 0;
    else
        return 7;
}

int R(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return -1;
    else
        return 1;
}

void revpol(char infix[]){ 
    push('(');
    char polish[strlen(infix)];
    int RANK = 0;
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        char next = infix[i];
        if(TOP < 0){
            printf("Invalid");
            return;
        }
        while(G(S[TOP]) > F(next)){
            char temp = pop();
            polish[j++] = temp;
            RANK = RANK + R(temp);
            if(RANK < 1){
                printf("Invalid");
                return;
            }
        }
        if(G(S[TOP]) != F(next))
            push(next);
        else{
            char x = pop();
        } 
        i++;           
    }
    polish[j] = '\0';
    if(TOP != -1 || RANK != 1)
        printf("Invalid");
    else
        printf("Prefix Expression : %s", strrev(polish));
}

void main(){
    char infix[] = "a+(b-d)";
    char rev_infix[strlen(infix)];
    int j = 0;
    for(int i=strlen(infix)-1 ; i>=0; i--){
        if(infix[i] == ')')
            rev_infix[j++] = '(';
        else if(infix[i] == '(')
            rev_infix[j++] = ')';
        else
            rev_infix[j++] = infix[i];
    }
    rev_infix[j] = '\0';
    printf("\nReverse of infix : %s", rev_infix);
    strcat(rev_infix,")");
    revpol(rev_infix);
}