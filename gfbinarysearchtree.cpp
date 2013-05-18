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


int *GFBinarySearchTree::search(int &data) {
    GFBinarySearchTreeNode *node = head;

    while( node ) {
        if( data  == *node->getData() ) {
            return node->getData();
        }
        else if( data > *node->getData() ) {
            node = node->getLeft();
            continue;
        }
        else if( data < *node->getData() ) {
            node = node->getRight();
            continue;
        }
    }

    return 0;
}


int *GFBinarySearchTree::remove(int &data) {
    GFBinarySearchTreeNode *father = 0;
    GFBinarySearchTreeNode *node = head;
    int *tmpData = 0;
    int *tmpData2 = 0;

    while( node ) {
        if( data == *node->getData() ) {
            if( node->childrenNumber() == 2 ) {
                tmpData = remove( *getMinimum( node->getLeft() )->getData() );
                tmpData2 = node->getData();
                node->setData( tmpData );
                return( tmpData2 );
            }
            else if( node->childrenNumber() == 1 ) {
                if( father ) {
                    if( father->getLeft() == node ) father->setLeft( node->getTheChild() );
                    else father->setRight( node->getTheChild() );
                }
                else {
                    head = node->getTheChild();
                }
                tmpData = node->getData();
                delete( node );
                return( tmpData );
            }
            else {
                if( father ) {
                    if( father->getLeft() == node ) father->setLeft( 0 );
                    else father->setRight( 0 );
                }
                else {
                    head = 0;
                }
                tmpData = node->getData();
                delete( node );
                return( tmpData );
            }
        }
        else if( data > *node->getData() ) {
            father = node;
            node = node->getLeft();
            continue;
        }
        else if( data < *node->getData() ) {
            father = node;
            node = node->getRight();
            continue;
        }
    }

    return( 0 );
}


void GFBinarySearchTree::printTree(bool addresses) {
    printTree(head, 0, addresses);
    if( getMaximum() ) cout << "Maximum: " << *getMaximum()->getData() << " \n";
    if( getMaximum() ) cout << "Minimum: " << *getMinimum()->getData() << endl;
}



GFBinarySearchTreeNode *GFBinarySearchTree::getMaximum(GFBinarySearchTreeNode *node) {
    if( !node ) node = head;
    if( !node ) return( 0 );

    while( node->getLeft() )
        node = node->getLeft();

    return( node );
}


GFBinarySearchTreeNode *GFBinarySearchTree::getMinimum(GFBinarySearchTreeNode *node) {
    if( !node ) node = head;
    if( !node ) return( 0 );

    while( node->getRight() )
        node = node->getRight();

    return( node );
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
        cout << "   @ " << node->getData() << " Children: " << node->childrenNumber();
    cout << endl;

    printTree( node->getLeft(), tabs + 1, addresses );
    printTree( node->getRight(), tabs + 1, addresses );
}
