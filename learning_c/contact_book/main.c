#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PHONE_BOOK_MAX 12;

struct Contact
{
    char first_name[15];
    char last_name[15];
    char phone[15];
};

// Phone book array of max 12 contacts
struct Contact PhoneBook[PHONE_BOOK_MAX];
int PhoneBookCounter = 0;

// private util function; TODO: shouldn't mutate
char *toLowerCase(char *s)
{
    for (int i = 0; s[i]; i++)
    {
        s[i] = tolower(s[i]);
    }
}

void fill_contact_details(int contact_index)
{
    printf("Please enter the phone number: ");
    scanf("%s", PhoneBook[contact_index].phone);

    printf("Please enter the first name: ");
    scanf("%s", PhoneBook[contact_index].first_name);

    printf("Please enter the last name: ");
    scanf("%s", PhoneBook[contact_index].last_name);
}

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
    fill_contact_details(contact_index);
    PhoneBookCounter++;

    return contact_index;
}

// Private function ?
void show_contact(int index)
{
    printf("\nShowing contact at index %d --->\n", index);
    struct Contact user_fetched = PhoneBook[index];
    printf("First name: %s\n", user_fetched.first_name);
    printf("Last name: %s\n", user_fetched.last_name);
    printf("Phone number: %s\n\n", user_fetched.phone);
}

void show_all_contacts()
{
    for (int i = 0; i < PhoneBookCounter; i++)
        show_contact(i);

    printf("Fetched all %d contacts", PhoneBookCounter);
}

int search_for_contact_index(char *query, int start_index)
{
    printf("Searching for %s...\n", query);
    for (int i = start_index; i < PhoneBookCounter; i++)
    {
        struct Contact current_contact = PhoneBook[i];
        char *res = strstr(current_contact.first_name, query);
        if (
            strstr(current_contact.first_name, query) == NULL &&
            strstr(current_contact.last_name, query) == NULL &&
            strstr(current_contact.phone, query) == NULL)
            continue;
        return i;
    }
    return -1;
}

void find_contact()
{
    char query[15];
    printf("Enter anything you remember about the contact: ");
    scanf("%s", &query);

    int search_start_index = 0;
    int continue_searching = 1;
    while (continue_searching > 0)
    {
        int contact_index = search_for_contact_index(query, 0);
        if (contact_index < 0)
        {
            printf("Sorry contact not found!\n");
            return;
        }
        show_contact(contact_index);
        printf("Is this the contact;\n0 for yes, 1 for continue searching: ");

        // TODO: Fix continue searching
        continue_searching = getchar();
        while (continue_searching == '\n')
            continue_searching = getchar();
        search_start_index = contact_index + 1; // next place to resume search

        if (search_start_index > PhoneBookCounter)
        {
            printf("Search done either no more contact to search!");
        }
        // consume new line char
        while (getchar() != '\n')
            ;
    }
}

void update_contact()
{
    char query[15];
    printf("Enter anything you remember about the contact to update: ");
    scanf("%s", &query);

    int contact_index = search_for_contact_index(query, 0);
    if (contact_index < 0)
    {
        printf("Sorry contact not found!\n");
        return;
    }
    show_contact(contact_index);

    // TODO: continue searching fn
    printf("Is this the contact;\n0 for yes, 1 for continue searching: ");
    int continue_searching = getchar();
    while (continue_searching == '\n')
            continue_searching = getchar();
    

    // if right contact to update
    fill_contact_details(contact_index);

    printf("Contact updated successfully =>\n");
    show_contact(contact_index);
}

void delete_contact()
{
    char query[15];
    printf("Enter anything you remember about the contact to delete: ");
    scanf("%s", &query);

    int contact_index = search_for_contact_index(query, 0);
    if (contact_index < 0)
    {
        printf("Sorry contact not found!\n");
        return;
    }
    show_contact(contact_index);

    // TODO: continue searching fn
    printf("Is this the contact;\n0 for yes, 1 for continue searching: ");
    int continue_searching = getchar();
    while (continue_searching == '\n')
            continue_searching = getchar();

    // A linked list would have been better
    for(
        int i = contact_index; 
        i <= PhoneBookCounter; 
        i++
    ) {
        // if (i == PHONE_BOOK_MAX - 1) {
        //     // TODO:
        // }
        PhoneBook[i] = PhoneBook[i+1];
    }
    // // Delete last item
    // PhoneBook[contact_index];
    PhoneBookCounter--;
    show_all_contacts();
}

void router()
{
    /**
     * c => create new contact;
     * f => find contact;
     * d => delete contact;
     * u => update contact;
     * s => show all contacts;
     * q => quit contact book program
     */
    char action_to_do = '\0';

    do
    {
        printf("\nEnter c to create, f to find, d to delete, s to show all, \nu to update and q to quit: ");
        action_to_do = getchar();
        while (action_to_do == '\n')
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

        case 'f':
        {
            find_contact();
            break;
        }

        case 'd':
            delete_contact();
            break;

        case 'u':
        {
            update_contact();
            break;
        }

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
