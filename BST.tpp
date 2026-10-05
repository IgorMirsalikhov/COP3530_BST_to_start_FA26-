#include "BST.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
BST<T>::BST() : root(nullptr) {
    
}


template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::insert(const T& val) {
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }

    BTNode<T>* cur = root;
    BTNode<T>* parent = root;

    // Iterate through BST
    while (cur) {
        parent = cur;

        if (val < cur->data) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    if (val < parent->data) {
        parent->left = new BTNode<T>(val);
    }
    else {
        parent->right = new BTNode<T>(val);
    }
}

template <typename T>
bool BST<T>::contains(const T& val) const {
    const BTNode<T>* cur = root;

    while (cur) {
        if (cur->data == val) {
            return true;
        }
        else if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return false;
}

template <typename T>
const BTNode<T>* BST<T>::search(const BTNode<T>* node, const T& val) const {
    // Base case
    if (!node || node->data == val) {
        return node;
    }
    else if (val < node->data) {
        return search(node->left, val);
    }
    else {
        return search(node->right, val);
    }
}

template <typename T>
const BTNode<T>* BST<T>::search(const T& val) const {
    return search(root, val);
}

template <typename T>
void BST<T>::inorder() const {
    inorder(root);
}

template <typename T>
void BST<T>::inorder(const BTNode<T>* node) const {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

template <typename T>
const BTNode<T>* BST<T>::searchParent(const T& val) const {
    if (empty() || root->data == val) {
        return nullptr;
    }
    const BTNode<T>* cur = root;
    while (cur) {
        if (cur->data > val) {
            if (cur->left && cur->left->data == val) {
                return cur;
            }
            cur = cur->left;
        }
        else {
            if (cur->right && cur->right->data == val) {
                return cur;
            }
            cur = cur->right;
        }
    }

    return nullptr;
}


template <typename T>
const BTNode<T>* BST<T>::getMinNode() const {
    return getMinNode(root);
}

template <typename T>
const BTNode<T>* BST<T>::getMinNode(const BTNode<T>* node) const {
    if (!node) {
        return nullptr;
    }
    else if (!node->left) {
        return node;
    }
    return getMinNode(node->left);
}

template <typename T>
void BST<T>::deleteLeaf(BTNode<T>* child, BTNode<T>* parent) {
    if (!child) {
        throw std::logic_error("deleteLeaf: no node to delete\n");
    }
    if (!parent) {
        delete root;
        root = nullptr;
        return;
    }
    if (parent->left == child) { //left kid
        parent->left = nullptr;
    }
    else if (parent->right == child) { //right kid
        parent->right = nullptr;
    }

    delete child;
}

template <typename T>
void BST<T>::deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent) {
    if (child == root) {
        BTNode<T>* to_delete = root;
        root = (root->left) ? root->left : root->right;
        delete to_delete;
        return;
    }
    BTNode<T>* grand_kid = (child->right) ? child->right : child->left;
    if (parent->right == child) {
        parent->right = grand_kid;
    }
    if (parent->left == child) {
        parent->left = grand_kid;
    }

    //release the memory
    delete child;
}

template <typename T>
void BST<T>::print() const {
    std::cout << "===============================\n";
    print("", root, false);    
    std::cout << "===============================\n";
}

template <typename T>
void BST<T>::print(const std::string& prefix, const BTNode<T>* node, bool isRight) const {
    if (!node) {
        return;
    }
    std::cout << prefix;
    if (node != root) {
        std::cout << (isRight ? "R--" : "L--");
    }
    else {
        std::cout << "---";
    }

    // Print the value of the node
    std::cout << node->data << std::endl;

    // Go to the next level of the tree
    print(prefix + "   ", node->right, true);
    print(prefix + "   ", node->left, false);

}