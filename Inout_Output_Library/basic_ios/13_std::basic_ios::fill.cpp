/**
std::basic_ios
**/

#include <iostream>
#include <iomanip>


/// std::basic_ios::fail
/**
CharT fill () const;
CharT fill (CharT ch);

Manage the fill character used to pad the output conversation to the specified field width.
    1. Return the current fill character
    2. Sets the fill character to 'ch', return previous value of the fill character

**/

int main() {
    {
        /// mine : did not know
        std::cout.fill('_');
        std::cout<<std::cout.fill()<<std::endl;
        std::cout<<std::cout.fill()<<std::setw(10)<<'|'<<std::endl;
        std::cout<<std::cout.fill()<<std::setw(10)<<'|'<<std::endl;
        std::cout<<std::cout.fill()<<std::setw(10)<<'|'<<std::endl;

    }
    {
        /// the site sample
        std::cout<<"With default setting : "<<std::setw(10)<<88<<std::endl;
        char pr = std::cout.fill('o');
        std::cout<<"Replace '"<<pr<<"' with '"<<std::cout.fill()<<"' :"<<std::setw(10)<<88<<std::endl;
    }

}












