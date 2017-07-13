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
/// istreabuf_iterator
// std::istreambuf_iterator is single-pass input iterator that reads successive
// characters from the std::basic_istream object for which it was constructed.
// The actual read operation is performed when the iterator is incremented, not
// when it is dereferenced. The first character may be read when the iterator is
// constructed or when the first dereferencing is done. Otherwise, dereferencing
// only returns a copy of the most recently read character.
//
// std::istreambuf_iterator has a trivia copy constructor, a conetexpr
// default constructor, and a trivia destructor.


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

    // demonstration of the single-pass nature
    std::istringstream istr("abc");

    std::istreambuf_iterator<char> c0(istr), c1(istr);

    std::cout<<"c0 and c1 are:\t"<<*c0<<' '<<*c1<<'\n';

    // only increments c0
    c0++;  // now it points to 'b'
    std::cout<<"c0 after incrementing:\t"<<*c0<<'\n';
    std::cout<<"c1 after incrementing:\t"<<*c1<<'\n';

    // now only increments c1 not c0
    c1++;   // now this make the apparent value of *c1 to jump form 'a' to 'c'
    std::cout<<"c0 after increments c1:\t"<<*c0<<'\n';
    std::cout<<"c1 after increments c1:\t"<<*c1<<'\n';




return 0;}






