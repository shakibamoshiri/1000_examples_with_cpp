/**
std::basic_ios
**/

#include <iostream>
#include <iomanip>
#include <fstream>


/// std::basic_ios::exception
/**

std::ios_base::iostate exception () const;
void exception ( std::ios_base::iostate except );

Gets and sets the exception of the stream. The exception amsk determines the error states, no occurrence of which the stream
    throw exception of the failure.

**/

int main() {
    {
        /// mine : did not know

    }
    {
        /// the site sample
        int i;
        try {
            std::ifstream in("in.txt");
            in.exceptions ( std::ifstream::failbit );
            in >> i;
        }
        catch (std::ios_base::failure &fial) {
            /// Handle exception here
            std::cout<<"some of the exceptions"<<std::endl;
        }
    }

}












