/**
std::basic_ios
**/

#include <iostream>
#include <sstream>


/// std::basic_ios::clear
/**

void clear ( std::ios_base::iostate state = std::ios_base::goodbit );

Sets the stream error state flags by assigning them the value of state.
By default, assigns std::ios_baic::goodbit which has the effect of clearing all error state flags.

Parameter :
        good bit
state : bad bit
        fail bit
        oef bit

**/

int main() {
    {
        /// mine : did not know
        int i;
        std::cin >> i;
        std::string s;
///why does not work ?
//        std::ios_base::iostate st ;
//        st = std::ios_base::goodbit;
//        std::cin.setstate(st);
        std::cin.clear();
        std::cin >> s;
        std::cout<<s<<" is not a number\n";
        std::cout<<std::endl;
        std::cin.clear();

    }
    {
        /// the site sample
        double d;
        while ( std::cout<<"Please, enter a number\n" && ! (std::cin>>d)){
            std::cin.clear();
            std::basic_string<char> line;
            std::getline ( std::cin, line );
            std::cout<<"I am sorry, but " << line << " is not a number \n";
        }
        std::cout<<"Thank you for entering the number" << d << std::endl;
    }

}

















