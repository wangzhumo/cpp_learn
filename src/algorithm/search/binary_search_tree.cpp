//
// Created by 王诛魔 on 12/3/20.
//

#include "../../../includes/search/binary_search_tree.h"


template<class Key, class Value>
BinarySearchTree<Key,Value>::BinarySearchTree() {
    this->root = nullptr;
    this->count = 0;
}

template<typename Key, typename Value>
BinarySearchTree<Key,Value>::~BinarySearchTree() {
    //TODO 清除数据
}

