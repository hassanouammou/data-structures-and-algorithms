#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *left;
    char data[20];
    struct node *right;
} node;

void introduction() {
    printf(
        ">> Welcome to you Binary Tree :)                                      \n"
        " -> with '      addnode      ' you can add a node                     \n"
        " -> with '  showcurrentnode  ' you can show your current node         \n"
        " -> with ' changecurrentnode ' you can change your current node       \n"
        " -> with '   showallnodes    ' you can show all the nodes in the tree \n"
        " -> with '       clear       ' you can clear the screen               \n"
    );
}

void PrintBinaryTree(node* CURRENT) {
    printf(" -> %s \n", CURRENT -> data);
    if (CURRENT -> right != NULL) {
        PrintBinaryTree(CURRENT -> right);
    }
    if (CURRENT -> left != NULL) {
        PrintBinaryTree(CURRENT -> left);
    }
}


int main() {
    // gcc -o binary-tree.exe binary-tree.c; .\binary-tree.exe; 
    char query[20];
    node *HEAD, *CURRENT, *ROOT, *NEW_NODE;
    HEAD = CURRENT = ROOT = NEW_NODE = NULL;
    introduction();
    do {
        printf(">> ");
        scanf("%s", query);
        if (strcmp(query, "addnode") == 0) {
            if (HEAD == NULL) {
                ROOT = malloc(sizeof(node));
                printf(" -> this is the root of the tree, enter some data to store into: ");
                scanf("%s", ROOT -> data);
                ROOT -> left  = NULL;
                ROOT -> right = NULL;
                HEAD = CURRENT = ROOT;
            } else {
                if (CURRENT -> left == NULL && CURRENT -> right == NULL || CURRENT -> left == NULL && CURRENT -> right != NULL) {
                    NEW_NODE = malloc(sizeof(node));
                    if (CURRENT -> left == NULL && CURRENT -> right == NULL) {
                        printf(" -> this is the right node of '%s', enter some data to store into: ", CURRENT -> data);
                        scanf("%s", NEW_NODE -> data);
                        NEW_NODE -> left  = NULL;
                        NEW_NODE -> right = NULL;
                        CURRENT  -> right = NEW_NODE;
                    } else {
                        printf(" -> this is the left node of '%s', enter some data to store into: ", CURRENT -> data);
                        scanf("%s", NEW_NODE -> data);
                        NEW_NODE -> left  = NULL;
                        NEW_NODE -> right = NULL;
                        CURRENT  -> left = NEW_NODE;
                    }
                } else {
                    printf(" -> you can't add more than two nodes inside '%s' node :( \n", CURRENT -> data);
                    printf(
                        " --> change you current node to one of it's children maybe '%s' or '%s' :) \n", 
                        CURRENT -> right -> data, 
                        CURRENT -> left -> data
                    );
                }
            }
        } else if (strcmp(query, "showcurrentnode") == 0) {
            if (HEAD == NULL) {
                puts(" -> your tree is empty, add a root node first :)");
            } else {
                printf(" -> your current node is '%s' :) \n", CURRENT -> data);
            }
        } else if (strcmp(query, "changecurrentnode") == 0) {
            if (HEAD != NULL && CURRENT -> right != NULL && CURRENT -> left != NULL) {
                puts(" -> great, you have 2 options ");
                printf(" ---> the node at the right '%s' \n", CURRENT -> right -> data);
                printf(" ---> the node at the left '%s' \n", CURRENT -> left -> data);
                printf(" -> enter the name of the disired node: ");
                char disired_node[20];
                scanf("%s", disired_node);
                if (strcmp(disired_node, CURRENT -> left -> data) == 0 || strcmp(disired_node, CURRENT -> right -> data) == 0) {
                    if (strcmp(disired_node, CURRENT -> left -> data) == 0) {
                        CURRENT = CURRENT -> left;
                        printf(" -> the left node '%s' became the current :) \n", CURRENT -> data);
                    } else {
                        CURRENT = CURRENT -> right;
                        printf(" -> the right node '%s' became the current :) \n", CURRENT -> data);
                    }
                } else {
                    puts(" --> the node entered doesn't exist :( ");
                }
            } else {
                puts(" -> you can't change the current node if there is no childs :( ");
            }
        } else if (strcmp(query, "showallnodes") == 0) {
            if (HEAD == NULL) {
                puts(" -> your tree is empty: ( ");
            } else {
                PrintBinaryTree(HEAD);
            }
        } else if (strcmp(query, "clear") == 0) {
            system("cls");
            introduction();
        } else {
            if (strcmp(query, "exit") != 0) {
                puts(" -> command not recognized :(");
            }
        }
    } while(strcmp(query, "exit") != 0);
    free(HEAD);
    free(CURRENT);
    free(ROOT);
    return 0;
}