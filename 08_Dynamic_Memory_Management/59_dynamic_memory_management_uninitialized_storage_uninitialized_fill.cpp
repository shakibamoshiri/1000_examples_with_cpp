/*
        Dynamic Memory Management
        *************************

Uninitialized Storage: (defined in header <memory>)
Several utilities are provided to create and access raw storage
    > uninitialized_copy            copies a rage of object to an uninitialized area of memory
    > uninitialized_copy_n          copies a number of objects to an uninitialized area of memory
    > uninitialized_fill            copies an object to an uninitialized area of memory
    > uninitialized_fill_n          copies an object to an uninitialized area of memory
    > raw_storage_iterator          an iterator that allows standard algorithms to store results in uninitialized memory
    > get_temporary_buffer          obtains uninitialized storage
    > return_temporary_buffer       frees uninitialized storage

*/
/// std::uninitialized_fill
// Copies the given value to an uninitialized memory area,
// defined by the range [first, last) as if by:
/*
    for (; first != last; ++first)
        ::new (static_cast<void*>(std::addressof(*first))
            typename iterator_traits<ForwardIterator>::value_type(x);
*/
// if an exception is thrown during the initialization, the function had no effect


#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

int main(){

    std::string* sptr;
    std::size_t size;
    std::tie(sptr, size) = std::get_temporary_buffer<std::string>(4);

    std::uninitialized_fill(sptr, sptr+size, "hello");

    for (std::string* i = sptr; i != (sptr + size); ++i){
        std::cout << *i << '\n';
        i -> ~basic_string<char>();
    }

    std::return_temporary_buffer(sptr);

    // the output:
    // hello
    // hello
    // hello
    // hello
}
