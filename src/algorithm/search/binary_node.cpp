//
// Created by 王诛魔 on 12/3/20.
//

#include "../../../includes/search/binary_node.h"


template<class Key, class Value>
BinaryNode<Key, Value>::BinaryNode(Key key, Value value) {
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

template<class Key, class Value>
BinaryNode<Key, Value>::BinaryNode(BinaryNode<Key, Value> *node) {
    this->key = node->getKey();
    this->value = node->getValue();
    this->left = node->getLeft();
    this->right = node->getRight();
}


template<class Key, class Value>
Value BinaryNode<Key, Value>::getValue() {
    return this->value;
}


template<class Key, class Value>
Key BinaryNode<Key, Value>::getKey() {
    return this->key;
}


template<class Key, class Value>
BinaryNode<Key, Value> *BinaryNode<Key, Value>::getLeft() {
    return this->left;
}

template<class Key, class Value>
BinaryNode<Key, Value> *BinaryNode<Key, Value>::getRight() {
    return this->right;
}

template<class Key, class Value>
void BinaryNode<Key, Value>::setLeft(BinaryNode<Key, Value> *node) {
    this->left = node;
}

template<class Key, class Value>
void BinaryNode<Key, Value>::setRight(BinaryNode<Key, Value> *node) {
    this->right = node;
}

template<class Key, class Value>
void BinaryNode<Key, Value>::setValue(Value v) {
    this->value = v;
}

template<class Key, class Value>
void BinaryNode<Key, Value>::setKey(Key k) {
    this->key = k;
}


// Explicit template instantiation
template
class BinaryNode<std::string, int>;