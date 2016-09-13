/// Sequence containers : Array

/// 18_std::tuple_size( std::array)
/// definition in header < array >

/**
template < Class T, size_t N>
    public integral_constant<size_t, N>
    {};

Provides access to the number of elements in an std::array
as a compile-time constant expression.

Return Value:

**/

#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <iterator>

//#include <unistd.h>
template<class T> void test ( T t ){
    int i[std::tuple_size<T>::value]; /// can be used at compile time
    std::cout<<(t.end() - t.begin());
    std::cout<<std::tuple_size<T>::value<<std::endl;
    std::cout<<*t.begin()<<std::endl;

}
int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::array<float, 3> f {23.34, 34.34, 55.66};
        test(f);

    }

}
