#include<stdio.h>
    #include<math.h>
    #include<ctype.h>

    #define n 20
    int top=-1;
    int value=0;
    int s[n];

    void push(int x)
    {
        s[++top]=x;
    }
    int pop()
    {
        return s[top--];
    }
    int main()
    {
        int i,temp,op1,op2;
        char p[]="546+*493/+*";
        while(p[i]!='\0')
        {
            p[i]=temp;
            if(isdigit(temp))
            {
                push(temp-'0');
            }
            else
            {
                op2=pop();
                op1=pop();
                switch (temp)
                {
                case '+':
                    value=op2+op1;
                    push(value);
                    break;
                case '-':
                    value=op2-op1;
                    push(value);
                    break;
                case '*':
                    value=op2*op1;
                    push(value);
                    break;
                case '/':
                    value=op2/op1;
                    push(value);
                    break;

                default:
                printf("enter proper choice");
                    break;
                }
            }
        }
        return pop();
        printf("%d",s[top]);


    }
