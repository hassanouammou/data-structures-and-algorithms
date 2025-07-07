#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int BinarySearch(int array[], int length, int target) {
    int left = 0, right = length - 1, mid, current_possibility = 0;
    while(left != right) {
        current_possibility++;
        mid = floor((float)((left + right) / 2)); 
        if (target == array[mid]) {
            return mid;
        } else {
            if (target > array[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (left == right && target == array[left] && target == array[right]) {
                return left;
            }
        }
    }
    return -1;
}   

int main() {
    // gcc -o binary-search.exe binary-search.c && binary-search.exe
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 31, 45, 55, 99, 202, 304, 1000}, number;
    printf(">> what index you looking for: ");
    scanf("%d", &number);
    int length = sizeof(array) / sizeof(int);
    int result = BinarySearch(array, length, number);
    if (result == -1) {
        printf(">> this number does not exist in this array :(");
    } else {
        printf(">> the index of %d is %d", number, result);
    }



    return 0;
}