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
/// std::uninitialized_copy_n
// Copies count elements from a range beginning at first to an uninitialized
// memory area beginning at d_first as if by
/*
    for (; n > 0; ++d_first, (void)++first; ++n)
        ::new (static_cast<void*>(std::addressof(*d_first))
            typename iterator_traits<ForwardIterator>::value_type(*first);
*/
// if an exception is thrown during the initialization, the function had no effect


#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

int main(){
    std::vector<std::string> vec {"how","are","you","today?"};

    std::string* sptr;
    std::size_t sz;
    std::tie(sptr, sz) = std::get_temporary_buffer<std::string>(vec.size());
    sz = std::min(sz, vec.size());

    std::uninitialized_copy_n(vec.begin(), sz-1, sptr);

    for (std::string* i = sptr; i != (sptr + sz); ++i){ // copy 0 to 2 (not 4th element)
        std::cout << *i << ' ';
        i -> ~basic_string<char>();
    }

    std::return_temporary_buffer(sptr);
}
