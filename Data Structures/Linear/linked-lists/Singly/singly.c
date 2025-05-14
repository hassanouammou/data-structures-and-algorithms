/* gcc -o singly singly.c && singly */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void printline() {
    printf("\n");
}

void print(node* HEAD) {
    node* temporaryHead = HEAD;
    if(HEAD == NULL) {
        printf(" -> Your Linked List is Empty !");
        printline();
        return;
    } else {
        printf(" -> Your Linked List Contains: ");
    }
    while (temporaryHead != NULL) {
        if (temporaryHead -> next == NULL) {
            printf("%d", temporaryHead -> data);
        } else {
            printf("%d -> ", temporaryHead -> data);
        }
        temporaryHead = temporaryHead -> next;
    }
    printline();
}

void introduction() {
    printf("\n>> This is your linked list program :)");                     printline();
    printf(">> You Can: ");                                                 printline();
    printf(" -> add node at last                   with  addnodeatlast");   printline();
    printf(" -> add node at first                  with  addnodeatfirst");  printline();
    printf(" -> display all nodes in the list      with  display");         printline();
    printf(" -> remove the last node in the list   with  removelast");      printline();
    printf(" -> remove the first node in the list  with  removefirst");     printline();
    printf(" -> terminate the program              with  exit");            printline();
}

void main() {
    char query[20];
    node* HEAD = NULL;
    int data;
    introduction();
    do {
        printf(">> ");
        scanf("%s", &query);
        if (strcmp(query, "addnodeatlast") == 0) {
            printf(" -> OK, enter the data please: ");
            scanf("%d", &data);
            node *newNode = (node *) malloc (sizeof(node)), *temporaryHead = HEAD;
            newNode -> data = data;
            newNode -> next = NULL;
            if (HEAD == NULL) {
                HEAD = newNode;
            } else {
                while(temporaryHead -> next != NULL) {
                    temporaryHead = temporaryHead -> next;
                }
                temporaryHead -> next = newNode;
            }   
            printf(" -> node added successfully :) ");  printline();  
        } else if (strcmp(query, "addnodeatfirst") == 0) {
            printf(" -> OK, enter the data please: ");
            scanf("%d", &data);
            node *newNode = (node *) malloc (sizeof(node)), *temporaryHead = HEAD;
            newNode -> data = data;
            newNode -> next = temporaryHead;
            HEAD = newNode;
            printf(" -> node added successfully :) ");  printline();  
        } else if (strcmp(query, "display") == 0) {
            print(HEAD);    
        } else if (strcmp(query, "removelast") == 0) {
            // TODO if the linked list contains only one node 
            node *temporaryHead = HEAD;
            while(HEAD != NULL && temporaryHead -> next != NULL) {
                if (temporaryHead -> next -> next == NULL) {
                    temporaryHead -> next = NULL;
                    printf(" -> the last node removed successfully :) "); printline();
                    break;
                }
                temporaryHead = temporaryHead -> next;
            }
        } else if (strcmp(query, "removefirst") == 0) {
            node *temporaryHead = HEAD;
            HEAD = temporaryHead -> next;
            printf(" -> the first node removed successfully :) "); printline();
        } else if (strcmp(query, "clear") == 0) {
            system("cls");
            introduction();
        } else {
            if (strcmp(query, "exit") != 0) {
                printf(" -> command not recognized :( "); printline();
            } else {
                printf(" -> program finished :) ");      
            }
        }
    } while(strcmp(query, "exit") != 0);
}

