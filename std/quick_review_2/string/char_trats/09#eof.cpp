/*

A review of string library( char_treats )

*/

/// char_traits::eof
//  static constexpr int_type eof() noexcept;
//
//  end-of-file character
//  end-of-file value

#include <iostream>
#include <string>



int main(){

    std::cout << "enter some word: ";
    if( std::cin.peek() == std::char_traits< char >::eof() ){
        std::cout << "error\n";
    } else {
        std::string string;
        std::getline( std::cin, string );
        std::cout << "you entered: " << string << '\n';
    }
}

/**

enter some word: how are you today?
you entered: how are you today?

Process returned 0 (0x0)   execution time : 3.641 s
Press ENTER to continue.



**/
