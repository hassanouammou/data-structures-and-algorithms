#include <stdio.h>
#include <time.h>

int* BubbleSort(int array[], int length) {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return array;
}


int main() {
    // gcc -o bubble-sort.exe bubble-sort.c && bubble-sort.exe
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -2, -9, -44};
    int length = sizeof(array) / sizeof(int);
    int *sortedArray = BubbleSort(array, length);

    for(int i =0; i < length; i++) {
        printf("%d ", sortedArray[i]);
    }

    
    return 0;
}