// Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;


// Insert at Start
void insertStart()
{
    int value;
    struct node *newNode;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("Node inserted at start.\n");
}


// Insert at End
void insertEnd()
{
    int value;
    struct node *newNode;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Node inserted at end.\n");
}


// Delete from Start
void deleteStart()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (last->next == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }

    printf("Node deleted from start.\n");
}


// Delete from End
void deleteEnd()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (last->next == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        temp = last->next;

        while (temp->next != last)
        {
            temp = temp->next;
        }

        temp->next = last->next;
        free(last);
        last = temp;
    }

    printf("Node deleted from end.\n");
}


// Display
void display()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

    } while (temp != last->next);

    printf("(back to first)\n");
}


// Main Function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Circular Linked List ---\n");

        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Start\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertStart();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteStart();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}