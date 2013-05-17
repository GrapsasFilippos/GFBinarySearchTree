#include "gfbinarysearchtree.hpp"


GFBinarySearchTree::GFBinarySearchTree() : head(0) {
}


bool GFBinarySearchTree::add(int * ldata) {
    GFBinarySearchTreeNode *node = 0;
    GFBinarySearchTreeNode *newNode = new GFBinarySearchTreeNode();

    newNode->setData(ldata);

    if(!head) {
        head = newNode;
        return 1;
    }

    node = head;

    while( 1 ) {
        if( *newNode->getData() > *node->getData() ) {
            if( node->getLeft() ) {
                node = node->getLeft();
                continue;
            }
            else {
                node->setLeft( newNode );
                return 1;
            }
        }
        else if( *newNode->getData() < *node->getData() ) {
            if( node->getRight() ) {
                node = node->getRight();
                continue;
            }
            else {
                node->setRight( newNode );
                return 1;
            }
        }
        else {
            delete(newNode);
            return 0;
        }
    }
}


int *GFBinarySearchTree::search(int &ldata) {
    GFBinarySearchTreeNode *node = head;

    while( node ) {
        if( ldata  == *node->getData()) {
            return node->getData();
        }
        else if( ldata > *node->getData() ) {
            node = node->getLeft();
            continue;
        }
        else if( ldata < *node->getData() ) {
            node = node->getRight();
            continue;
        }
    }

    return 0;
}


void GFBinarySearchTree::printTree(bool addresses) {
    printTree(head, 0, addresses);
}


void GFBinarySearchTree::printTree(GFBinarySearchTreeNode *node, int tabs, bool addresses) {
    int i;

    for( i = 0; i < tabs; i++ )
        cout << "| ";

    if( !node ) {
        cout << "+ .\n";
        return;
    }

    cout << "+ " << *node->getData();
    if( addresses )
        cout << " @" << node->getData();
    cout << endl;

    printTree( node->getLeft(), tabs + 1, addresses );
    printTree( node->getRight(), tabs + 1, addresses );
}
