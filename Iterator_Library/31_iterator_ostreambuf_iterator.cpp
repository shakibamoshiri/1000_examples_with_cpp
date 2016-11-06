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
/// ostrembuf_iterator
// std::ostreambuf_iterator is a single-pass OutputIterator that writes successive
// characters into the std::basic_ostreambuf object for which it was constructed.
// The actual write operation is performed when the iterator (whether dereferenced or not)
// is assigned to.
// Incrementing the std::ostremabuf_iterator is a no-op.
//
// In typical implementation, the only data members of std::ostreambuf_iterator are
// a pointer to associated std::basic_streambuf and a boolean flag indicating if the
// the end of file condition has been reached.

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

    std::string str("This is an example how to use: std::ostreambuf_iterator\n");

    std::copy(str.begin(),str.end(),
              std::ostreambuf_iterator<char>(std::cout)); // it only take one argument ( output stream)
                                                          // not like ostream_iterator std::cout and a space

return 0;}






