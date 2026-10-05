#ifndef BTNODE_HPP
#define BTNODE_HPP

template <typename T>
class BTNode {
public:
    BTNode(const T& val = T(), BTNode<T>* l = nullptr, BTNode<T>* r = nullptr) 
        : data(val), left(l), right(r) {
            
        }

    bool isLeaf() const {
        return (!left && !right);
    }
    bool hasOnlyOneChild() const {
        return (right && !left) || (!right && left);
    }
    bool hasTwoChildren() const {
        return right && left;
    }

    T data;
    BTNode<T>* left;
    BTNode<T>* right;
};

#endif