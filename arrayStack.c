#include <stdio.h>
#include <stdlib.h>

#define N 10

int STACK[N],top=-1;


void PUSH(){
    if(top==N-1){
        printf("          List is full\n\n");
        return;
    }
    ++top;
    int n;
    printf("Enter a data : ");
    scanf("%d",&n);
    STACK[top]=n;
}

void POP(){
    if(top==-1){
        printf(
            "            "
            "List is empty\n\n"
        );
        return;
    }
    --top;
}

int PEEK(){
    if(top==-1){
        printf(
            "            "
            "List is empty\n\n"
        );
        return -1;
    }
    return STACK[top];
}

int isEmpty(){
    if(top==-1){
        printf(
            "            "
            "List is empty\n\n"
        );
        return 1;
    }
    return 0;
}

int isFull(){
    if(top==N-1){
        printf(
            "            "
            "List is full\n\n"
        );
        return 1;
    }
    return 0;
}

int main(){

    while(1){
        printf(
            "\n\n      MENU       \n"
            "-----------------\n"
            "1. Insert a element(PUSH)\n"
            "2. Delete a element(POP)\n"
            "3. Top Element\n"
            "4. check stack is empty\n"
            "5. check stack is full\n"
            "99. Exit \n"
        );
        int choice;
        printf("\n\n        Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                PUSH();
                break;
            }
            case 2:
            {
                POP();
                break;
            }
            case 3:
            {
                printf("Last element is %d",PEEK());
                break;
            }
            case 4:
            {
                printf("check stack is empty or not ? %d\n\n",isEmpty());
                break;
            }
            case 5:
            {
                printf("check stack is full or not ? %d\n\n",isFull());
                break;
            }
            case 99:
            {
                printf("Program End");
                exit(0);
            }
            default:
            {
                printf("Invalid Input\n\n");
                break;
            }
        }
    }
    return 0;
}