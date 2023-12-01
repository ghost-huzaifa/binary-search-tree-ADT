#include "BinarySearchTree.h"

template <class T>
BinarySearchTree<T> :: BinarySearchTree()                             //Constructors
{
    root = NULL;
}

template <class T>
BinarySearchTree<T> :: BinarySearchTree(const BinarySearchTree& t) : root(deepCopy(t.root))
{
    //Copy Constructor calls a recursive deepCopy Function
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()                            //Destructor
{
    makeEmpty(this->root);
}

template <class T>
bool BinarySearchTree<T> :: empty() const
{
    return root == NULL;
}

template <class T>
bool BinarySearchTree<T> :: search(const T elementToSearch)           //Contains
{
    return contains(elementToSearch, this->root);
}

template <class T>
void BinarySearchTree<T> :: insert(const T elementToInsert)           //Compose element into a tree
{
    insert(elementToInsert, this->root);
}

template <class T>
void BinarySearchTree<T> :: remove(const T elementToRemove)           //decompose element from a tree
{
    remove(elementToRemove, this->root);
}

template <class T>
bool BinarySearchTree<T> :: contains(const T elementToSearch, BinaryNode*& t) const        //Contains
{
    if (t == NULL)
        return false;
    else if (elementToSearch == t->element)
        return true;
    else if (elementToSearch > t->element)
        return contains(elementToSearch, t->right);
    else if (elementToSearch < t->element)
        return contains(elementToSearch, t->left);
}

template <class T>
void BinarySearchTree<T> :: insert(const T elementToInsert, BinaryNode*& t) const           //Compose element into a tree
{
    if (t == NULL)
        t = new BinaryNode(elementToInsert, NULL, NULL);
    else if (elementToInsert < t->element)
        insert(elementToInsert, t->left);
    else if (elementToInsert > t->element)
        insert(elementToInsert, t->right);
    else
        return;
}

template <class T>
void BinarySearchTree<T> :: remove(const T elementToRemove, BinaryNode*& t) const           //decompose element from a tree
{
    if (t == NULL)
        return;
    else if (elementToRemove < t->element)
        remove(elementToRemove, t->left);
    else if (elementToRemove > t->element)
        remove(elementToRemove, t->right);
    else if (t->left != NULL && t->right != NULL)   //Node to be deleted has 2 children
    {
        t->element = findMin(t->right) ->element;
        remove(t->element, t->right);
    }
    else                                            //Node has 1 or no children
    {
        BinaryNode* oldNode = t;
        if (t->left != NULL)
            t = t->left;
        else if (t->right != NULL)
            t = t->right;
        delete oldNode;
    }
}

template <class T>
void BinarySearchTree<T> :: makeEmpty (BinaryNode*& t)
{
    if (t!=NULL)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

template <class T>
typename BinarySearchTree<T> :: BinaryNode* BinarySearchTree<T> :: findMin(BinaryNode*& t) const
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

template <class T>
typename BinarySearchTree<T> :: BinaryNode* BinarySearchTree<T> :: deepCopy(BinaryNode* t)
{
    if (t != NULL)
    {
        BinaryNode* newNode = new BinaryNode();
        newNode->element = t->element;
        newNode->left = deepCopy(t->left);
        newNode->right = deepCopy(t->right);
        return newNode;
    }
    else
        return NULL;
}
