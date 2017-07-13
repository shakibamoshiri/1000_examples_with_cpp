#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::getline
/*
Defined in header <string>

template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>& input,
                                           std::basic_string<CharT,Traits,Allocator>& str,
                                           CharT delim );

template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>&& input,
                                           std::basic_string<CharT,Traits,Allocator>& str,
                                           CharT delim );

template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>& input,
                                           std::basic_string<CharT,Traits,Allocator>& str );

template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>&& input,
                                           std::basic_string<CharT,Traits,Allocator>& str );


Parameters
input	-	the stream to get data from
str	-	the string to put the data into
delim	-	the delimiter character


Return value
input
*/

int main() {
    std::basic_string<char> s;

    std::getline(cin,s);

    cout<<s<<endl;
    {
        /// Sample of en.cppreference
        std::string name;
        cout<<"What is you name ? ";
        std::getline(cin,name);
        cout<<"Hello "<<name <<", nice to meet you"<<'\n';

        /// read file line by line
        std::istringstream input;
        input.str("1\n2\n3\n4\n5\n6\n7\n");
        int sum(0);
        for (std::string line; std::getline(input,line);)
            sum+= std::stoi(line);

        cout<<'\n'<<"The sum is : "<<sum<<'\n';
    }
}





















