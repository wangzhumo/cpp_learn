//
// Created by 王诛魔 on 12/3/20.
//

#include "../../../includes/search/binary_search_tree.h"


template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree() {
    this->root = nullptr;
    this->count = 0;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree() {
    //TODO 清除数据
}

// 插入一个元素
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::insert(Key key, Value value) {
    this->root = insert(root, key, value);
}


template<typename Key, typename Value>
BinaryNode<Key, Value> *BinarySearchTree<Key, Value>::insert(BinaryNode<Key, Value> *root, Key key, Value value) {
    // 如果root为空，则直接插入即可
    if (root == nullptr) {
        // 直接返回，
        count++;
        // 此处直接返回，给上一个递归
        return new BinaryNode<Key, Value>(key, value);
    }
    // 如果不为空，则判断即可
    if (key == root->key) {
        // 如果相同，直接更新即可
        root->value = value;
    } else if (key < root->key) {
        // 如果小于root值，则应该插入左边
        root->left = insert(root->left, key, value);
    } else {
        // 否则插入右边
        root->right = insert(root->right, key, value);
    }
    return root;
}


template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::insertWhile(Key key, Value value) {
    // 通过for循环来加入元素
    BinaryNode<Key, Value> *p = root;
    // pre用于记录上一个可用的node,因为p被用于中断条件使用
    BinaryNode<Key, Value> *pre = p;
    // 开始循环，如果p不为空，就一直循环
    while (p) {
        if (key > p->key) {
            // 要插入的key大于当前的这个node，应该修改p为他的右节点
            pre = p;
            p = p->right;
        } else if (key < p->key) {
            // 要插入的key小于当前的这个node，应该修改p为他的左节点
            pre = p;
            p = p->left;
        } else {
            // 否则就是相等了，这个时候我需要去覆盖原来的值
            // 此时我们不修改pre的指向即可让他覆盖
        }
    }
    // 如果是null,或者查到一个p的值是可以插入的了
    if (key > pre->key) {
        pre->right = new BinaryNode<Key, Value>(key, value);
    } else if (key < pre->key) {
        pre->left = new BinaryNode<Key, Value>(key, value);
    } else {
        // 直接覆盖value即可
        pre->value = value;
    }

}

// 递归调用，node每次指定
template<typename Key, typename Value>
BinaryNode<Key, Value> *searchInner(BinaryNode<Key, Value> *node, Key key) {
    // 如果为空，那就是没找到
    if (node == nullptr) {
        return nullptr;
    }
    if (key == node->getKey()) {
        // 直接返回
        return node;
    } else if (key < node->getKey()) {
        // 如果我小于当前的node,继续查找左节点
        return search(node->getLeft(), key);
    } else {
        return search(node->getRight(), key);
    }
}


template<typename Key, typename Value>
BinaryNode<Key, Value> *BinarySearchTree<Key, Value>::search(Key key) {
    // 定义一个p
    return searchInner(root, key);
}


// 递归查询,所以需要外部指定当前要查找的node
template<typename Key, typename Value>
bool containInner(BinaryNode<Key, Value> *node, Key key) {
    // 退出条件之一 - 无法查询到
    if (node == nullptr) {
        return false;
    }
    // 退出条件之二 - 已经查询到了
    if (key == node->getKey()) {
        // 直接返回即可
        return true;
    } else if (key < node->getKey()) {
        // 如果大于我，我就去左边去查找。
        return containInner(node->getLeft(), key);
    } else {
        return containInner(node->getRight(), key);
    }
}


template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::contain(Key key) {
    return containInner(key);
}



