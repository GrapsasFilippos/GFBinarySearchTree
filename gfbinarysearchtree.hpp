#ifndef GFBINARYSEARCHTREE_HPP
#define GFBINARYSEARCHTREE_HPP

#include <iostream>

#include "gfbinarysearchtreenode.hpp"

using namespace std;


class GFBinarySearchTree
{
    public:
        GFBinarySearchTree();
        bool add(int *);
        int *search(int &);
        int *remove(int &);
        void printTree(bool addresses = 0);

    private:
        GFBinarySearchTreeNode *getMaximum(GFBinarySearchTreeNode *node = 0);
        GFBinarySearchTreeNode *getMinimum(GFBinarySearchTreeNode *node = 0);
        void printTree(GFBinarySearchTreeNode *, int tabs, bool addresses = 0);

        GFBinarySearchTreeNode *head;
};


#endif // GFBINARYSEARCHTREE_HPP
