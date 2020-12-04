//
// Created by 王诛魔 on 12/3/20.
//


#ifndef LEARN_CPP_BINARY_SEARCH_TREE_H
#define LEARN_CPP_BINARY_SEARCH_TREE_H

#include "binary_node.h"
#include <queue>


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

    BinaryNode<Key, Value> *search(Key key);

    BinaryNode<Key, Value> *min();

    BinaryNode<Key, Value> *max();

    // 前序遍历
    void preOrder();

    // 中序遍历 - 遍历出的结构刚好是按顺序排列的有序
    void inOrder();

    // 后序遍历 - 先遍历左右子树，而后到自己 （常用于释放的操作）
    void postOrder();

    // 层序遍历
    void levelOrder();

    /**
     * 假定要删除一个元素 d ，且这个元素左右节点都存在
     * 删除完毕之后，需要有一个元素s去替代d
     * s = min(d->right)
     * 就是说找到他右面节点之中最小的那个元素即可
     *
     * 满足：
     *  1.因为是右节点中的数据，则一定比左节点的所有值大
     *  2.又因为是右节点中的最小值，一定是比这个右节点小的
     *
     * (deleteMin 会在删除的同时把元素移动重新排序)
     * s-right = deleteMin(d->right)
     * s-left = d-left
     */
    void remove(Key k);

    void removeMin();

    void removeMax();


private:
    BinaryNode<Key, Value> *root;  //根节点，从这里出发
    int count;  //现在的大小

private:
    // root为根，插入一个元素
    BinaryNode<Key, Value> *insert(BinaryNode<Key, Value> *root, Key key, Value value);

    // 递归释放
    void destroy(BinaryNode<Key, Value> *node);

    // 递归删除最小值
    BinaryNode<Key, Value> *removeMinInner(BinaryNode<Key, Value> *node);

    // 递归删除最大值
    BinaryNode<Key, Value> *removeMaxInner(BinaryNode<Key, Value> *node);

    // 递归删除指定元素
    BinaryNode<Key, Value> *remove(BinaryNode<Key, Value> *node,Key k);
};


#endif //LEARN_CPP_BINARY_SEARCH_TREE_H
