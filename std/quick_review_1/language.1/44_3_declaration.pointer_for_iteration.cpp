/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>
#include <string>
#include <iomanip>

constexpr long operator"" size(const char* str, const std::size_t size){ return size; }

int main(){
    // pointer declaration:


    const char* how("how are you today?");

    // to iterate to this const char*
    // there are six way to iterate through a char* string

    // first way
    for( const char* ch = how; *ch; ++ch)       // ...; *ch; here it means if not a null-terminate character, there is no need to use ch == nullptr but we can use it
        std::cout << *ch << ' ';

    // second way
    std::cout << '\n';
    for( const char* ch = how; *ch != '\0'; ++ch)
        std::cout << *ch << ' ';


    // third way
    std::cout << '\n';
    {
        // const char* begin = how; no need to use it here
        const char* end   = how + "how are you today?"size; // it returns length of this string
        for( const char* ch = how; ch != end; ++ch)
            std::cout << *ch << ' ';
    }

    // forth way
    std::cout << '\n';
    {
        const char* begin = how;
        const char* end   = how + "how are you today?"size; // it returns length of this string
        for( ; begin != end; ++begin)
            std::cout << *begin << ' ';
    }

    // fifth way
    std::cout << '\n';
    {
        const char* begin = how;
        const char* end   = how + "how are you today?"size; // it returns length of this string
        for( ; begin != end; )
            std::cout << *begin++ << ' ';
    }

    // sixth way
    std::cout << '\n';
    {
        const char* begin = how;
        const char* end   = how + "how are you today?"size; // it returns length of this string
        while( begin != end )
            std::cout << *begin++ << ' ';
    }


    // as you can see it is a play around pinter and test-condition
    // iterator in reveres order
    std::cout << '\n';
    {
        const char* begin = how;
        const char* end   = how + "how are you today?"size; // it returns length of this string
        while( begin != end )
            std::cout << *--end<< ' '; // output is: ? y a d o t   u o y   e r a   w o h

    }

    // print word by word
    std::cout << '\n';
    for( const char* ch = how; *ch != '\0'; ++ch){

        if( *ch == ' ' ) { puts(""); continue; }        // puts("") == std::cout << '\n';

        std::cout << *ch;
    }

    // counts the length of each word
    std::cout << '\n';
    int count = 0;
    how = "a aa aaa aaaa a aa aaa aaaa aaaa-aaaa a-a a";
    std::cout << how << std::endl;
    for( const char* ch = how; *ch != '\0'; ++ch,++count){

        if( *ch == ' ') {
            std::cout << std::setw( count ) << count << ' ';    // to set the output according to the word and prints it
            count = -1;                                         // -1 because after that it becomes 0 and we need to count from 0
            continue;                                           // continue for skip the ' '(one space)
        }

        if( *( ch + 1 ) == '\0' ) std::cout << count + 1;       // print the last count before exiting from loop

    }

    // of course you can count how many word there are
    // if you count a new integer in the first if ( *ch == ' ')
    // and the print it, in the second if
    /*


    // counts the length of each word
    std::cout << '\n';
    int count = 0;
    int word_count = 0;
    how = "a aa aaa aaaa a aa aaa aaaa aaaa-aaaa a-a a";
    std::cout << how << std::endl;
    for( const char* ch = how; *ch != '\0'; ++ch,++count){

        if( *ch == ' ') {
            ++word_count;
            std::cout << std::setw( count ) << count << ' ';    // to set the output according to the word and prints it
            count = -1;                                         // -1 because after that it becomes 0 and we need to count from 0
            continue;                                           // continue for skip the ' '(one space)
        }

        if( *( ch + 1 ) == '\0' ) {
            std::cout << count + 1 << '\n';                     // print the last count before exiting from loop
            std::cout << "there are: "
                      << word_count + 1                         // +1 because if we have 10 spaces between the words, it means we have 11 words
                      << " word\n";
        }
    }


    */






}
