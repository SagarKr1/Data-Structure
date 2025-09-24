#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insertAtLast()
{
    int n;
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory Error: Memory not allocated");
        exit(1);
    }
    printf("Enter a value\n");
    scanf("%d", &n);

    temp->next = NULL;
    temp->data = n;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
};

void insertAtStart()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory Error: Memory not allocated\n");
        return;
    }

    printf("Enter a data: ");
    scanf("%d", &temp->data);
    temp->next = head;
    head = temp;
}

void getAllData()
{
    Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Get all data:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int findLength()
{
    Node *temp = head;
    int n = 0;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    // printf("Get all data:\n");
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}

void insertIntoMiddle(int position)
{
    int length = findLength();
    if (head == NULL)
    {
        printf("No data found\n");
        return;
    }

    if (position == length + 1)
    {
        insertAtLast();
    }
    else if (position == 1)
    {
        insertAtStart();
    }
    else if (position <= 0)
    {
        printf("Are You Made\n");
        return;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    Node *p = head;
    if (temp == NULL)
    {
        printf("Memory Error: Memory not allocated\n");
        return;
    }
    for (int i = 1; i < position - 1; i++)
    {
        p = p->next;
    }
    printf("Enter a data: ");
    scanf("%d", &temp->data);
    temp->next = p->next;
    p->next = temp;
}

void deleteFromStart()
{
    if (head == NULL)
    {
        printf("No Data Found\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    printf("Data Deleted successfully");
}

void deleteFromEnd()
{
    if(head==NULL){
        printf("No Data Found");
        return;
    }
    if(head->next==NULL){
        deleteFromStart();
        return;
    }
    Node *ptr = head;

    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }

    Node *temp=ptr->next;
    printf("Deleted: %d\n", temp->data);
    ptr->next=NULL;
    free(temp);
}

void deleteFromMiddle()
{
    if(head==NULL){
        printf("Data should not be empty\n");
        return;
    }
    int pos;
    printf("Enter position which you want to delete: ");
    scanf("%d",&pos);

    if(pos<=0){
        printf("Invalid Input\n");
        return;
    }
    int length = findLength();

    if(pos>length){
        printf("Condition not satisfied\n");
        return;
    }
    
    if(pos==1){
        deleteFromStart();
        return;
    }

    if(pos==length){
        deleteFromEnd();
        return;
    }

    Node *ptr = head;
    for(int i=1;i<pos-1;i++){
        ptr=ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next=temp->next;
    free(temp);
    printf("Data Deleted Successfully\n");
}

int main()
{
    while (1)
    {
        int n;
        printf(
            "        Menu          \n"
            "----------------------\n"
            "1. Insert Data at end"
            "\n2. Insert Data at start"
            "\n3. Get All Data"
            "\n4. Get Length of Data"
            "\n5. Insert Into Middle"
            "\n6. Delete from start"
            "\n7. Delete from End"
            "\n8. Delete from Middle"
            "\n99. Exit"
            "\n---------xxxxxx---------"
            );
        printf("\n\nEnter Your Choice:  ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insertAtLast();
            break;
        case 2:
            insertAtStart();
            break;
        case 3:
            getAllData();
            break;
        case 4:
        {
            int length = findLength();
            printf("Total length is %d\n", length);
            break;
        }

        case 5:
        {
            int pos;
            printf("Enter position where you want to enter data : ");
            scanf("%d", &pos);
            insertIntoMiddle(pos);
            break;
        }
        case 6:
        {
            deleteFromStart();
            break;
        }
        case 7:
        {
            deleteFromEnd();
            break;
        }
        case 8:
        {
            deleteFromMiddle();
            break;
        }
        case 99:
            exit(1);
        default:
            printf("Wrong choice");
        }
    }
    return 0;
}