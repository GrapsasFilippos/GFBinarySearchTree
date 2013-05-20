#ifndef GFBINARYSEARCHTREENODE_HPP
#define GFBINARYSEARCHTREENODE_HPP

#include "gfbinarysearchtreedatacontainer.hpp"


template< class C >
class GFBinarySearchTreeNode
{
    public:
        GFBinarySearchTreeNode();
        void setData( C );
        C getData();
        void setLeft( GFBinarySearchTreeNode< C > * );
        GFBinarySearchTreeNode< C > * getLeft();
        void setRight( GFBinarySearchTreeNode< C > * );
        GFBinarySearchTreeNode< C > * getRight();
        unsigned short childrenNumber();
        GFBinarySearchTreeNode< C > * getTheChild();

    private:

        GFBinarySearchTreeNode< C > * left;
        GFBinarySearchTreeNode< C > * right;

        C data;
};


#include "gfbinarysearchtreenode.cpp"

#endif // GFBINARYSEARCHTREENODE_HPP
