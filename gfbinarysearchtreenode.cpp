#ifndef GFBINARYSEARCHTREENODE_CPP
#define GFBINARYSEARCHTREENODE_CPP

#include "gfbinarysearchtreenode.hpp"


template< class C >
GFBinarySearchTreeNode< C >::GFBinarySearchTreeNode() : left( 0 ), right( 0 ), data( 0 ) {
}


template< class C >
void GFBinarySearchTreeNode< C >::setData( C ldata ) {
    data = ldata;
}


template< class C >
C GFBinarySearchTreeNode< C >::getData() {
    return data;
}


template< class C >
void GFBinarySearchTreeNode< C >::setLeft( GFBinarySearchTreeNode< C > * node ) {
    left = node;
}


template< class C >
GFBinarySearchTreeNode< C > * GFBinarySearchTreeNode< C >::getLeft() {
    return left;
}


template< class C >
void GFBinarySearchTreeNode< C >::setRight( GFBinarySearchTreeNode< C > * node ) {
    right = node;
}


template< class C >
GFBinarySearchTreeNode< C > * GFBinarySearchTreeNode< C >::getRight() {
    return right;
}



template< class C >
unsigned short GFBinarySearchTreeNode< C >::childrenNumber() {
    unsigned short num = 0;

    if( getLeft() ) num++;
    if( getRight() ) num++;

    return num;
}


template< class C >
GFBinarySearchTreeNode< C > * GFBinarySearchTreeNode< C >::getTheChild() {
    if( childrenNumber() != 1 ) return 0;

    return getLeft() ? getLeft() : getRight();
}


#endif
