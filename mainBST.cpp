// Create BST, insert nodes, check contain method

#include "BST.hpp"
#include <string>
#include <iostream>

int main(void) {
    BST<std::string> tree;

    tree.insert("hello");
    tree.insert("apple");
    tree.insert("zoo");
    tree.insert("carrot");

    std::cout << "Has apple " << tree.contains("apple") << std::endl;
    std::cout << "Has cat " << tree.contains("cat") << std::endl;

    auto node = tree.search("zoo");
    if (node) {
        std::cout << node->data << std::endl;
    }

    tree.inorder();
    
    return 0;
}

