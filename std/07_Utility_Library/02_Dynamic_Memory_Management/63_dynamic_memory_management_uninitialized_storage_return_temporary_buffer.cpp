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
/// std::return_temporary_buffer
// Deallocates storage previously allocated with std::get_temporary_buffer.

#include <iostream>
#include <memory>

#include <string>
#include <iterator>
#include <algorithm>

int main(){
    const std::string str[] = {"how", "are", "you", "today", "?"};
    std::pair<std::string*, int> pir = std::get_temporary_buffer<std::string>(5);
    // requires the pir.first is passed to return_temporary_buffer
    // beware of early exit points and exception

    std::copy(str, str+pir.second, std::raw_storage_iterator<std::string*, std::string>(pir.first));
    // requires that each string in pir is individually destroyed
    // beware of early exit points and exception

    std::copy( str,
              (str + pir.second),
              std::ostream_iterator<std::string>(std::cout,"\n"));

    std::for_each(pir.first, (pir.first+pir.second), [](std::string& s){ s . ~basic_string<char>(); });

    std::return_temporary_buffer(pir.first);

    // the output:
    // how
    // are
    // you
    // today
    // ?

}





