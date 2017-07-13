/*

A review of string library( char_treats )

*/

/// char_traits::

// The char_traits class is a traits class template that abstracts basic character and string
// operations for a given character type. The defined operation set is such that generic algorithms
// almost always can be implemented in terms of it. It is thus possible to use such algorithms with
// almost any possible character or string type, just by supplying customized char_traits class.


#include <iostream>
#include <string>
#include <cctype>

struct user_char_traits : public std::char_traits< char > {
    static bool eq( char c1, char c2 ){
        return std::tolower( c1 ) == std::tolower( c2 );
    }

    static bool lt( char c1, char c2 ){
        return std::tolower( c1 ) < std::tolower( c2 );
    }

    static int compare( const char* str_1, const char* str_2, std::size_t n ){
        while( n-- != 0 ){
            if( std::tolower( *str_1 ) < std::tolower( *str_2 ) ) return -1;
            if( std::tolower( *str_1 ) > std::tolower( *str_2 ) ) return 1;

            ++str_1;
            ++str_2;
        }
        return 0;   // if both are equal
    }

    static const char* find( const char* str, int n, char c ){
        const char chr = std::tolower( c );

        while( n-- != 0 ){
            if( std::tolower( *str ) == chr ) return str;

            // if still not then:
            ++str;
        }
        return nullptr;
    }
};

using user_string = std::basic_string< char, user_char_traits >;

std::ostream& operator <<( std::ostream& output, const user_string& str ){
    return output.write( str.data(), str.size() );
}

int main(){

    // test the custom user_string
    user_string str_1 = "How Are You Today?";
    user_string str_2 = "how are you today?";

    if( str_1 == str_2 ) // then
        std::cout << str_1 << " and " << str_2 << " are equal\n";

}

/**

How Are You Today? and how are you today? are equal

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.

**/
