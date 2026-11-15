#include<stdio.h>
#include<ctype.h>
int priority(char op){
    if(op=='*' || op=='/')
        return 2;
    else if (op=='+' || op=='-')
        return 1;
    else
        return 0;
}
int main()
{
    char stack[100],exp[100];
    int top=-1;
    printf("ENTER THE INFIX EXPRESSION: ");
    scanf("%s",&exp);
    printf("Postfix: ");
    for(int i=0;exp[i]!='\0';i++){
        char c=exp[i];
        if (isalnum(c)){
            printf("%c",c);
        }
        else if(c=='('){
            stack[++top]=c;
        }
        else if(c==')'){
            while(stack[top]!='(')
                    printf("%c",stack[top--]);
            top--;
        }
        else{
            while(top>=0 && priority(stack[top])>=priority(c))
                printf("%c",stack[top--]);
            stack[++top]=c;
        }
    }
    while(top>=0){
        printf("%c",stack[top--]);
    }
    return 0;
}
