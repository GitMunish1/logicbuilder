#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define our Contact struct
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// We'll store all our contacts in a global array
Contact contacts[MAX_CONTACTS];
// This variable will keep track of how many contacts we've added
int contact_count = 0;

int main() {
    int choice;
    
    // An example contact to test the search function
    strcpy(contacts[contact_count].name, "Jane Doe");
    strcpy(contacts[contact_count].phone, "555-1234");
    strcpy(contacts[contact_count].email, "jane.doe@example.com");
    contact_count++;

    while (1) {
        // Display the menu options
        printf("\n********Digital adress book\n");
        printf("1. Add a Number\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear the input buffer after reading an integer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                if (contact_count < MAX_CONTACTS) {
                    printf("Enter name: ");
                    fgets(contacts[contact_count].name, sizeof(contacts[contact_count].name), stdin);
                    contacts[contact_count].name[strcspn(contacts[contact_count].name, "\n")] = 0;
                    
                    printf("Enter phone number: ");
                    fgets(contacts[contact_count].phone, sizeof(contacts[contact_count].phone), stdin);
                    contacts[contact_count].phone[strcspn(contacts[contact_count].phone, "\n")] = 0;

                    printf("Enter email: ");
                    fgets(contacts[contact_count].email, sizeof(contacts[contact_count].email), stdin);
                    contacts[contact_count].email[strcspn(contacts[contact_count].email, "\n")] = 0;
                    
                    contact_count++;
                    printf("Contact added successfully!\n");
                } else {
                    printf("Address book is full!\n");
                }
                break;
            case 2:
                if (contact_count == 0) {
                    printf("Address book is empty.\n");
                } else {
                    printf("\n--- All Contacts ---\n");
                    for (int i = 0; i < contact_count; i++) {
                        printf("Name: %s\n", contacts[i].name);
                        printf("Phone: %s\n", contacts[i].phone);
                        printf("Email: %s\n", contacts[i].email);
                        printf("---------------------\n");
                    }
                }
                break;
            case 3: ; // The semicolon is needed because a switch case cannot be followed by a declaration directly.
                char search_name[50];
                int found = 0;

                printf("Enter name to search: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = 0;

                for (int i = 0; i < contact_count; i++) {
                    // Create temporary strings for comparison
                    char temp_contact_name[50];
                    char temp_search_name[50];

                    strcpy(temp_contact_name, contacts[i].name);
                    strcpy(temp_search_name, search_name);

                    // Convert both strings to lowercase
                    for (int j = 0; temp_contact_name[j]; j++) {
                        if (temp_contact_name[j] >= 'A' && temp_contact_name[j] <= 'Z') {
                            temp_contact_name[j] = temp_contact_name[j] + ('a' - 'A');
                        }
                    }
                    for (int j = 0; temp_search_name[j]; j++) {
                        if (temp_search_name[j] >= 'A' && temp_search_name[j] <= 'Z') {
                            temp_search_name[j] = temp_search_name[j] + ('a' - 'A');
                        }
                    }

                    // Perform the comparison
                    if (strcmp(temp_contact_name, temp_search_name) == 0) {
                        printf("\nContact Found!\n");
                        printf("Name: %s\n", contacts[i].name);
                        printf("Phone: %s\n", contacts[i].phone);
                        printf("Email: %s\n", contacts[i].email);
                        found = 1;
                        break; // Exit the loop once a match is found
                    }
                }

                if (!found) {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}