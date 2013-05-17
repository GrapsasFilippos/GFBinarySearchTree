#ifndef GFBINARYSEARCHTREE_HPP
#define GFBINARYSEARCHTREE_HPP

#include <iostream>

#include "gfbinarysearchtreenode.hpp"

using namespace std;


class GFBinarySearchTree
{
    public:
        GFBinarySearchTree();
        void add(int *);
        void printTree();

    private:
        void printTree(GFBinarySearchTreeNode *node, int tabs);

        GFBinarySearchTreeNode *head;
};


#endif // GFBINARYSEARCHTREE_HPP
