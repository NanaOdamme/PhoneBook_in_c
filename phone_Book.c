#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phoneNumber[15];
    char address[100];
};

struct Contact *phoneBook = NULL;
int contactCount = 0;
int maxContacts = 0;

void addContact(void)
{
    if (contactCount < maxContacts)
    {
        struct Contact newContact;

        printf("Enter name: ");
        scanf("%s", newContact.name);
        printf("Enter phone number: ");
        scanf("%s", newContact.phoneNumber);
        printf("Enter address: ");
        scanf(" %[^\n]", newContact.address);

        phoneBook[contactCount++] = newContact;
        printf("Contact added successfully!\n");
    }
    else
    {
        printf("Phone book is full.\n");
    }
}

void searchContact(void)
{
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < contactCount; i++)
    {
        if (strcmp(phoneBook[i].name, searchName) == 0)
        {
            printf("Contact found:\n");
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone number: %s\n", phoneBook[i].phoneNumber);
            printf("Address: %s\n", phoneBook[i].address);
            return;
        }
    }

    printf("Contact not found.\n");
}

void displayContacts(void)
{
    if (contactCount == 0)
    {
        printf("No contacts yet.\n");
        return;
    }

    printf("Phone Book Contacts:\n");
    for (int i = 0; i < contactCount; i++)
    {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone number: %s\n", phoneBook[i].phoneNumber);
    }
}

int main(void)
{
    int choice;

    printf("Enter the maximum number of contacts: ");
    scanf("%d", &maxContacts);
    phoneBook = (struct Contact *)malloc(maxContacts * sizeof(struct Contact));

    if (phoneBook == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1)
    {
        printf("\nPhone Book App\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a valid choice.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice)
        {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                free(phoneBook);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(phoneBook);
    return 0;
}

