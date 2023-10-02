#include <stdio.h>
#include <stdlib.h>


void router() {
    /**
     * c => create new contact;
     * d => delete contact;
     * u => update contact;
     * s => show all contacts;
     * q => quit contact book program
    */
    char action_to_do = '\0';
    
    do {
        printf("\nEnter c to create, d to delete, s to show all, \nu to update and q to quit: ");
        action_to_do = getchar();

        // consume new line char
        while (getchar() != '\n');
        
        switch (action_to_do)
        {
        case 'c':
            printf("Will create a new contact\n");
            break;
        
        case 'd':
            printf("Will create a new contact\n");
            break;
        
        case 'u':
            printf("Will create a new contact\n");
            break;
        
        case 's':
            printf("Will create a new contact\n");
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
