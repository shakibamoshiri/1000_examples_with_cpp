/**
std::basic_istream
**/


/// 17_std::basic_istream::sync
/**

int sync ();

Synchronizes the input buffer with the associated date source.

Return value : 0 on success, -1 on failure or id the stream does not
    support this setstate(badbit ) and return -1.

**/
#include <iostream>
#include <sstream>
#include <fstream>

void file_abc () {
    std::basic_ofstream<char> ofs ("test_sync.txt");
    ofs << "ABC\n";
}
void file_123 () {
    std::basic_ofstream<char> ofs("test_sync.txt");
    ofs << "123\n";
}

int main() {
    {
        /// mine
    }
    {
        /// the site sample
        file_abc(); /// file now contain "ABC"
        std::basic_ifstream<char> ifs("test_sync.txt");
        std::cout<<"Reading form the file : ";
        char c;
        ifs >> c ;
        std::cout<<c;
        file_123(); /// file now contain "123"
        ifs >> c ;
        std::cout<<c;
        ifs >> c ;
        std::cout<<c;
        ifs.close();

        std::cout<<std::endl;

        file_abc(); /// "ABC"
        ifs.open("test_sync.txt");
        std::cout<<"Reading form the file with sync() : ";
        ifs >> c;
        std::cout<<c;

        file_123(); /// "`123"
        ifs.close();
        ifs.open("test_sync.txt");
        ///ifs.sync(); /// synchronize the input buffer with the associated date source

        ifs >> c;
        std::cout<<c;
        ifs >> c;
        std::cout<<c<<std::endl;


    }

    {
        /// msdn.microsoft.com
    }

}













