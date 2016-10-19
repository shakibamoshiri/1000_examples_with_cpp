#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::resize
/*

void resize( size_type count ); (1)
void resize( size_type count, CharT ch ); (2)


Resizes the string to contain count characters.
If the current size is less than count, additional characters are appended.
If the current size is greater than count, the string is reduced to its first count elements.
The first version initializes new characters to CharT(), the second version initializes new characters to ch.


Parameters
count	-	new size of the string
ch	-	character to initialize the new characters with

Return value
(none)

Exceptions
std::length_error if count > max_size(). Any exceptions thrown by corresponding Allocator.
If an exception is thrown for any reason, this function has no effect (strong exception guarantee). (since C++11)

*/


int main() {
    /// void resize( size_type count ); (1)
    std::string s("shakiba");
    cout<<s<<endl;
    s.resize(5);
    cout<<s<<endl;
    s.resize(12);


    /// void resize( size_type count, CharT ch ); (2)
    cout<<endl;
    cout<<s<<endl;
    s.resize(23,'=');
    cout<<s<<endl;
    {
    std::cout << "Basic functionality:\n";
    const unsigned  desired_length(8);
    std::string     long_string( "Where is the end?" );
    std::string     short_string( "Ha" );

    // Shorten
    std::cout << "Before: \"" << long_string << "\"\n";
    long_string.resize( desired_length );
    std::cout << "After: \"" << long_string <<  "\"\n";

    // Lengthen
    std::cout << "Before: \"" << short_string <<  "\"\n";
    short_string.resize( desired_length, 'a' );
    std::cout << "After: \"" << short_string <<  "\"\n";

    std::cout  << "\nErrors:\n";
    {
        std::string s;

        try {
            // size is OK, no length_error
            // (may throw bad_alloc)
            s.resize(s.max_size() - 1, 'x');
        } catch (const std::bad_alloc&) {
            std::cout << "1. bad alloc\n";
        }

        try {
            // size is OK, no length_error
            // (may throw bad_alloc)
            s.resize(s.max_size(), 'x');
        } catch (const std::bad_alloc& exc) {
            std::cout << "2. bad alloc\n";
        }

        try {
            // size is BAD, throw length_error
            s.resize(s.max_size() + 1, 'x');
        } catch (const std::length_error&) {
            std::cout << "3. length error\n";
        }

    }
    }
}




















