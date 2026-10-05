#include<stdio.h>
#include<stdlib.h>

int main(){
    char stack_arr[50];
    char exp[50];
    int top = -1;

    printf("Enter the expression: ");
    scanf("%s", exp);

    for(int i = 0; exp[i] != '\0'; i++){
        char c = exp[i];

        if(c == '('){
            stack_arr[++top] = ')';
        }
        else if(c == '['){
            stack_arr[++top] = ']';
        }
        else if (c == '{'){
            stack_arr[++top] = '}';
        }
        else if(top == -1 || c != stack_arr[top--]){
                printf("FALSE\n");
                exit(1);
        }
    }
    if(top == -1){
        printf("TRUE\n");
    }
    else{
        printf("FALSE\n");
    }

    return 0;
}
