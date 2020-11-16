#include "../src/algorithm/sorts/select_sort.cpp"
#include "../includes/sorts/sort_test_helper.h"
#include <iostream>

int main() {
    int n  = 10000;
    int *array = SortTestHelper::generateRandomArray(n,0,n);
    selectionSort<int>(array, n);
    SortTestHelper::printArray(array,n);

    delete [] array;
    return 0;
}