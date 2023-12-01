#pragma once

#include <iostream>
template <class T>
class BinarySearchTree{
  public:

    BinarySearchTree();                             //Constructors
    BinarySearchTree(const BinarySearchTree& t);
    ~BinarySearchTree();                            //Destructor

    bool empty() const;

    bool search(const T elementToSearch);           //Contains
    void insert(const T elementToInsert);           //Compose element into a tree
    void remove(const T elementToRemove);           //decompose element from a tree


private:

    struct BinaryNode
    {

        T element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(T element, BinaryNode* left, BinaryNode* right)  //Constructor for a Binary Node
        {
            this->element = element;
            this->left = left;
            this->right = right;
        }
        BinaryNode()
        {
            this->left = NULL;
            this->right = NULL;
        }

    };

    //member attributes
    BinaryNode* root;


    /*Functions for proper and reliable
    internal working of Binary Search Tree*/

    bool contains(const T elementToSearch, BinaryNode*& t) const;
    void insert(const T elementToInsert, BinaryNode*& t) const;
    void remove(const T elementToRemove, BinaryNode*& t) const;

    void makeEmpty(BinaryNode*& t);                 //Recursive destructor

    BinaryNode* findMin(BinaryNode*& t) const;
    BinaryNode* deepCopy(BinaryNode* t);

};
