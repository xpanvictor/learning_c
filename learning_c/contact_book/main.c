#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char first_name[15];
    char last_name[15];
    char phone[15];
};

// Phone book array of max 12 contacts
struct Contact PhoneBook[12];
int PhoneBookCounter = 0;

int create_contact()
{
    if (PhoneBookCounter >= 12)
    {
        fprintf(stderr, "No more space in phone book, delete a contact first\n");
        exit(1);
    }

    // Still space, can store contact
    // Create new contact
    int contact_index = PhoneBookCounter;
    printf("Please enter the phone number: ");
    scanf("%s", PhoneBook[contact_index].phone);

    printf("Please enter the first name: ");
    scanf("%s", PhoneBook[contact_index].first_name);

    printf("Please enter the last name: ");
    scanf("%s", PhoneBook[contact_index].last_name);

    PhoneBookCounter++;

    return contact_index;
}

// Private function ?
void show_contact(int index)
{
    printf("Showing contact at index %d --->\n", index);
    struct Contact user_fetched = PhoneBook[index];
    printf("First name: %s\n", user_fetched.first_name);
    printf("Last name: %s\n", user_fetched.last_name);
    printf("Phone number: %s\n\n", user_fetched.phone);
}

void show_all_contacts()
{
    for (int i = 0; i < PhoneBookCounter; i++)
        show_contact(i);
}

void router()
{
    /**
     * c => create new contact;
     * d => delete contact;
     * u => update contact;
     * s => show all contacts;
     * q => quit contact book program
     */
    char action_to_do = '\0';

    do
    {
        printf("\nEnter c to create, d to delete, s to show all, \nu to update and q to quit: ");
        action_to_do = getchar();

        // consume new line char
        while (getchar() != '\n')
            ;
        printf("\n");

        switch (action_to_do)
        {
        case 'c':
        {
            int contact_index = create_contact();
            printf("Contact created\n");
            show_contact(contact_index);
            break;
        };

        case 'd':
            printf("Will create a new contact\n");
            break;

        case 'u':
            printf("Will create a new contact\n");
            break;

        case 's':
        {
            printf("Fetching all contacts...\n");
            show_all_contacts();
            break;
        }

        case 'q':
            printf("Thanks for using the phone book app\n");
            break;

        default:
            printf("The option '%c' you entered is not valid\n", action_to_do);
            continue;
        }
    } while (action_to_do != 'q');
}

int main()
{
    printf("Welcome to the phonebook app.\n");
    router();
    exit(0);
}
