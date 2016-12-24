
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


/// operator &, |, ^ ( std::bitset )
//
//  Performs binary AND, OR, and NOT between two bitsets, left-hand side (lhs) and right-hand side (rhs)

#include <iostream>
#include <bitset>
#include <limits>

int main() {

    std::bitset< 4 > bit_1( "0110" );
    std::bitset< 4 > bit_2( "0011" );

    std::cout << "bit_1 & bit_2 " << ( bit_1 & bit_2 ) << '\n';
    std::cout << "bit_1 | bit_2 " << ( bit_1 | bit_2 ) << '\n';
    std::cout << "bit_1 ^ bit_2 " << ( bit_1 ^ bit_2 ) << '\n';
}


/* output for me:
bit_1 & bit_2 0010
bit_1 | bit_2 0111
bit_1 ^ bit_2 0101
*/


