#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction(void);

int main() {
    // gcc -o adjacency-matrix.exe adjacency-matrix.c; .\adjacency-matrix.exe; 
    introduction();
    char *query = calloc(20, sizeof(char));
    int **ADJACENCY_MATRIX = NULL, totalNodes = 0;
    do {
        printf(">> ");
        scanf("%s", query);
        if (strcmp(query, "Start") == 0) {
            if (ADJACENCY_MATRIX == NULL) {
                printf(" -> great, how many nodes: ");
                scanf("%d", &totalNodes);
                ADJACENCY_MATRIX = calloc(totalNodes, sizeof(int *));
                for(int i = 0; i < totalNodes; i++) {
                    ADJACENCY_MATRIX[i] = calloc(totalNodes, sizeof(int));
                }
                puts(" -> Graphspace created successfully :) ");
            } else {
                puts(" -> you can't start the program more than once :( ");
            }
        } else if (strcmp(query, "ShowNodes") == 0) {
            if (ADJACENCY_MATRIX == NULL) {
                puts(" -> start the program first using 'Start' command :) ");
            } else {
                puts(" -> The available nodes are: ");
                for(int i = 0; i < totalNodes; i++) {
                    printf(" --> node %d \n", i + 1);
                }
            }
        } else if (strcmp(query, "MakeRelation") == 0) {
            if (ADJACENCY_MATRIX == NULL) {
                puts(" -> start the program first using 'Start' command :) ");
            } else {
                puts(" -> Notice that the available relations are: ");
                int totalRelationsFound = totalNodes;
                for(int i = 0; i < totalNodes; i++) {
                    printf(" -> for node %d \n", i +1);
                    for(int j = 0; j < totalNodes; j++) {
                        if (ADJACENCY_MATRIX[i][j] == ADJACENCY_MATRIX[j][i] && ADJACENCY_MATRIX[i][j] == 1) {
                            printf(" ----> node %d <--> node %d \n", i + 1, j + 1);
                        } else {
                            totalRelationsFound--;
                        }
                    }
                    if (totalRelationsFound == 0) {
                        puts(" --> no relations found");
                    }
                    totalRelationsFound = totalNodes;
                }
                int u, v;
                puts(" -> enter the first and the second nodes using their id (i.e: node 1 => id = 1) ");
                do {
                    printf(" --> first node id: ");
                    scanf("%d", &u);
                    if (u > totalNodes || u < 1) {
                        puts(" -> node's id doesn't exist :( ");
                    }
                } while(u > totalNodes || u < 1);
                do {
                    printf(" --> second node id: ");
                    scanf("%d", &v);
                    if (v > totalNodes || v < 1) {
                        puts(" -> node's id doesn't exist :( ");
                    }
                } while(v > totalNodes || v < 1);
                if (ADJACENCY_MATRIX[u - 1][v - 1] == ADJACENCY_MATRIX[v - 1][u - 1] && ADJACENCY_MATRIX[v - 1][u - 1] == 1) {
                    puts(" -> relation already exist :( ");
                } else if (u == v) {
                    puts(" -> you can't create a relation at the same node, please try again :) ");
                } else {
                    ADJACENCY_MATRIX[u - 1][v - 1] = 1;
                    ADJACENCY_MATRIX[v - 1][u - 1] = 1;
                    puts(" -> done, relation added successfully :)");
                }
            }
        } else if (strcmp(query, "ShowRelations") == 0) {
            if (ADJACENCY_MATRIX == NULL) {
                puts(" -> start the program first using 'Start' command :) ");
            } else {
                int totalRelationsFound = totalNodes;
                puts(" -> The available relations are: ");
                for(int i = 0; i < totalNodes; i++) {
                    printf(" --> for node %d \n", i +1);
                    for(int j = 0; j < totalNodes; j++) {
                        if (ADJACENCY_MATRIX[i][j] == ADJACENCY_MATRIX[j][i] && ADJACENCY_MATRIX[i][j] == 1) {
                            printf(" ----> node %d <--> node %d \n", i + 1, j + 1);
                        } else {
                            totalRelationsFound--;
                        }
                    }
                    if (totalRelationsFound == 0) {
                        puts(" ---> no relations found");
                    }
                    totalRelationsFound = totalNodes;
                }
            }
        } else if (strcmp(query, "ShowAsMatrix") == 0) {
            if (ADJACENCY_MATRIX == NULL) {
                puts(" -> start the program first using 'Start' command :) ");
            } else {
                printf("\n");
                for(int i = 0; i < totalNodes; i++) {
                    printf("        ");
                    for(int j = 0; j < totalNodes; j++) {
                        printf("  %d  ", ADJACENCY_MATRIX[i][j]);
                    }
                    printf("\n\n");
                }
            }
        } else if (strcmp(query, "RemoveRelation") == 0) {
            if (ADJACENCY_MATRIX == NULL) {
                puts(" -> start the program first using 'Start' command :) ");
            } else {
                puts(" -> Notice that the available relations are: ");
                int totalRelationsFound = totalNodes;
                for(int i = 0; i < totalNodes; i++) {
                    printf(" -> for node %d \n", i +1);
                    for(int j = 0; j < totalNodes; j++) {
                        if (ADJACENCY_MATRIX[i][j] == ADJACENCY_MATRIX[j][i] && ADJACENCY_MATRIX[i][j] == 1) {
                            printf(" ----> node %d <--> node %d \n", i + 1, j + 1);
                        } else {
                            totalRelationsFound--;
                        }
                    }
                    if (totalRelationsFound == 0) {
                        puts(" --> no relations found");
                    }
                    totalRelationsFound = totalNodes;
                }
                int u, v;
                puts(" -> enter the first and the second nodes using their id (i.e: node 1 => id = 1) ");
                do {
                    printf(" --> first node id: ");
                    scanf("%d", &u);
                    if (u > totalNodes || u < 1) {
                        puts(" -> node's id doesn't exist :( ");
                    }
                } while(u > totalNodes || u < 1);
                do {
                    printf(" --> second node id: ");
                    scanf("%d", &v);
                    if (v > totalNodes || v < 1) {
                        puts(" -> node's id doesn't exist :( ");
                    }
                } while(v > totalNodes || v < 1);
                if (ADJACENCY_MATRIX[u - 1][v - 1] == ADJACENCY_MATRIX[v - 1][u - 1] && ADJACENCY_MATRIX[v - 1][u - 1] == 0) {
                    puts(" -> there is no relation between the two :( ");
                } else if (u == v) {
                    puts(" -> you can't remove a relation at the same node because the same node can't have a relation");
                } else {
                    ADJACENCY_MATRIX[u - 1][v - 1] = 0;
                    ADJACENCY_MATRIX[v - 1][u - 1] = 0;
                    puts(" -> done, relation removed successfully :)");
                }
            }
        } else if (strcmp(query, "Clear") == 0) {
            system("cls");
            introduction();
        } else {
            if (strcmp(query, "Exit") != 0) {
                puts(" -> command not recognized :( ");
            }
        }

    } while(strcmp(query, "Exit") != 0);
    for(int i = 0; i < totalNodes; i++) {
        free(ADJACENCY_MATRIX[i]);
    }
    free(ADJACENCY_MATRIX);
    return 0;
}


void introduction(void) {
    printf(
        ">> Welcome To Your Simple Graph Data Structure :)                       \n"
        " -> with Start          you can start the program                       \n"
        " -> with ShowNodes      you can show all the available nodes            \n"
        " -> with MakeRelation   you can create a new relation between two nodes \n"
        " -> with ShowRelations  you can show all the relations for each node    \n"
        " -> with RemoveRelation you can remove an existing relation             \n"
        " -> with ShowAsMatrix   you can show your graph as a matrix             \n"
        " -> with Clear          you can clear your screen                       \n"
        " -> with Exit           you can terminate the program                   \n"
    );
}

