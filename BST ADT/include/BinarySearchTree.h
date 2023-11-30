#pragma once

#include <iostream>
template <typename dataType>
class BinarySearchTree{
  public:

    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& t);
    ~BinarySearchTree();

    bool empty() const;
    dataType root();
    BinarySearchTree left();
    BinarySearchTree right();
  
    bool search(const dataType elementToSearch);

    void insert(const dataType elementToInsert);
    void remove(const dataType elementToRemove);
private:
    struct BinaryNode{
    dataType element;
    BinaryNode* left;
    BinaryNode* right;
}

};
