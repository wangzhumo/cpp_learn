//
// Created by 王诛魔 on 12/3/20.
//

#ifndef LEARN_CPP_BINARY_SEARCH_TREE_H
#define LEARN_CPP_BINARY_SEARCH_TREE_H

#include "binary_node.h"

template<class Key, class Value>
class BinarySearchTree {

public:
    BinarySearchTree();

    ~BinarySearchTree();

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value);

    void insertWhile(Key key, Value value);

    bool contain(Key key);

    BinaryNode<Key,Value>* search(Key key);

    // root为根，插入一个元素
    BinaryNode<Key,Value>* insert(BinaryNode<Key,Value> *root, Key key, Value value);

private:
    BinaryNode<Key,Value> *root;  //根节点，从这里出发
    int count;  //现在的大小
};




#endif //LEARN_CPP_BINARY_SEARCH_TREE_H
