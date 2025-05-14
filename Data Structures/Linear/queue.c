#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char data[20];
    struct item * next;
} item;

void introduction() {
    printf(
        ">> Hello, this is your Queue :)                               \n"
        " -> The Queue follow the 'First In First Out (FIFO) rule'  <- \n"
        " -> with 'enqueue' you can add     a   new  item           <- \n"
        " -> with 'dequeue' you can remove  the last item           <- \n"
        " -> with 'showall' you can display all the  items          <- \n"
        " -> with 'clear'   you can clear   your     screen         <- \n"
    );
}


int main() {
    // gcc -o queue.exe queue.c && queue.exe
    char query[20];
    item *QUEUE = NULL, *tQUEUE = NULL;
    introduction();
    do {
        printf(">> ");
        scanf("%s", query);
        if (strcmp(query, "enqueue") == 0) {
            printf(" -> data: ");
            if (QUEUE == NULL) {
                QUEUE = (item *) calloc (1, sizeof(item));
                scanf("%s", &QUEUE -> data);
                QUEUE -> next = NULL;
            } else {
                item* newItem = (item *) calloc(1, sizeof(item));
                scanf("%s", &newItem -> data);
                newItem -> next = NULL;
                tQUEUE = QUEUE;
                while(tQUEUE -> next != NULL) {
                    tQUEUE = tQUEUE -> next;
                }
                tQUEUE -> next = newItem;
            }
        } else if (strcmp(query, "dequeue") == 0) {
            item* firstItem = QUEUE;
            QUEUE = QUEUE -> next;
            free(firstItem);
            puts(" -> the first item is removed successfully :)");
        } else if (strcmp(query, "showall") == 0) {
            if (QUEUE == NULL) {
                puts(" -> Your Queue is Empty !");
            } else {
                tQUEUE = QUEUE;
                printf(" -> Your Queue contains: \n ");
                while(tQUEUE != NULL) {
                    printf("%s", tQUEUE -> data);
                    if (tQUEUE -> next != NULL) {
                        printf(" -> ");
                    }
                    tQUEUE = tQUEUE -> next;
                }
                printf("\n");
            }
        } else if (strcmp(query, "clear") == 0) {
            system("cls");
            introduction();
        } else {
            if (strcmp(query, "exit") != 0) {
                printf(" -> command not recognized :( \n");
            }
        }
    } while(strcmp(query, "exit") != 0);
    free(QUEUE);
    return 0;
}