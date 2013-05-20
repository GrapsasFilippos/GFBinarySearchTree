#ifndef GFBINARYSEARCHTREE_CPP
#define GFBINARYSEARCHTREE_CPP

#include "gfbinarysearchtree.hpp"


template< class C >
GFBinarySearchTree< C >::GFBinarySearchTree() : head( 0 ) {
}


template< class C >
bool GFBinarySearchTree< C >::add( C container ) {
    GFBinarySearchTreeNode< C > * node = 0;
    GFBinarySearchTreeNode< C > * newNode = new GFBinarySearchTreeNode< C >();
    int compare;

    newNode->setData( container );

    if( !head ) {
        head = newNode;
        return 1;
    }
    node = head;

    while( 1 ) {
        compare = newNode->getData()->compare( node->getData() );

        //if( *newNode->getData() > *node->getData() ) {
        if( compare > 0 ) {
            if( node->getLeft() ) {
                node = node->getLeft();
                continue;
            }
            else {
                node->setLeft( newNode );
                return 1;
            }
        }
        //else if( *newNode->getData() < *node->getData() ) {
        else if( compare < 0 ) {
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


template< class C >
C GFBinarySearchTree< C >::search( C container ) {
    GFBinarySearchTreeNode< C > * node = head;
    int compare;

    while( node ) {
        compare = container->compare( node->getData() );
        //if( container  == *node->getData() ) {
        if( compare == 0 ) {
            return node->getData();
        }
        //else if( container > *node->getData() ) {
        else if( compare > 0 ) {
            node = node->getLeft();
            continue;
        }
        //else if( container < *node->getData() ) {
        else if( compare < 0 ) {
            node = node->getRight();
            continue;
        }
    }

    return 0;
}


template< class C >
C GFBinarySearchTree< C >::remove( C container ) {
    GFBinarySearchTreeNode< C > * father = 0;
    GFBinarySearchTreeNode< C > * node = head;
    C tmpData = 0;
    C tmpData2 = 0;
    int compare;

    while( node ) {
        compare = container->compare( node->getData() );
        //if( container == *node->getData() ) {
        if( compare == 0 ) {
            if( node->childrenNumber() == 2 ) {
                tmpData = remove( getMinimum( node->getLeft() )->getData() );
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
        //else if( container > *node->getData() ) {
        else if( compare > 0 ) {
            father = node;
            node = node->getLeft();
            continue;
        }
        //else if( container < *node->getData() ) {
        else if( compare < 0 ) {
            father = node;
            node = node->getRight();
            continue;
        }
    }

    return( 0 );
}


template< class C >
void GFBinarySearchTree< C >::printTree( bool addresses ) {
    printTree(head, 0, addresses);
    if( getMaximum() ) cout << "Maximum: " << *getMaximum()->getData()->getData() << " \n";
    if( getMaximum() ) cout << "Minimum: " << *getMinimum()->getData()->getData() << endl;
}



template< class C >
GFBinarySearchTreeNode< C > * GFBinarySearchTree< C >::getMaximum( GFBinarySearchTreeNode< C > * node ) {
    if( !node ) node = head;
    if( !node ) return( 0 );

    while( node->getLeft() )
        node = node->getLeft();

    return( node );
}


template< class C >
GFBinarySearchTreeNode< C > * GFBinarySearchTree< C >::getMinimum( GFBinarySearchTreeNode< C > * node ) {
    if( !node ) node = head;
    if( !node ) return( 0 );

    while( node->getRight() )
        node = node->getRight();

    return( node );
}


template< class C >
void GFBinarySearchTree< C >::printTree( GFBinarySearchTreeNode< C > * node, int tabs, bool addresses ) {
    int i;

    for( i = 0; i < tabs; i++ )
        cout << "| ";

    if( !node ) {
        cout << "+ .\n";
        return;
    }

    cout << "+ " << *node->getData()->getData();
    if( addresses )
        cout << "   @ " << node->getData() << " Children: " << node->childrenNumber();
    cout << endl;

    printTree( node->getLeft(), tabs + 1, addresses );
    printTree( node->getRight(), tabs + 1, addresses );
}


#endif
