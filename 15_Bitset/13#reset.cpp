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


/// std::bitset::reset
//  Sets bits to false
//  1. sets all bits to false
//  2. sets the bit a position 'pos' to false


#include <iostream>
#include <bitset>


int main() {

    std::bitset< 8 > number_42( 42 );

    std::cout << "bitset of number_42:\t" << number_42 << '\n';

    number_42.reset( 1 );   // bit at pos 1 become false
    std::cout << "after reset( 1 ):\t" << number_42 << '\n';

    number_42.reset();  // all bits set to false
    std::cout << "after reset():\t" << number_42 << '\n';

}


/* output for me:

bitset of number_42:    00101010
after reset( 1 ):       00101000
after reset():  00000000


*/


