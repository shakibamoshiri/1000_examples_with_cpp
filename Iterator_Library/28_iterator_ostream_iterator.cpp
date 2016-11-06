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
/// ostream_iterator
// std::ostream_iterator is single-pass OutputIterator that writes successive
// object of type T into the std::basic_ostream object for which it was constructed
// using operator <<. Optional delimiter string is written to the output stream
// after every write operation. The write operation is preformed when the iterator
// (whether dereferenced or not) is assigned to. Incrementing the std::ostream_iterator
// is no-op.
//
// A typical implementation of std::istream_iterator holds two data members:
// a pointer to the associated std::basic_istream object and the most recently
// read value of type T.


#include <iostream>
#include <iterator>
#include <sstream>

#include <algorithm>
// #include <functional> // std::greater<int>()
// #include <vector>
// #include <list>
// #include <set>
// #include <set>
// #include <string>
 #include <array>
// #include <list>
// #include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>

// #include <unistd.h>
// #include <climits>
#include "../helpful/print_container" // operator<< overloaded



int main(){

    std::istringstream i("1 2 3 4 5 6 7");

    int arr[7]{0};

    std::copy(std::istream_iterator<int>(i), // read all number
              std::istream_iterator<int>(),
              std::ostream_iterator<int>(std::operator<<(std::cout,"the output:\t")," "));             // store numbers into object of osteram_iterator
              // I here use std::operator<<  for output because  of ambiguous overloading
              // that I have written for print array
              // in ../helpful/print_container



return 0;}






