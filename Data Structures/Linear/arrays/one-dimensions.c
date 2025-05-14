#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    // gcc -o one-dimensions one-dimensions.c && one-dimensions
    char **pointer, result[200] = "";
    int n;
    printf(">> The Concatenation Program :) \n");
    printf(">> Please, enter the number of words to concatenate: ");
    scanf("%d", &n);
    pointer = (char**) malloc (n * sizeof(char*));
    for(int i = 0; i < n; i++) {
        pointer[i] = (char*) malloc (200 * sizeof(char));
    }
    printf(">> Great, now enter the words one by one \n");
    for(int i = 0; i < n; i++) {
        printf(" -> %d: ", i + 1);
        scanf("%s", pointer[i]);
        if (strcmp(result, "") == 0) {
            strcat(result, pointer[i]);
        } else {
            strcat(result, " ");
            strcat(result, pointer[i]);
        }
    }
        
    printf(">> The result is %s \n", result);
    
    for(int i = 0; i < n; i++) {
        free(pointer[i]);
    }
    free(pointer);
}
