#include <stdio.h>
#include <stdlib.h>

int LinearSearchUsingForLoopForArray(int array[], int length, int target) {
    // Auxilary Space is O(1) [because of the int i]
    for(int i = 0; i < length; i++) {
        if (target == array[i]) {
            return i;            
        }
    }
    return -1;
}

int LinearSearchUsingWhileLoopForArray(int array[], int length, int target) {
    int index = 0, current = array[index], last = array[length - 1];
    while(current != last) {
        if (current == target) {
            return index;
        }
        current = array[index++];
    }
    return -1;
}

typedef struct node {
    int data;
    struct node *next;
} node;


int LinearSearchUsingForLoopForSinglyLinkedList(node *HEAD, int target) {
    node *TEMP_HEAD = HEAD;
    int i = 0;
    while(target != TEMP_HEAD -> data) {
        TEMP_HEAD = TEMP_HEAD -> next;
        i++;
    }
    return i;
}



int main() {
    // gcc -o linear-search linear-search.c && linear-search
    
    node first, second, third, fourth;

    node *HEAD = &first;



    first.data  = 99;
    second.data = 59;
    third.data  = 50;
    fourth.data = 28;

    first.next  = &second;
    second.next = &third;
    third.next  = &fourth;
    fourth.next = NULL;




    return 0;
}