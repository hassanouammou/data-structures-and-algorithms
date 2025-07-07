#include <stdio.h>
#include <time.h>

int* SelectionSort(int *array, int length) {
    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            if (array[j] < array[i]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    return array;
}


int main() {
    // gcc -o selection-sort.exe selection-sort.c; 
    // $time = Measure-Command { .\selection-sort.exe }; 
    // clear 
    // .\selection-sort.exe; 
    // Write-Output "`nProgram finished with $($time.TotalSeconds)";   
    
    int array[] = {10, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 88, -5, -99999, 5};
    int length = sizeof(array) / sizeof(int), *sortedArray = SelectionSort(array, length);

    for(int i =0; i < length; i++) {
        printf("%d ", sortedArray[i]);
    }

    
    return 0;
}