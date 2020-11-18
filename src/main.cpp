#include "../includes/sorts/sort_test_helper.h"
#include "../includes/sorts/select_sort.h"
#include "../includes/sorts/insert_sort.h"
#include "../includes/sorts/merge_sort.h"


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

template<typename T>
void mergeSort(T arr[], int n) {
    auto merge = new MergeSort<int>();
    merge->mergeSortBU(arr, n);
    delete merge;
}

int main() {
    int n = 10;
    int *arrayA = SortTestHelper::generateRandomArray(n, 0, n);
    int *arrayB = SortTestHelper::copyIntArray(arrayA, n);
    int *arrayC = SortTestHelper::copyIntArray(arrayA, n);

    SortTestHelper::testSort("Selection Sort", selectSort, arrayA, n);
    SortTestHelper::testSort("Insertion Sort", insertSortDecSwap, arrayB, n);
    SortTestHelper::testSort("MergeBu   Sort", mergeSort, arrayC, n);
    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
    return 0;
}