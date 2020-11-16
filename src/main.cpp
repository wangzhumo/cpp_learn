#include "../includes/sorts/sort_test_helper.h"
#include "../includes/sorts/select_sort.h"
#include "../includes/sorts/insert_sort.h"


template<typename T>
void selectSort(T arr[], int n) {
    auto selectSort = new SelectionSort<int>();
    selectSort->selectionSort(arr, n);

    delete (selectSort);
}

template<typename T>
void insertSort(T arr[], int n) {
    auto insert = new InsertionSort<int>();
    insert->insertionSort(arr, n);
    delete insert;
}

template<typename T>
void insertSortDecSwap(T arr[], int n) {
    auto insert = new InsertionSort<int>();
    insert->insertionSortDecSwap(arr, n);
    delete insert;
}

int main() {
    int n = 10000;
    int *arrayA = SortTestHelper::generateNearlyOrderArray(n, 300);
    int *arrayB = SortTestHelper::copyIntArray(arrayA,n);
    SortTestHelper::testSort("Selection Sort", selectSort, arrayA, n);
    SortTestHelper::testSort("Insertion Sort", insertSortDecSwap, arrayB, n);
    delete[] arrayA;
    delete[] arrayB;
    return 0;
}