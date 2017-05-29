/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <fstream>


int main(){
    std::filebuf* fbptr = new std::filebuf;
    fbptr->open("04.txt",std::ios_base::out);
    fbptr->sputn("std::filebuf\n",13);

    std::streambuf* sbptr = fbptr;
    delete sbptr;                   // the file is closed, output flashed and written

    std::ifstream ifs("04.txt");
    std::cout << ifs.rdbuf() << std::endl;
}
