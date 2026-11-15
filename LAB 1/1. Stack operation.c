#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int top=-1;
int ele;
int stack_arr[MAX];
void push()
{
    if (top==MAX-1){
        printf("Stack is Full - Overflow");}
    else{
        top++;
        stack_arr[top]=ele;}
}
int pop()
{
    if(top==-1){
        printf("Stack is empty - Underflow");
    }

    else{
        int ele=stack_arr[top];
        top--;
        return ele;
    }
}
void print()
{
    for(int i=top;i>=0;i--)
        printf("%d\t\n",stack_arr[i]);
}
int main()
{
    int choice;
    while(1){
        printf("The coices are :\n1.Push,2.Pop,3.Print,4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d",&ele);
            push(ele);
            break;
        case 2:
            int ele2=pop();
            printf("The element poped is: %d\n",ele2);
            break;
        case 3:
            print();
            break;
        case 4:
            printf("Exiting the program..");
            exit(0);
        default:
            printf("Wrong choice entered");
        }
    }
    return 0;
}
