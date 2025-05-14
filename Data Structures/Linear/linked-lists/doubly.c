#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *previous;
    char data[20];
    struct node *next;
} node;

void introduction(void) {
    printf(
        ">> Welcome To your Doubly Linked List :)            \n"
        " -> with 'addnode' you can add a new nodes          \n"
        " -> with 'showall' you can visualize all your nodes \n"
        " -> with ' clear ' you can clear the screen \n"
    );
}

int main() {
    // gcc -o doubly.exe doubly.c; .\doubly.exe
    introduction();
    char query[20];
    node *HEAD, *CURRENT;
    HEAD = CURRENT = NULL;
    do {    
        printf(">> ");
        scanf("%s", query);
        if (strcmp(query, "addnode") == 0) {
            node *NEW = malloc(sizeof(node));
            printf(" -> great, enter some data: ");
            scanf("%s", NEW -> data);
            NEW -> next = NULL;
            if (HEAD == NULL) {
                NEW -> previous = NULL;
                HEAD = CURRENT = NEW;
            } else {
                CURRENT -> next = NEW;
                NEW -> previous = CURRENT;
                CURRENT = NEW;
            }
            puts(" -> node added successfully :)");
        } else if (strcmp(query, "showall") == 0) {
            if (HEAD == NULL) {
                puts(" -> You Linked List is EMPTY :) ");
            } else {
                char order[20];
                printf(" -> which order please (ascending | descending): ");
                scanf("%s", order);
                if (strcmp(order, "ascending") == 0) {
                    printf(" -> Your Linked List contains \n    ");
                    node *TEMP_HEAD = HEAD;
                    while(TEMP_HEAD != NULL) {
                        printf("%s", TEMP_HEAD -> data);
                        if (TEMP_HEAD -> next != NULL) {
                            printf(" -> ");
                        }
                        TEMP_HEAD = TEMP_HEAD -> next;
                    } 
                    printf("\n");
                } else {
                    node *TEMP_LAST = CURRENT;
                    printf(" -> Your Linked List contains \n");
                    while(TEMP_LAST != NULL) {
                        printf("%s", TEMP_LAST -> data);
                        if (TEMP_LAST -> previous != NULL) {
                            printf(" <- ");
                        }
                        TEMP_LAST = TEMP_LAST -> previous;
                    } 
                    printf("\n");
                }
            } 
            
        } else if (strcmp(query, "clear") == 0) {
            system("cls"); 
            introduction();
        }
        
    } while (strcmp(query, "exit") != 0);
    free(HEAD);
    free(CURRENT);
    return 0;
}