//
// Created by 王诛魔 on 12/3/20.
//

#ifndef LEARN_CPP_BINARY_NODE_H
#define LEARN_CPP_BINARY_NODE_H

#include <string>

template<class Key, class Value>
class BinaryNode {

    Key key;
    Value value;
    BinaryNode *left;
    BinaryNode *right;

public:

    BinaryNode<Key, Value>(Key k, Value v);

    BinaryNode<Key, Value>(BinaryNode<Key, Value> *node);

    Value getValue();
    Key getKey();
    void setValue(Value v);
    void setKey(Key k);

    BinaryNode<Key, Value> *getLeft();

    BinaryNode<Key, Value> *getRight();

    void setLeft(BinaryNode<Key, Value> *node);

    void setRight(BinaryNode<Key, Value> *node);
};




#endif //LEARN_CPP_BINARY_NODE_H
