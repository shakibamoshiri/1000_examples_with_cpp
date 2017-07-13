/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <vector>
#include <map>
#include <fstream>

// word count


int main(int argi, char** argv){

    std::ifstream ifs(*(++argv)); // opens the file

    std::vector<std::string> vstr;  // for storing the file
    std::string str;                // for getting a word from input-file-stream

    while (!ifs.eof()){             // store each word in the vstr (vector)
        ifs >> str;
        vstr.push_back( str );
    }


    std::map<std::string, std::size_t> word_count;      // for storing the word and key
    for (const std::string& s : vstr) ++word_count[s];  // counts for each key

    for (const std::pair<std::string, std::size_t>& pw : word_count) std::cout << pw.second << ' ' << pw.first << std::endl;    // print key and word

    return 0;
}




