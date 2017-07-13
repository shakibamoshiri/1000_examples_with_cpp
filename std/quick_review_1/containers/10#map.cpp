/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

//


int main(){

    std::istringstream word;
    std::ifstream("file") >> word.rdbuf();


    std::vector<std::string> vec { "one","two","three",
                                   "one","two","three","four",
                                   "one","two","three","four","five" };

    std::map<std::string, std::size_t> wp;

    for (const std::string& s : vec) ++wp[s];   // ++, if key is equal

    for (const std::pair<std::string, std::size_t> tmp : wp) std::cout << tmp.first << ' ' << tmp.second << std::endl;
}




