/*
            std::bitset
            ***********


template< std::size_t N > class bitset;

The class template bitset represents a fixed-size sequence of N bits.
Bitsets can be manipulated by standard logic operators and converted
to and from strings and iterators.
Bitsets meets the requirement of CopyConstructible and CopyAssignment


    member type:
        reference

    member function:
        constructor         constructs the bitset
        operator ==, !=     compares the contents

    element access:
        operator []         access specifier bit
        test                access specifier bit
        all                 check if all,
        any                          any, or
        none                         none bits are set to true
        count               returns the number of bits set to true

    capacity:
        size                returns the size number of bits that the bitset can hold

    modifier:
        operator &, |, ^, ~         performs binary AND, OR, XOR, NOT
        operator >>, <<, <<=, >>=   performs binary shift left and shift right
        set                 sets bits to true or given value
        reset               sets bits to false
        flip                toggles the value of bits

    conversation:
     to_string              returns a string representation of the data
     to_ulong               returns a unsigned long integer representation of the data
     to_ullong              returns a unsigned long long integer representation of the data

     non-member function:
        operator &, |, ^    performs binary logic operations on bitsets
        operator >> , <<    performs stream input and output of bitsets

    helper-class
        std::hash< std::bitset >    hash support for std::bitset

    ---------------------------------------------
    Note:
    If the size of the bitset is not known at the compile time,
    std::vector<bool> and boost<dynamic_bistset> may be used.
*/


/// std::bitset all, any, none
//  Checks if all, any, or none of the bits set to true.

#include <iostream>
#include <bitset>

int main() {

    typedef std::bitset< 4 > bit4;

    bit4 b1( "0000" );
    bit4 b2( "0101" );
    bit4 b3( "1111" );

    std::puts( "bitset\tall\tany\tnone" );
    std::cout << b1 << '\t'
              << b1.all() << '\t'
              << b1.any() << '\t'
              << b1.none() << std::endl

              << b2 << '\t'
              << b2.all() << '\t'
              << b2.any() << '\t'
              << b2.none() << std::endl

              << b3 << '\t'
              << b3.all() << '\t'
              << b3.any() << '\t'
              << b3.none() << std::endl;

}


/* output for me:

bitset  all     any     none
0000    0       0       1
0101    0       1       0
1111    1       1       0

*/


