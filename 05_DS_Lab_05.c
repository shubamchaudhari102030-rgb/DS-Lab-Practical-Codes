#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int value)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;

    printf("Node inserted successfully.\n");
}

// Delete at beginning
void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);

    printf("Node deleted successfully.\n");
}

// Forward traversal
void displayForward()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Forward Traversal: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Backward traversal
void displayBackward()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Move to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Backward Traversal: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

// Main function
int main()
{
    int choice, value;

    do
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete at Beginning\n");
        printf("3. Forward Traversal\n");
        printf("4. Backward Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertAtBeginning(value);
                break;

            case 2:
                deleteAtBeginning();
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                printf("Program exited.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}