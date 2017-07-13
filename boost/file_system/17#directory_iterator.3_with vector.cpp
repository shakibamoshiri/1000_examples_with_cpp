
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>
#include <vector>

namespace fs = boost::filesystem;


int main( ){

    std::vector< fs::directory_entry > vec_of_dir{
        fs::directory_iterator( fs::current_path() ),
        fs::directory_iterator()
    };

    for( const fs::directory_entry& de : vec_of_dir ){
        std::cout << de.path().string() << '\n';
    }

}
/* the output:

/home/shu/codeblock/ideas/brm_dir/08#replace_extension.cpp
/home/shu/codeblock/ideas/brm_dir/temp.o
/home/shu/codeblock/ideas/brm_dir/07#_iterate_over_a_path.cpp
/home/shu/codeblock/ideas/brm_dir/05#stem_and_extension.2.cpp
/home/shu/codeblock/ideas/brm_dir/10#valid_path_or_invalid.cpp
/home/shu/codeblock/ideas/brm_dir/14#space_info.cpp
/home/shu/codeblock/ideas/brm_dir/13#get_the_size_of_a_file.cpp
/home/shu/codeblock/ideas/brm_dir/16#directory_iterator.2.cpp
/home/shu/codeblock/ideas/brm_dir/02#_component_of_path.2.cpp
/home/shu/codeblock/ideas/brm_dir/12#permission_of_a_file.cpp
/home/shu/codeblock/ideas/brm_dir/03#_component_of_path._has.3.cpp
/home/shu/codeblock/ideas/brm_dir/temp.cpp
/home/shu/codeblock/ideas/brm_dir/04#stem_and_extension.cpp
/home/shu/codeblock/ideas/brm_dir/06#stem_and_extension.3.cpp
/home/shu/codeblock/ideas/brm_dir/11#valid_path_or_invalid.2.cpp
/home/shu/codeblock/ideas/brm_dir/15#directory_iterator.cpp
/home/shu/codeblock/ideas/brm_dir/09#NOTE_path_just_a_string.cpp
/home/shu/codeblock/ideas/brm_dir/one.txt
/home/shu/codeblock/ideas/brm_dir/01#_component_of_path.cpp
/home/shu/codeblock/ideas/brm_dir/temp

*/
