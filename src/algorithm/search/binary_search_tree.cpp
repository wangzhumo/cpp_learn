//
// Created by 王诛魔 on 12/3/20.
//


#include <iostream>
#include "../../../includes/search/binary_search_tree.h"

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree() {
    this->root = nullptr;
    this->count = 0;
}


template<class Key, class Value>
void BinarySearchTree<Key, Value>::destroy(BinaryNode<Key, Value> *node) {
    // 采用后序遍历的形式，释放
    // 只要不为空就继续释放
    if (node != nullptr) {
        // 此时我们是一个后序遍历，先把left,right释放掉
        destroy(node->getLeft());
        destroy(node->getRight());
        // 最后把自己释放
        delete node;
        count--;
    }
}


template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree() {
    destroy(root);
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
    if (key == root->getKey()) {
        // 如果相同，直接更新即可
        root->setValue(value);
    } else if (key < root->getKey()) {
        // 如果小于root值，则应该插入左边
        root->setLeft(insert(root->getLeft(), key, value));
    } else {
        // 否则插入右边
        root->setRight(insert(root->getRight(), key, value));
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
        if (key > p->getKey()) {
            // 要插入的key大于当前的这个node，应该修改p为他的右节点
            pre = p;
            p = p->getRight();
        } else if (key < p->getKey()) {
            // 要插入的key小于当前的这个node，应该修改p为他的左节点
            pre = p;
            p = p->getLeft();
        } else {
            // 否则就是相等了，这个时候我需要去覆盖原来的值
            // 此时我们不修改pre的指向即可让他覆盖
        }
    }
    // 如果是null,或者查到一个p的值是可以插入的了
    if (key > pre->getKey()) {
        pre->setRight(new BinaryNode<Key, Value>(key, value));
    } else if (key < pre->getKey()) {
        pre->setLeft(new BinaryNode<Key, Value>(key, value));
    } else {
        // 直接覆盖value即可
        pre->setValue(value);
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
        return searchInner(node->getLeft(), key);
    } else {
        return searchInner(node->getRight(), key);
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
    return containInner(root, key);
}

template<class Key, class Value>
void preOrderInner(BinaryNode<Key, Value> *node) {
    // 只要不为空就继续遍历
    if (node != nullptr) {
        // 此时我们是一个前序遍历，先把自己先打印出来
        std::cout << node->getKey() << std::endl;
        // 然后分别打印 left , right,他们也会先把自己打印出来
        preOrderInner(node->getLeft());
        preOrderInner(node->getRight());
    }
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::preOrder() {
    preOrderInner(root);
}

template<class Key, class Value>
void inOrderInner(BinaryNode<Key, Value> *node) {
    // 只要不为空就继续遍历
    if (node != nullptr) {
        // 此时我们是一个中序遍历，先把left打印出来
        inOrderInner(node->getLeft());
        std::cout << node->getKey() << std::endl;
        // 然后分别打印 right
        inOrderInner(node->getRight());
    }
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::inOrder() {
    inOrderInner(root);
}

template<class Key, class Value>
void postOrderInner(BinaryNode<Key, Value> *node) {
    // 只要不为空就继续遍历
    if (node != nullptr) {
        // 此时我们是一个后序遍历，先把left,right打印出来
        postOrderInner(node->getLeft());
        postOrderInner(node->getRight());
        // 最后把自己打印出来
        std::cout << node->getKey() << std::endl;
    }
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::postOrder() {
    postOrderInner(root);
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::levelOrder() {
    // 层序的遍历，借助队列进行遍历
    std::queue<BinaryNode<Key, Value> *> queue;
    queue.push(root);
    // 先把root放进去，而后依次入队,为空后停止遍历
    while (!queue.empty()) {
        // 拿出一个元素
        BinaryNode<Key, Value> *p = queue.front();
        queue.pop();

        // 做遍历要执行的操作，如打印
        std::cout << p->getKey() << std::endl;

        // 此时把p中的元素入队
        if (p->getLeft() != nullptr) {
            queue.push(p->getLeft());
        }
        if (p->getRight() != nullptr) {
            queue.push(p->getRight());
        }
    }
}

// 递归查找最小值
template<class Key, class Value>
BinaryNode<Key, Value> *minInner(BinaryNode<Key, Value> *node) {
    // 直接递归
    // 退出条件是一个左节点没有子节点了，它就是最小值
    if (node->getLeft() == nullptr) {
        return node;
    }
    // 否则就一直往下找即可
    return minInner(node->getLeft());
}


template<class Key, class Value>
BinaryNode<Key, Value> *BinarySearchTree<Key, Value>::min() {
    BinaryNode<Key, Value> *p = root;
    while (p != nullptr && p->getLeft() != nullptr) {
        // 如果不为空，就一直向下
        p = p->getLeft();
    }
    // 递归的查找最小值
    // minInner(root);
    return p;
}

template<class Key, class Value>
BinaryNode<Key, Value> *maxInner(BinaryNode<Key, Value> *node) {
    // 直接递归.
    // 退出条件是一个右节点没有子节点了，它就是最大值
    if (node->getRight() == nullptr) {
        return node;
    }
    // 否则就一直往下找即可
    return maxInner(node->getRight());
}

template<class Key, class Value>
BinaryNode<Key, Value> *BinarySearchTree<Key, Value>::max() {
    return maxInner(root);
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::remove(Key k) {
    root = remove(root, k);
}

template<class Key, class Value>
BinaryNode<Key, Value> *BinarySearchTree<Key, Value>::remove(BinaryNode<Key, Value> *node, Key k) {
    // break
    if (node == nullptr) {
        return nullptr;
    }
    // find node
    if (node->getKey() > k) {
        // 大于的话去左边
        node->setLeft(remove(node->getLeft(), k));
        return node;
    } else if (node->getKey() < k) {
        node->setRight(remove(node->getRight(), k));
        return node;
    } else {
        // 找到了这个key,判断左右孩子的状态
        if (node->getLeft() == nullptr) {
            // 如果为空,保存右边节点，并且赋值
            BinaryNode<Key, Value> *rightNode = node->getRight();
            // 删除这个node
            delete node;
            count--;
            return rightNode;
        }
        if (node->getRight() == nullptr) {
            // 如果为空,保存右边节点，并且赋值
            BinaryNode<Key, Value> *leftNode = node->getLeft();
            // 删除这个node
            delete node;
            count--;
            return leftNode;
        }

        // 上面的情况是，只有左边或者右边，如果下来说明都有node
        // 使用之前的删除法
        // 1.确定要删除的节点,find Min value,copy node
        BinaryNode<Key, Value> *minRight = new BinaryNode<Key, Value>(minInner(node->getRight()));
        count++;

        // 2.给minRight设置新的right,left
        minRight->setRight(removeMinInner(node->getRight()));
        minRight->setLeft(node->getLeft());

        // 3.删除node
        delete node;
        count--;

        // 4.返回新的node节点,递归的上一步setLeft
        // 或者setRight会把minRight添加到树中
        return minRight;
    }
}

// 递归
template<class Key, class Value>
BinaryNode<Key, Value> *BinarySearchTree<Key, Value>::removeMinInner(BinaryNode<Key, Value> *node) {
    // 如果遇到没有left节点的，执行删除即可
    if (node->getLeft() == nullptr) {
        // 把这right的值记录下来，用于返回，为null时不会更新node的值
        BinaryNode<Key, Value> *rightNode = node->getRight();
        // 如果这个节点没有left节点了，说明它就是最小值，删除即可
        delete node;
        count--;
        return rightNode;
    }

    // 如果getLeft不为空，则继续往下
    node->setLeft(removeMinInner(node->getLeft()));
    // 这里的返回是为了递归的时候，给上一步的setLeft赋值
    // 1.下一个会成功删除则 setLeft 会赋值为下一个的Right节点
    // 2.下一个没有成功删除，则返回的是node自己，setLeft还是原来的自己
    return node;
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::removeMin() {
    removeMinInner(root);
}

// 递归
template<class Key, class Value>
BinaryNode<Key, Value> *BinarySearchTree<Key, Value>::removeMaxInner(BinaryNode<Key, Value> *node) {
    // 如果遇到没有left节点的，执行删除即可
    if (node->getRight() == nullptr) {
        // 把这right的值记录下来，用于返回，为null时不会更新node的值
        BinaryNode<Key, Value> *leftNode = node->getLeft();
        // 如果这个节点没有left节点了，说明它就是最小值，删除即可
        delete node;
        count--;
        return leftNode;
    }

    // 如果getLeft不为空，则继续往下
    node->setRight(removeMaxInner(node->getRight()));
    // 这里的返回是为了递归的时候，给上一步的setRight赋值
    // 1.下一个会成功删除则 setRight 会赋值为下一个的Left节点
    // 2.下一个没有成功删除，则返回的是node自己，setRight还是原来的自己
    return node;
}


template<class Key, class Value>
void BinarySearchTree<Key, Value>::removeMax() {
    removeMaxInner(root);
}


// Explicit template instantiation
template
class BinarySearchTree<std::string, int>;





