#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define N 20

int S[N];
int TOP = -1;

void push(int x){
    S[++TOP] = x;
}

int pop(){
    return S[TOP--];
}

void main(){
    char postfix[] = "45+33+*";
    int i = 0;
    while(postfix[i] != '\0'){
        char temp = postfix[i];
        if(isdigit(temp)){
            push(temp-'0');
        }
        else{
            int op2 = pop();
            int op1 = pop();
            switch(temp){
                case '+':
                push(op1 + op2);
                break;

                case '-':
                push(op1 - op2);
                break;

                case '*':
                push(op1 * op2);
                break;

                case '/':
                push(op1 / op2);
                break;

                case '^':
                push(pow(op1,op2));
                break;
            }

        }
        i++;
    }
    printf("\nAnswer is %d", pop());
}







// '0' = 48
// '1' = 49
// '2' = 50
// '3' = 51
// '4' = 52
// '5' = 53