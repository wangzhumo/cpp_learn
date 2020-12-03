//
// Created by 王诛魔 on 12/3/20.
//

#ifndef LEARN_CPP_BINARY_SEARCH_TREE_H
#define LEARN_CPP_BINARY_SEARCH_TREE_H

template<class Key, class Value>
class BinarySearchTree {


private:
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

    Node *root;  //根节点，从这里出发
    int count;  //现在的大小

public:
    BinarySearchTree();

    ~BinarySearchTree();

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }
};


#endif //LEARN_CPP_BINARY_SEARCH_TREE_H
