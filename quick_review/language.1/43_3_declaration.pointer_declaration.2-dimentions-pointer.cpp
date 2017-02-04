/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>
#include <string>


int main(){
    // pointer declaration:


    int array[2] = {10, 20};
    int* iptr2array = array;            // okay, point to the first element
    std::cout << *iptr2array << std::endl;      // 10
    std::cout << *(iptr2array+1) << std::endl;  // 20



    int (*aiptr) [2] = &array;          // okay, pinter to array of int. note that is a two dimensions pointer
    std::cout << aiptr[0][0] << std::endl;  // prints 10
    std::cout << aiptr[0][1] << std::endl;  // prints 20

    std::cout << *(aiptr[0]+0) << std::endl;      // also 10
    std::cout << *(aiptr[0]+1) << std::endl;      // also 20

    std::cout << *(*aiptr) << std::endl;        // also 10  // it is the same as *(*aitpr+0)
    std::cout << *(*aiptr+1) << std::endl;      // also 20

    std::cout << **aiptr << std::endl;          // also 10
    std::cout << ++**aiptr << std::endl;        // print 11 ( 10 + 1 )

    std::cout << **++aiptr << std::endl;        // print 0 wrong syntax. it increments 8 bytes not 4 bytes
    std::cout << **aiptr++ << std::endl;        // print 0 wrong syntax. also same as above

    // here a cannot find a way to iterate to this array by 4 bytes, 4 bytes movement
    // with this aiptr
    // if you find it, tell it to me :)



}
