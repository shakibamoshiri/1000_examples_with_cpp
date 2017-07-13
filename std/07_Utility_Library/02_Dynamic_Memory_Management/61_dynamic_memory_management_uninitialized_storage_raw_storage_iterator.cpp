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
/// std::raw_storage_iterator
// The output iterator std::raw_storage_iterator makes it possible for
// standard algorithm to store results in uninitialized memory. Whenever
// the algorithm writes an object of type T to the dereferenced iterator,
// the object is parameterOutput is any type that meets the requirement of
// OutputIterator and has operator * defined to return an object, for which
// operator & returns an object of type T*. Usually, the type T* used as OutputIt.

#include <iostream>
#include <memory>

#include <string>

#include <algorithm>

int main(){
    const std::string str[] = {"how", "are", "you", "today", "?"};
    std::string* ptr_str = std::get_temporary_buffer<std::string>(5).first;

    std::copy(std::begin(str), std::end(str),
        std::raw_storage_iterator<std::string*,std::string>(ptr_str));

    for (std::string* i = ptr_str; i != (ptr_str + 5); ++i){
        std::cout << *i << '\n';
        i -> ~basic_string<char>();
    }

    std::return_temporary_buffer(ptr_str);

    // The output:
    // how
    // are
    // you
    // today
    // ?
}





