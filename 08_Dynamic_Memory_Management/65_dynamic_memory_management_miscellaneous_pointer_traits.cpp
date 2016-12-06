/*
        Dynamic Memory Management
        *************************


Miscellaneous (in header <memory>)
    > pointer_traits                provides information about pointer-like types
    > addressof                     obtains actual address of an object, even if that & operator is overloaded
    > align                         aligns a pointer in a buffer

*/
/// std::pointer_traits
// The pointer class template provides the standardized way to access
// certain properties of pointer-like types. The standard template
// std::allocator_traits relies on pointer_traits to determine the
// default for various typedefs required by 'Allocator'.
//
/// NOTE:
// The rebind member template alias makes it possible, given a pointer-like type
// that points to T, to obtain the-same pointer-like type that points to U for example:
/**
    typedef std::pointer_traits<std::shared_ptr<int>>::rebind<double> another_pointer;
    static_assert(std::is_same<another_pointer, std::shared_ptr<double>>::value, "");
**/


#include <iostream>
#include <memory>

template<class Ptr>
struct BlockList {
    // predefine a memory block
    struct block;

    // define a pointer to a  memory block form the kind of pointer Ptr s
    // if Ptr is any kind of T*, block_ptr_t is block*
    // if Ptr is smart_ptr<T>,   block_ptr_t is smart_ptr<block>
    typedef typename std::pointer_traits<Ptr>::template rebind<block> block_ptr_t;

    struct block {
        std::size_t size;
        block_ptr_t next_block;
    };

    block_ptr_t free_blocks;
};

int main(){
    BlockList<int*> bl1;
    // the type of bl1.free_blocks is block*

    BlockList<std::shared_ptr<char>> bl2;
    // the type of bl2.free_blocks is std::shared_ptr<block>

    std::cout << bl2.free_blocks.use_count() << std::endl;

    // the output: 0
}




