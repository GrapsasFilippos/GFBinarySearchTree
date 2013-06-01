#ifndef GFBINARYSEARCHTREEDATACONTAINER_HPP
#define GFBINARYSEARCHTREEDATACONTAINER_HPP


template< class C >
class GFBinarySearchTreeDataContainer {
    public:
        virtual ~GFBinarySearchTreeDataContainer() {}
        virtual int compare( GFBinarySearchTreeDataContainer< C > * ) = 0;
        virtual void setKey( C ) = 0;
        virtual C getKey() = 0;
};


#endif // GFBINARYSEARCHTREEDATACONTAINER_HPP
