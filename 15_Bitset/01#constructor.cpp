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


/// std::bitset::bitset
//  constructs a new bitset from one of several optional data sources

#include <iostream>
#include <bitset>
#include <climits>
#include <string>


int main() {

    // empty constructor
    std::bitset< 8 > b1;
    std::cout << "b1:\t" << b1 << std::endl;

    // unsigned long long constructor
    std::bitset< 8 > b2( 42 );
    std::bitset< 70 > bl( ULLONG_MAX );
    std::bitset< 8 > bs( 0xfff0 );
    // and print:
    std::cout << "b2:\t" << b2 << '\n'
              << "bl:\t" << bl << '\n'
              << "bs:\t" << bs << '\n';

    // string constructor
    std::string bit_string = "110010";
    std::bitset< 8 > b3( bit_string );
    std::bitset< 8 > b4( bit_string, 2 );
    std::bitset< 8 > b5( bit_string, 2, 3 );
    // and print:
    std::cout << "b3:\t" << b3 << '\n'
              << "b4:\t" << b4 << '\n'
              << "b5:\t" << b5 << '\n';

    // string constructor using custom zero/one digit
    std::string alpha_bit_string = "aBaaBBaB";
    std::bitset< 8 > b6( alpha_bit_string, 0, alpha_bit_string.size(), 'a', 'B' );
    // and print:
    std::cout << "b6:\t" << b6 << '\n';

    // char* constructor using custom digit
    std::bitset< 8 > b7( "XXXXYYYY", 8, 'X', 'Y' );
    // and print:
    std::cout << "b7:\t" << b7 << '\n';



}


/* output for me:

b1:     00000000
b2:     00101010
bl:     0000001111111111111111111111111111111111111111111111111111111111111111
bs:     11110000
b3:     00110010
b4:     00000010
b5:     00000001
b6:     01001101
b7:     00001111


*/






