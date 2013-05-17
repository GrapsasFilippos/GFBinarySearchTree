#include <iostream>

#include "gfbinarysearchtree.hpp"

using namespace std;


int main()
{
    GFBinarySearchTree bst;

    bst.add( new int(1) );
    bst.add( new int(5) );
    bst.add( new int(7) );
    bst.add( new int(9) );
    bst.add( new int(3) );
    bst.add( new int(8) );
    bst.add( new int(4) );
    bst.add( new int(6) );
    bst.add( new int(2) );

    bst.printTree();

    cout << "\nSearch result: " << bst.search( *new int(6) ) << endl;

    cout << "\nExiting..." << endl;

    return 0;
}

