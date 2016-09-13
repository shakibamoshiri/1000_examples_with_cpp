/// Sequence containers : Array

/// 12_std::array::max_size
/// definition in header < array >

/**
constexpr size_type max_size();
constexpr size_type size() max_const ;

Returns the maximum number of elements the container is able
to hold due to system or library implementation limitation,
i.e. std::distance ( begin(), end() ) for the largest container.

note: because each std::array<T, N> is a fixed-size container
      , the value returned by max_size equals n ( which is also
      the value returned by size )

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
        std::array<const char*, 3> chs;
        std::cout<<chs.max_size()<<std::endl; /// output : 3 because of std::array<T, N> is a fixed size
    }

}
