//
// Created by 王诛魔 on 12/3/20.
//

#ifndef LEARN_CPP_BINARY_SEARCH_TREE_H
#define LEARN_CPP_BINARY_SEARCH_TREE_H

template<typename Key, typename Value>
class BinarySearchTree {

public:
    BinarySearchTree();

    ~BinarySearchTree();

    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value);

    void insertWhile(Key key, Value value);

private:
    Node *root;  //根节点，从这里出发
    int count;  //现在的大小


private:
    // root为根，插入一个元素
    // Node *insert(Node *root, Key key, Value value);

};


#endif //LEARN_CPP_BINARY_SEARCH_TREE_H
