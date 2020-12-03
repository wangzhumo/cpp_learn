//
// Created by 王诛魔 on 12/3/20.
//

#include "../../../includes/search/binary_search.h"


template<class T>
int BinarySearch<T>::binarySearch(T arr[], int n, T target) {
    // 首先定义查找的区间 [l,r] 前闭后闭
    int l = 0;
    int r = n - 1;
    // 循环并查找,如果相遇还没有退出，则不存在
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        // 开始判断
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            // 如果中间值比自己要小，则应该移动mid的位置
            l = mid + 1;
        } else {
            // 此处的-1，是因为前面已经确定mid != target
            r = mid - 1;
        }
    }
    return -1;
}



// Explicit template instantiation
template
class BinarySearch<int>;