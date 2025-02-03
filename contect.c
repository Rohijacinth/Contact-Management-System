#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 50

typedef struct contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

Contact *contacts;
int num_contacts = 0;
int capacity = 10;

// Function to resize the contacts array
void resize_contacts() {
    capacity *= 2;
    contacts = (Contact *)realloc(contacts, capacity * sizeof(Contact));
    if (contacts == NULL) {
        perror("Memory reallocation failed");
        exit(1);
    }
}

void add_contact() {
    if (num_contacts == capacity) {
        resize_contacts();
    }

    printf("Enter name: ");
    scanf(" %[^\n]s", contacts[num_contacts].name);
    printf("Enter phone: ");
    scanf(" %[^\n]s", contacts[num_contacts].phone);
    printf("Enter email: ");
    scanf(" %[^\n]s", contacts[num_contacts].email);

    num_contacts++;
    printf("Contact added successfully.\n");
}

void display_contacts() {
    if (num_contacts == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\nContacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n\n", contacts[i].email);
    }
}

// Basic search by name (you can extend this)
void search_contacts() {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf(" %[^\n]s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n\n", contacts[i].email);
            return; // Found the contact
        }
    }
    printf("Contact not found.\n");
}

// (Sorting functions – bubble sort and quicksort – would go here.  These are more complex and I'll provide them separately if you'd like to work on those next.)

int main() {
    int choice;

    contacts = (Contact *)malloc(capacity * sizeof(Contact));
    if (contacts == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contacts\n"); // Basic search implemented
        printf("4. Sort Contacts\n"); // Placeholder for sorting
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_contact(); break;
            case 2: display_contacts(); break;
            case 3: search_contacts(); break;
            case 4: printf("Sorting not yet implemented.\n"); break; // Placeholder
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    free(contacts);
    return 0;
}
