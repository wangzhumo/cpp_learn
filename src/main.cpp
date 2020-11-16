#include "../includes/sorts/sort_test_helper.h"
#include "../includes/sorts/select_sort.h"

#include <iostream>

int main() {
    int n  = 10000;
    int *array = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("Selection Sort",selectionSort,array,n);

    delete [] array;
    return 0;
}