/**
std::basic_ios
**/

#include <iostream>
#include <fstream>


/// std::basic_ios::rdbufs
/**

std::basic_streambuf<CharT, Traits>* rdbuf() const; (1)
std::basic_streambuf<CharT, Traits>* rdbuf( std::basic_streambuf<CharT, Traits>* sb ); (2)
Manages the associated stream buffer.
    1) Returns the associated stream buffer. If there is no associated stream buffer, returns NULL.
    2) Sets the associated stream buffer to sb. The error state is cleared by calling clear(). Returns the associated stream buffer before the operation.
        If there is no associated stream buffer, returns NULL.
**/

int main() {
    {
        /// mine : did not know

    }
    {
        /// the site sample
    std::ostringstream local;
    auto cout_buff = std::cout.rdbuf(); // save pointer to std::cout buffer

    std::cout.rdbuf(local.rdbuf()); // substitute internal std::cout buffer with
        // buffer of 'local' object

    // now std::cout work with 'local' buffer
    // you don't see this message
    std::cout << "some message";

    // go back to old buffer
    std::cout.rdbuf(cout_buff);

    // you will see this message
    std::cout << "back to default buffer\n";

    // print 'local' content
    std::cout << "local content: " << local.str() << "\n";

    }

}












