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
        void printTree(bool addresses = 0);

    private:
        void printTree(GFBinarySearchTreeNode *node, int tabs, bool addresses = 0);

        GFBinarySearchTreeNode *head;
};


#endif // GFBINARYSEARCHTREE_HPP
