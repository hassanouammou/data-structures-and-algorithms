#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction(void);
void printline(void);

typedef struct node {
    char datatype[10];
    void *data;
    struct node *next;
} node ;

void printline() {
    printf("\n");
}

void introduction() {
    printf(
        "-> Welcome to your advanced singly linked iterator    \n"
        "--- you can insert a node using 'insert'              \n"
        "--- you can read all the available nodes using 'read' \n"
    );
}


int main() {
    // gcc -o singly-advanced.exe singly-advanced.c && singly-advanced.exe
    char query[20];
    node *last     = NULL;
    node *iterator = NULL;
    introduction();
    do {
        printf("-> ");
        scanf("%s", query);
        if (strcmp(query, "insert") == 0) {
            node *new_node = malloc(sizeof(node));
            new_node -> next = NULL;
            printf("--- enter the datatype (string | integer): ");
            scanf("%s", new_node -> datatype);
            if (strcmp(new_node -> datatype, "string") == 0) {
                new_node -> data = (char *) malloc (20 * sizeof(char));
                printf("--- enter the data: ");
                scanf("%s", (char *) new_node -> data);   
            } else {
                new_node -> data = (int *) malloc (sizeof(int));
                printf("--- enter the data: ");
                scanf("%d", (int *) new_node -> data);   
            }
            if (!iterator) {
                iterator = new_node;
                last = new_node;
            } else {
                last -> next = new_node;
                last = new_node;
            }
            printf("--- node created successfully. \n");
        } else if(strcmp(query, "read") == 0) {
            printf("--- Your list contains \n   ");
            node *tIterator = iterator;
            while (tIterator) {
                if (strcmp(tIterator -> datatype, "string") == 0) {
                    printf("(%s) %s ", tIterator -> datatype, (char *) tIterator -> data);
                } else {
                    printf("(%s) %d ", tIterator -> datatype, *(int *) tIterator -> data);
                }
                if (tIterator -> next) printf(" -> ");
                tIterator = tIterator -> next;
            }
            printline();
        } else if (strcmp(query, "clear") == 0) {
            system("cls");
            introduction();
        }
    } while (strcmp(query, "exit") != 0);

    while(iterator) {
        free(iterator);
        iterator = iterator -> next;
    }
    free(last);


    return 0;
}