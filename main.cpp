#include <iostream>
#include <string>

#include "gfbinarysearchtree.hpp"
#include "gfbinarysearchtreedatacontainer.hpp"

using namespace std;


class IntContainer : public GFBinarySearchTreeDataContainer< int * > {
    public:
        IntContainer() : key( 0 ) {}
        IntContainer( int * lkey ) : key( lkey ) {}
        ~IntContainer() {}

        int compare( GFBinarySearchTreeDataContainer< int * > * ldata) {
            if( *getKey() > *ldata->getKey() ) return( 1 );
            if( *getKey() < *ldata->getKey() ) return( -1 );
            else return( 0 );
        }
        void setKey( int * lkey ) {
            key = lkey;
        }
        int * getKey() {
            return key;
        }

    private:
        int * key;
};



class StringContainer : public GFBinarySearchTreeDataContainer< string * > {
    public:
        StringContainer() : key( 0 ) {}
        StringContainer( string * lkey ) : key( lkey ) {}
        ~StringContainer() {}

        int compare( GFBinarySearchTreeDataContainer< string * > * ldata) {
            return getKey()->compare( *ldata->getKey() );
        }
        void setKey( string * lkey ) {
            key = lkey;
        }
        string * getKey() {
            return key;
        }

    private:
        string * key;
};



void ints() {
    GFBinarySearchTree< GFBinarySearchTreeDataContainer< int * > * > bst;
    IntContainer * tmpIC = 0;
    IntContainer * tmpIC2 = 0;
    int menu = -1;

    tmpIC = new IntContainer( new int( 4 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );
    tmpIC = new IntContainer( new int( 6 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );
    tmpIC = new IntContainer( new int( 7 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );
    tmpIC = new IntContainer( new int( 5 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );
    tmpIC = new IntContainer( new int( 2 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );
    tmpIC = new IntContainer( new int( 3 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );
    tmpIC = new IntContainer( new int( 1 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );
    tmpIC = new IntContainer( new int( 8 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );
    tmpIC = new IntContainer( new int( 9 ) );
    if( !bst.add( tmpIC ) ) delete( tmpIC );

    while( menu ) {
        cout << "1. Add\n2. Search\n3. Delete\n4. Print\n0. Exit\n> Option: ";
        cin >> menu;

        switch(menu) {
            case 1:
                cout << "> Give an integer: ";
                cin >> menu;
                tmpIC = new IntContainer( new int( menu) );
                if( bst.add( tmpIC ) ) cout << "Added.\n";
                else {
                    delete( tmpIC );
                    cout << "Already exist.\n";
                }
                menu = -1;
                break;
            case 2:
                cout << "> Give an integer: ";
                cin >> menu;
                tmpIC = new IntContainer( new int( menu) );
                cout << "Item @ " << bst.search( tmpIC ) << endl;
                delete( tmpIC );
                menu = -1;
                break;
            case 3:
                cout << "> Give an integer: ";
                cin >> menu;
                tmpIC = new IntContainer( new int(menu ) );
                tmpIC2 = ( IntContainer * ) bst.remove( tmpIC );
                if( tmpIC2 ) {
                    delete( tmpIC2 );
                    cout << "Removed.\n";
                }
                else cout << "Don't exist.\n";
                delete( tmpIC );
                menu = -1;
                break;
            case 4:
                bst.printTree(1);
                break;
        }
    }

    cout << "Exiting..." << endl;
}



void strings() {
    GFBinarySearchTree< GFBinarySearchTreeDataContainer< string * > * > bst;
    StringContainer * tmpSC = 0;
    StringContainer * tmpSC2 = 0;
    string tmpstr;
    int menu = -1;

    tmpSC = new StringContainer( new string( "Calliope" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );
    tmpSC = new StringContainer( new string( "Thalia" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );
    tmpSC = new StringContainer( new string( "Myrto" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );
    tmpSC = new StringContainer( new string( "Arsinoe" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );
    tmpSC = new StringContainer( new string( "Panacea" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );
    tmpSC = new StringContainer( new string( "Gorgon" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );
    tmpSC = new StringContainer( new string( "Agathoniki" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );
    tmpSC = new StringContainer( new string( "Dione" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );
    tmpSC = new StringContainer( new string( "Jocasta" ) );
    if( !bst.add( tmpSC ) ) delete( tmpSC );

    while( menu ) {
        cout << "1. Add\n2. Search\n3. Delete\n4. Print\n0. Exit\n> Option: ";
        cin >> menu;

        switch(menu) {
            case 1:
                cout << "> Give a string: ";
                cin >> tmpstr;
                tmpSC = new StringContainer( new string( tmpstr ) );
                if( bst.add( tmpSC ) ) cout << "Added.\n";
                else {
                    delete( tmpSC );
                    cout << "Already exist.\n";
                }
                break;
            case 2:
                cout << "> Give a string: ";
                cin >> tmpstr;
                tmpSC = new StringContainer( new string( tmpstr ) );
                cout << "Item @ " << bst.search( tmpSC ) << endl;
                delete( tmpSC );
                break;
            case 3:
                cout << "> Give a string: ";
                cin >> tmpstr;
                tmpSC = new StringContainer( new string( tmpstr ) );
                tmpSC2 = ( StringContainer * ) bst.remove( tmpSC );
                if( tmpSC2 ) {
                    delete( tmpSC2 );
                    cout << "Removed.\n";
                }
                else cout << "Don't exist.\n";
                delete( tmpSC );
                break;
            case 4:
                bst.printTree(1);
                break;
        }
    }

    cout << "Exiting..." << endl;
}

int main() {
    int menu;
    cout << "1. Integer\n2. String\n3. exit\n> Option: ";
    cin >> menu;

    switch( menu ) {
        case 1:
            ints();
            break;
        case 2:
            strings();
            break;
    }

    return 0;
}

