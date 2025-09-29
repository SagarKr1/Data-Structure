#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *head = NULL;

int findLength()
{
    if (head == NULL)
    {
        return 0;
    }
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    temp = NULL;
    free(temp);
    return count;
}

void insertAtStart()
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\n\n Memory Error : Memory not allocated\n\n");
        return;
    }

    printf("\n\nEnter a data: ");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = head;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    head = temp;
}

void insertAtLast()
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\n\n Memory Error : Memory not allocated\n\n");
        return;
    }

    printf("\n\nEnter a data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return;
    }
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->prev = ptr;
    ptr->next = temp;
}

int main()
{
    while (1)
    {
        printf(
            "\n          MENU           "
            "\n-------------------------"
            "\n1. Get Length"
            "\n2. Insert at Starting"
            "\n3. Insert at Last"
            "\n99. Exit");
        int choice;
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int length = findLength();
            printf("\n Length are %d", length);
            break;
        }
        case 2:
        {
            insertAtStart();
            break;
        }

        case 3:
        {
            insertAtLast();
            break;
        }
        case 99:
        {
            printf("-----x-x-The End-x-x-------");
            exit(1);
        }

        default:
        {
            printf("\nInvalid Input\n");
        }
        }
    }
    return 0;
}