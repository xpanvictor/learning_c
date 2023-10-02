#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the phonebook app.\n");
    /**
     * c => create new contact;
     * d => delete contact;
     * u => update contact;
     * s => show all contacts;
     * q => quit contact book program
    */
    char action_to_do = '\0';
    
    do {
        printf("Enter c to create, d to delete, s to show all, \nu to update and q to quit: ");
        scanf("%c", &action_to_do);

        // consume new line char
        while (getchar() != '\n');
        
        printf("%c\n", action_to_do);
    } while (action_to_do != 'q');

    exit(0);
}
