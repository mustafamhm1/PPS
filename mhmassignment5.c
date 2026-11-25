#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int choice;

    do {
        printf("\n1. Length  2. Copy  3. Concat  4. Compare  5. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = 0; 
            continue;
        }
        getchar(); 

        if (choice >= 1 && choice <= 4) {
            printf("Enter string 1: ");
            scanf(" %99[^\n]", s1);
            while (getchar() != '\n'); // Clear any extra characters

            if (choice >= 3) {
                printf("Enter string 2: ");
                scanf(" %99[^\n]", s2);
                while (getchar() != '\n');
            }
        }

        switch (choice) {
            case 1:
                printf("Length: %zu\n", strlen(s1));
                break;
            case 2:
                strcpy(s2, s1);
                printf("Copied: %s\n", s2);
                break;
            case 3:
                if (strlen(s1) + strlen(s2) < sizeof(s1)) {
                    strcat(s1, s2);
                    printf("Joined: %s\n", s1);
                } else {
                    printf("Error: Combined string exceeds buffer limit (99 chars).\n");
                }
                break;
            case 4:
                printf("Comparison result: %d\n", strcmp(s1, s2));
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
