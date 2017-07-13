
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::directory_iterator dir_iter( fs::current_path() );
    while( dir_iter != fs::directory_iterator() ){
        std::cout << dir_iter->path().filename() << '\n';
        ++dir_iter;
    }

}
/* the output:

"08#replace_extension.cpp"
"temp.o"
"07#_iterate_over_a_path.cpp"
"05#stem_and_extension.2.cpp"
"10#valid_path_or_invalid.cpp"
"14#space_info.cpp"
"13#get_the_size_of_a_file.cpp"
"02#_component_of_path.2.cpp"
"12#permission_of_a_file.cpp"
"03#_component_of_path._has.3.cpp"
"temp.cpp"
"04#stem_and_extension.cpp"
"06#stem_and_extension.3.cpp"
"11#valid_path_or_invalid.2.cpp"
"09#NOTE_path_just_a_string.cpp"
"one.txt"
"01#_component_of_path.cpp"
"temp"


*/
