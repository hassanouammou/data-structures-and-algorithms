#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void main() {
    // gcc -o stack.exe stack.c && stack.exe
    char query[20];
    int *pointer = NULL, popRequestsLength = 0, data, index = 0;
    system("cls");
    printf(
        ">> Welcome To Your Stack Structure :)             \n"
        ">> Here you can:                                  \n"
        " -> add an item to the stack          with 'push' \n"
        " -> delete the last item in the stack with 'pop'  \n"
        " -> show the last item in the stack   with 'peek' \n"
        " -> show the items in the stack       with 'show' \n"
        " -> terminate the program             with 'exit' \n"
    );
    do {
        printf(">> ");
        scanf("%s", query);
        if (strcmp(query, "push") == 0) {
            popRequestsLength++;
            pointer = realloc (pointer, popRequestsLength * sizeof(int));
            printf(" -> Great, what data to store in: ");
            scanf("%d", &data);
            pointer[index] = data;
            index++;
            printf(" -> item added successfully :) \n");
        } else if (strcmp(query, "pop") == 0) {
            pointer = realloc(pointer, (popRequestsLength - 1) * sizeof(int));
            popRequestsLength--;
            index--;
            printf(" -> the last item is removed successfully :) \n");
        } else if (strcmp(query, "peek") == 0) {
            printf(" -> the last item in the stack is %d \n", pointer[index - 1]);
        } else if (strcmp(query, "show") == 0) {
            printf(" -> Ok, the elements in the stack are: \n");
            for(int i = 0; i < popRequestsLength; i++) {
                printf("  -> item %d: %d \n", i + 1, pointer[i]);
            }
            printf(" -> end with total %d items. \n", popRequestsLength);
        } else {
            if (strcmp(query, "exit") != 0) {
                printf(" -> command not recognized :( \n");
            }
        }
    } while (strcmp(query, "exit") != 0);
    printf(" -> program successfully terminated :) ");
    free(pointer);
}