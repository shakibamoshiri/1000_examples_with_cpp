
#include <boost/filesystem.hpp>
//#include <cstdio>
#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <regex>


namespace fs = boost::filesystem;



int main(  ){

    for( const fs::directory_entry& de : fs::recursive_directory_iterator( fs::current_path() ) ){
        std::cout << fs::basename( de ) << " : " << fs::basename( de ).size() << '\n';
    }

}
/* the output:
temp : 4
02#size of a directory : 22
a : 1
a : 1
temp : 4
b : 1
temp : 4
c : 1
temp : 4
03#size of a directory.2 : 24
temp : 4
01#getting_exception_for_size_of a directory : 44
04#size of a directory.3 : 24
05#exist : 8
06#empty_file or directory : 26
01 : 2
08#replace_extension : 20
07#_iterate_over_a_path : 23
17#directory_iterator.3_with vector : 35
05#stem_and_extension.2 : 23
10#valid_path_or_invalid : 24
19#directory_iterator.5_vector_of_names : 39
14#space_info : 13
20#directory_iterator.6_vector_of_names.2 : 41
13#get_the_size_of_a_file : 25
16#directory_iterator.2 : 23
02#_component_of_path.2 : 23
12#permission_of_a_file : 23
21#directory_iterator.7_vector_of_names.3 : 41
03#_component_of_path._has.3 : 28
04#stem_and_extension : 21
18#directory_iterator.4_copy : 28
06#stem_and_extension.3 : 23
11#valid_path_or_invalid.2 : 26
15#directory_iterator : 21
09#NOTE_path_just_a_string : 26
one : 3
01#_component_of_path : 21
temp : 4

*/
