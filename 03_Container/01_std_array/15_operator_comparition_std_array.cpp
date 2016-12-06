/// Sequence containers : Array

/// 15 operator ==, !=, <, <=, >, >= (std::array)
/// definition in header < array >

/**
template< class T, std::size_t N >

bool operator==( const array<T,N>& lhs,
                 const array<T,N>& rhs );(1)
template< class T, std::size_t N >

bool operator!=( const array<T,N>& lhs,
                 const array<T,N>& rhs );(2)
template< class T, std::size_t N >

bool operator<( const array<T,N>& lhs,
                const array<T,N>& rhs );(3)
template< class T, std::size_t N >
bool operator<=( const array<T,N>& lhs,
                 const array<T,N>& rhs );(4)
template< class T, std::size_t N >
bool operator>( const array<T,N>& lhs,
                const array<T,N>& rhs );(5)
template< class T, std::size_t N >
bool operator>=( const array<T,N>& lhs,
                 const array<T,N>& rhs ); (6)
Return Value:

**/

#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <iterator>

//#include <unistd.h>

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        /// filling with const char*
        std::array<const char*, 3> name;
        std::get<0>(name) = "Some cunt";
        std::get<1>(name) = "Nasim cunt";
        std::get<2>(name) = "Hajar cunt";

        std::array<const char*,3> lname {"A", "B","C"};
        bool ba = lname == name ;
        std::cout<<std::boolalpha<<ba<<std::endl;
        std::array<const char*,3> ch {"A","B","C"};
        ba = lname == ch;
        std::cout<<std::boolalpha<<ba<<std::endl;

    }

}
