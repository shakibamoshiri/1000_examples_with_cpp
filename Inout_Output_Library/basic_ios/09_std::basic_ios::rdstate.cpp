/**
std::basic_ios
**/

#include <iostream>
#include <sstream>


/// std::basic_ios::rdstate
/**
iostate rdstate () const;

Return the current stream error state.

**/

int main() {
    {
        /// mine : did not know
        std::basic_ostringstream<char> stream;

        stream.clear();
        stream.setstate(std::ios_base::goodbit);
        std::cout<<"stream.rdstate() with goodbit "<<stream.rdstate()<<std::endl;

        stream.clear();
        stream.setstate(std::ios_base::badbit);
        std::cout<<"stream.rdstate() with badbit "<<stream.rdstate()<<std::endl;

        stream.clear();
        stream.setstate(std::ios_base::failbit);
        std::cout<<"stream.rdstate() with failbit "<<stream.rdstate()<<std::endl;

        stream.clear();
        stream.setstate(std::ios_base::eofbit);
        std::cout<<"stream.rdstate() with eofdbit "<<stream.rdstate()<<std::endl;
    }
    {
        /// the site sample
        std::basic_ostringstream<char> stream;

        if(stream.rdstate() == std::ios_base::goodbit )
            std::cout<<"Stream state is goodbit\n";
        stream.clear();
        stream.setstate(std::ios_base::eofbit);

        if(stream.rdstate() == std::ios_base::eofbit )
            std::cout<<"Stream state is end-of-file\n";
        stream.clear();
        std::cout<<std::endl;


    }
}

















