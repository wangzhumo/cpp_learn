#include "../includes/heap/index_heap.h"
#include "../includes/heap/max_heap.h"
#include "../includes/sorts/insert_sort.h"
#include "../includes/sorts/merge_sort.h"
#include "../includes/sorts/quick_sort.h"
#include "../includes/sorts/select_sort.h"
#include "../includes/sorts/sort_test_helper.h"
#include "../includes/search/binary_search.h"
#include "../includes/search/binary_search_tree.h"

template <typename T>
void selectSort(T arr[], int n) {
    SelectionSort<int> selectSort = SelectionSort<int>();
    selectSort.selectionSort(arr, n);
}

template <typename T>
void insertSort(T arr[], int n) {
    InsertionSort<int> insert = InsertionSort<int>();
    insert.insertionSort(arr, n);
}

template <typename T>
void insertSortDecSwap(T arr[], int n) {
    InsertionSort<int> insert = InsertionSort<int>();
    insert.insertionSortDecSwap(arr, n);
}

template <typename T>
void mergeSort(T arr[], int n) {
    MergeSort<int> merge = MergeSort<int>();
    merge.mergeSortBU(arr, n);
}

template <typename T>
void quickSort(T arr[], int n) {
    QuickSort<int> merge = QuickSort<int>();
    merge.quickSort(arr, n);
}

template <typename T>
void quickSortDouble(T arr[], int n) {
    QuickSort<int> quick = QuickSort<int>();
    quick.quickSortDouble(arr, n);
}

template <typename T>
void heapSort(T arr[], int n) {
    MaxHeap<int> maxHeap = MaxHeap<int>(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxHeap.pop();
    }
}

template <typename T>
void indexHeapSort(T arr[], int n) {
    IndexHeap<int> maxHeap = IndexHeap<int>(n);
    for (int i = 0; i < n; i++) {
        maxHeap.insert(i,arr[i]);
    }
    for (int j = n-1; j >= 0; j--) {
        arr[j] = maxHeap.pop();
    }
}

int main() {
    int n = 100000;
    int* arrayA = SortTestHelper::generateRandomArray(n, 0, n);
    int* arrayB = SortTestHelper::copyIntArray(arrayA, n);
    int* arrayC = SortTestHelper::copyIntArray(arrayA, n);
    int* arrayD = SortTestHelper::copyIntArray(arrayA, n);

    // SortTestHelper::testSort("Selection Sort", selectSort, arrayA, n);
    // SortTestHelper::testSort("Insertion Sort", insertSortDecSwap, arrayB, n);
    // SortTestHelper::testSort("MergeBu   Sort", mergeSort, arrayB, n);
    // SortTestHelper::testSort("Quick     Sort", quickSort, arrayC, n);
    // SortTestHelper::testSort("Quick Double Sort", quickSortDouble, arrayD,n);
    // SortTestHelper::testSort("IndexHeap    Sort", indexHeapSort, arrayC, n);
    BinarySearch<int> binarySearchTree = BinarySearch<int>();
    binarySearchTree.binarySearch(arrayA,n,998);
    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
    delete[] arrayD;
    return 0;
}