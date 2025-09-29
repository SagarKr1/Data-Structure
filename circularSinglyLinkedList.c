// singly circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;


int findLength()
{
    if (head == NULL)
    {
        printf("Data not fount\n");
        return 0;
    }
    int n = 0;
    node *temp = head;
    do
    {
        n++;
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    return n;
}


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
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = temp;
    temp->next = head;
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
    while (p->next != head)
    {
        p = p->next;
    }
    temp->next = head;
    p->next = temp;
    head = temp;
}

void insertAtPosition(int pos)
{
    int length = findLength();
    if (pos <= 0)
    {
        printf("Invalid Input!\n");
        return;
    }
    if (pos == 1)
    {
        insertAtStart();
        return;
    }

    if (pos == length + 1)
    {
        insertAtLast();
        return;
    }
    if (pos > length + 1)
    {
        printf("Out of Range\n");
        return;
    }

    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory Error : memory not allocated\n");
        return;
    }

    node *p = head;

    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    printf("\nEnter a number: ");
    scanf("%d", &temp->data);
    temp->next = p->next;
    p->next = temp;
}



int main()
{
    while (1)
    {
        printf(
            "\n       MENU         "
            "\n--------------------"
            "\n1. Insert at end"
            "\n2. insert at start"
            "\n3. get length and element"
            "\n4. insert at any position"
            "\n99. Exit\n");
        int choice;
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            insertAtLast();
            break;
        }
        case 2:
        {
            insertAtStart();
            break;
        }
        case 3:
        {
            printf("\nLength = %d\n", findLength());
            break;
        }
        case 4:
        {
            int pos;
            printf("\nEnter position: ");
            scanf("%d", &pos);
            insertAtPosition(pos);
            break;
        }
        case 99:
        {
            printf("\nExiting...\n");
            exit(0);
        }
        default:
            printf("\nInvalid choice!\n");
        }
    }
    return 0;
}