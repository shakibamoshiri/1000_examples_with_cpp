/*
            The Iterator Library
            ********************
For more detail you can see:
    stl_iterator_base_types.h
    stl_iterator.h
    type_traits
-------------------------------------------------
Stream iterator
    istream_iterator:               input iterator that reads from std::basic_isteram
    ostream_iterator:               output iterator that writes to std::basic_ostream
    istreambuf_iterator:            input iterator that reads form std::basic_streambuf
    ostreambuf_iterator:            output iterator that writes to std::basic_streambut

*/
/// istream_iterator
// std::istream_iterator is a single-pass iterator that reads successive
// objects of type T from the std::basic_istream object for which it was
// constructed, by calling the appropriate operator >>. The actual read
// operation is performed when the iterator is incremented, not when it
// is dereferenced. The first object may be read when the iterator is
// constructed or when the first dereferencing is done. Otherwise, dereferencing
// only returns a copy of the most recently read object.
//
// A typical implementation of std::istream_iterator holds two data members:
// a pointer to the associated std::basic_istream object and the most recently
// read value of type T.


#include <iostream>
#include <iterator>
#include <sstream>

#include <algorithm>
// #include <functional> // std::greater<int>()
#include <vector>
// #include <list>
// #include <set>
// #include <set>
// #include <string>
// #include <array>
// #include <list>
// #include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>

// #include <unistd.h>
// #include <climits>


#include "../helpful/print_container" // operator<< overloaded



int main(){
    std::istringstream istr("0.1 0.2 0.3 0.4");

    std::partial_sum(std::istream_iterator<float>(istr),
                     std::istream_iterator<float>(),
                     std::ostream_iterator<float>(std::cout<<"The result:\t"," "));
    // note:
    // when reading character, std::istream_iterator skips whitespace by default
    // (unless disabled with std::noskipws or equivalent), whit std::istreambuf_iterator
    // does not. In addition, std::isterambuf_iterator is more efficient, since it
    // avoid the overhead of constructing and destructing the sentry object once per character.
return 0;}






