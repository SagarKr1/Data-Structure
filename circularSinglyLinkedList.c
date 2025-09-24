// singly circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    node *next;
} node;

node *head;

void insertAtLast()
{
    node *temp = (node *)malloc(sizeof(node));

    if (temp == NULL)
    {
        printf("\nMemory Error : memory not allocated\n");
        return;
    }

    printf("\nEnter a data: ");
    scanf("%d", &temp->data);

    if (head == NULL)
    {
        head = temp;
        head->next = temp;
        return;
    }

    node *p = head;
    while(p->next!=head){
        p=p->next;
    }

    p->next=temp;
    temp->next=head;
}

void insertAtStart()
{
    node *temp = (node *)malloc(sizeof(node));

    if (temp == NULL)
    {
        printf("Memory Error: memory not allocated\n");
        return;
    }

    printf("\nEnter a data: ");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        head = temp;
        head->next = temp;
        return;
    }

    node *p = head;
    while(p->next!=head){
        p=p->next;
    }
    temp->next=head;
    p->next=temp;
    head=temp;
}

void insertAtPosition(int pos){
    if(pos<=0){
        printf("Invalid Input!\n");
        return;
    }
    if(pos==1){
        insertAtStart();
        return;
    }
    int length = findLength();
    if(pos==length+1){
        insertAtLast();
        return;
    }
    if(pos>length+1){
        printf("Out of Range\n");
        return;
    }

    node *temp = (node *)malloc(sizeof(node));
    if(temp==NULL){
        printf("Memory Error : memory not allocated\n");
        return;
    }

    node *p = head;

    for(int i=1;i<pos-1;i++){
        p=p->next;
    }
    printf("\nEnter a number: ");
    scanf("%d",&temp->data);
    temp->next=p->next;
    p->next=temp;
}

int findLength(){
    if(head==NULL){
        printf("Data not fount\n");
        return 0;
    }
    int n=0;
    node *temp = head;
    while(temp->next!=head){
        n++;
        printf("%d  ",temp->data);
    }
    printf('\n\n');
    return n;
}

int main()
{
    return 0;
}