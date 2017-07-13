/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::sputbackc
//  int_type sputbackc( char_type c );
//
//  Put character back

//  note:
//  Member function sungetc() behaves in a similar way, but without taking any arguments.


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>




int main(){

    // sputbackc()

    std::streambuf* stream_buffer = std::cin.rdbuf();
    char chr = '\0';
    std::cout << "Please enter some letters and then a number: ";

    do{
        chr = stream_buffer->sgetc();
        if( ( chr >= '0' ) && ( chr <= '9' ) ){
            // the same result without using sputbackc()
//            stream_buffer->sputbackc( chr ); // sputbackc( char chr )

            int number;
            std::cin >> number;
            std::cout << "You entered the number: " << number << '\n';
            break;
        }
    }while( stream_buffer->sbumpc() != std::streambuf::traits_type::eof() );

}
/**

Please enter some letters and then a number: I have only 3 dollars!
You entered the number: 3

Please enter some letters and then a number: abcdef 12345 abcdef
You entered the number: 12345

Please enter some letters and then a number: AAAA3333BBBB
You entered the number: 3333


**/
