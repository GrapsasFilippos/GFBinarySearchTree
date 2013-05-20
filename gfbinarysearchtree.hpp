#ifndef GFBINARYSEARCHTREE_HPP
#define GFBINARYSEARCHTREE_HPP

#include <iostream>

#include "gfbinarysearchtreenode.hpp"

using namespace std;


template< class C >
class GFBinarySearchTree
{
    public:
        GFBinarySearchTree();
        bool add( C );
        C search( C );
        C remove( C );
        void printTree( bool addresses = 0 );

    private:
        GFBinarySearchTreeNode< C > * getMaximum( GFBinarySearchTreeNode< C > * node = 0);
        GFBinarySearchTreeNode< C > * getMinimum( GFBinarySearchTreeNode< C > * node = 0 );
        void printTree( GFBinarySearchTreeNode< C > *, int tabs, bool addresses = 0 );

        GFBinarySearchTreeNode< C > * head;
};


#include "gfbinarysearchtree.cpp"

#endif // GFBINARYSEARCHTREE_HPP
