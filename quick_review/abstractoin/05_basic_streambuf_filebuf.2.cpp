/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <fstream>


int main(){
    std::filebuf* fbptr = new std::filebuf;
    fbptr->open("05.txt",std::ios_base::out);

    std::string someText = "05_basic_streambuf_std::filebuf\n";
    fbptr->sputn(someText.c_str(),someText.size()+1);

    delete fbptr;                   // the file is closed, output flashed and written

    std::ifstream ifs("05.txt");
    std::cout << ifs.rdbuf() << std::endl;
}
