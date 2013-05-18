#include <iostream>

#include "gfbinarysearchtree.hpp"

using namespace std;


int main()
{
    GFBinarySearchTree bst;
    int *tmpData = 0;
    int menu = -1;


    bst.add( new int(4) );
    bst.add( new int(6) );
    bst.add( new int(7) );
    bst.add( new int(5) );
    bst.add( new int(2) );
    bst.add( new int(3) );
    bst.add( new int(1) );
    bst.add( new int(8) );
    bst.add( new int(9) );
    bst.printTree();


    while( menu ) {
        cout << "1. Add\n2. Search\n3. Delete\n4. Print\n0. Exit\n> Option: ";
        cin >> menu;

        switch(menu) {
            case 1:
                cout << "> Give an integer: ";
                cin >> menu;
                tmpData = new int( menu );
                if( bst.add( tmpData ) ) cout << "Added.\n";
                else {
                    delete( tmpData );
                    cout << "Already exist.\n";
                }
                menu = -1;
                break;
            case 2:
                cout << "> Give an integer: ";
                cin >> menu;
                cout << "Item at: " << bst.search( *new int(menu) ) << endl;
                menu = -1;
                break;
            case 3:
                cout << "> Give an integer: ";
                cin >> menu;
                tmpData = bst.remove( menu );
                if( tmpData ) {
                    delete( tmpData );
                    cout << "Removed.\n";
                }
                else cout << "Don't exist.\n";
                menu = -1;
                break;
            case 4:
                bst.printTree(1);
                break;
        }
    }

    cout << "Exiting..." << endl;

    return 0;
}

