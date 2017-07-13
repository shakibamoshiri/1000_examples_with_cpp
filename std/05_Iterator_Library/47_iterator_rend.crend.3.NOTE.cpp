/*
            The Iterator Library
            ********************
For more detail you can see:
    stl_iterator_base_types.h
    stl_iterator.h
    type_traits
-------------------------------------------------
Range access
    Those non-member function provides a generic interface for containers, plain arrays, and std::initializer_list.

    begin:                          returns an iterator to the beginning of a container or array
    cbegin:                         same as begin but constant
    end:                            returns an iterator to the end of a container or array
    cend:                           same as end but constant
    rbegin:                         returns a reverse iterator to a container of array
    crbegin:                        same as rbegin but constant
    rend:                           returns a reverse end iterator to a container of array
    crend:                          same as rend but constant

*/
/// rend and crend
//  (rend)                                               (rbegin)
//  -------------------------------------------------------------
//  |   | * | * | * | * | * | * | * | * | * | * | * | * | * | * | <-
//  -------------------------------------------------------------
//
//      (begin)                                               (end)
//      -------------------------------------------------------------
//  ->  | * | * | * | * | * | * | * | * | * | * | * | * | * | * |   |
//      -------------------------------------------------------------
//
// Returns an iterator to the reverse-end of the given container 'c' or array of array



#include <iostream>
#include <iterator>
// #include <sstream>

#include <algorithm>
// #include <functional> // std::greater<int>()
#include <vector>
// #include <list>
// #include <set>
// #include <set>
// #include <string>
  #include <array>
// #include <list>
// #include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>

// #include <unistd.h>
// #include <climits>
// #include "../helpful/print_container" // operator<< overloaded


int main(){
    int arr[]={11,22,33,44,55,66,77};

    int* barr=std::begin(arr);
    int* earr=std::end(arr);

    // now barr points to the beginning of the arr
    // and earr points the end of arr
    // we can swap these points to make these reverse

    int* temp=barr; // store beginning to the temp
    barr=earr-1;    // store end-1 to the barr
    earr=temp-1;    // store barr that have put in the temp, to the earr
    // Now, barr points to the end
    // and  earr points to the beginning

    // earr points to the one past-the-end so we need to the address of earr-1
    // and also needed that earr( reverse-begin ) points the one before-the-begin so we do temp-1
    //
    //       barr                               earr
    // ---------------------------------------------
    // |    | 11 | 22 | 33 | 44 | 55 | 66 | 77 |   |
    // ---------------------------------------------
    // ^^^^^^                              ^^^^
    // begin-1                             end-1
    // ^^^^^^^                             ^^^^
    // r-begin                             r-end


    std::cout<<*(earr+1)<<std::endl; // 11
    std::cout<<*(barr)<<std::endl; // 77


return 0;}






