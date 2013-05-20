#ifndef GFBINARYSEARCHTREEDATACONTAINER_HPP
#define GFBINARYSEARCHTREEDATACONTAINER_HPP


template< class C >
class GFBinarySearchTreeDataContainer {
    public:
        virtual ~GFBinarySearchTreeDataContainer() {}
        virtual int compare( GFBinarySearchTreeDataContainer< C > * ) = 0;
        virtual void setData( C ) = 0;
        virtual C getData() = 0;
};


#endif // GFBINARYSEARCHTREEDATACONTAINER_HPP
