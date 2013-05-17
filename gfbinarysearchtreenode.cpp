#include "gfbinarysearchtreenode.hpp"


GFBinarySearchTreeNode::GFBinarySearchTreeNode() : left(0), right(0), data(0) {
}


void GFBinarySearchTreeNode::setData(int *ldata) {
    data = ldata;
}


int *GFBinarySearchTreeNode::getData() {
    return data;
}


void GFBinarySearchTreeNode::setLeft(GFBinarySearchTreeNode *node) {
    left = node;
}


GFBinarySearchTreeNode *GFBinarySearchTreeNode::getLeft() {
    return left;
}


void GFBinarySearchTreeNode::setRight(GFBinarySearchTreeNode *node) {
    right = node;
}


GFBinarySearchTreeNode *GFBinarySearchTreeNode::getRight() {
    return right;
}
