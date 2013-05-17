#include "gfbinarysearchtree.hpp"


GFBinarySearchTree::GFBinarySearchTree() : head(0) {
}


void GFBinarySearchTree::add(int * ldata) {
    GFBinarySearchTreeNode *node = 0;
    GFBinarySearchTreeNode *newNode = new GFBinarySearchTreeNode();

    newNode->setData(ldata);

    if(!head) {
        head = newNode;
        return;
    }

    node = head;

    while(1) {
        if( *newNode->getData() > *node->getData() ) {
            if( node->getLeft() ) {
                node = node->getLeft();
                continue;
            }
            else {
                node->setLeft( newNode );
                break;
            }
        }
        else if( *newNode->getData() < *node->getData() ) {
            if( node->getRight() ) {
                node = node->getRight();
                continue;
            }
            else {
                node->setRight( newNode );
                break;
            }
        }
        else {
            // THROW
            return;
        }
    }
}


void GFBinarySearchTree::printTree() {
    printTree(head, 0);
}


void GFBinarySearchTree::printTree(GFBinarySearchTreeNode *node, int tabs) {
    int i;

    for( i = 0; i < tabs; i++ )
        cout << "| ";

    if( !node ) {
        cout << "+ .\n";
        return;
    }

    cout << "+ " << *node->getData() << endl;

    printTree( node->getLeft(), tabs + 1 );
    printTree( node->getRight(), tabs + 1 );
}
