#ifndef GFBINARYSEARCHTREENODE_HPP
#define GFBINARYSEARCHTREENODE_HPP


class GFBinarySearchTreeNode
{
    public:
        GFBinarySearchTreeNode();
        void setData(int *);
        int *getData();
        void setLeft(GFBinarySearchTreeNode *);
        GFBinarySearchTreeNode *getLeft();
        void setRight(GFBinarySearchTreeNode *);
        GFBinarySearchTreeNode *getRight();

    private:
        GFBinarySearchTreeNode *left;
        GFBinarySearchTreeNode *right;

        int *data;
};


#endif // GFBINARYSEARCHTREENODE_HPP
