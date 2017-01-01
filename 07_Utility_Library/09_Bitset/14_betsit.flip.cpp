
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


/// std::bitset::flip
//
//  Flips bits, i.e. changes true value to false and false value to true
//  Equivalent to logical NOT operation on part of all of bits.
//  1. flips all bits ( equivalent to operator ~)
//  2. flips the bit at position 'pos'


#include <iostream>
#include <bitset>


int main() {

    std::bitset< 4 > bit;

    std::cout << bit << '\n';
    std::cout << bit.flip( 0 ) << '\n'; // changes position 0 == 0001
    std::cout << bit.flip( 2 ) << '\n'; // changes position 2 == 0101
    std::cout << bit.flip() << '\n';    // changes all bits   == 1010
}


/* output for me:

0000
0001
0101
1010

*/






