
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>

namespace fs = boost::filesystem;



int main( ){

    std::vector< fs::directory_entry > list_of_names;

    std::copy( fs::directory_iterator( fs::current_path() ),                                        // first
               fs::directory_iterator(),                                                            // last
               std::back_insert_iterator< std::vector< fs::directory_entry > >( list_of_names ) );  // the output

    std::vector< const char* > result_data( list_of_names.size(), "" );
    std::transform( list_of_names.begin(),
                    list_of_names.end(),
                    result_data.begin(),
                    [](const fs::directory_entry& de ){
                        return de.path().string().data();
                    } );

    for( const char* str : result_data ){
        std::cout << str << '\n';
    }


}
/* the output:

/home/shu/codeblock/ideas/brm_dir/08#replace_extension.cpp
/home/shu/codeblock/ideas/brm_dir/temp.o
/home/shu/codeblock/ideas/brm_dir/07#_iterate_over_a_path.cpp
/home/shu/codeblock/ideas/brm_dir/17#directory_iterator.3_with vector.cpp
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
/home/shu/codeblock/ideas/brm_dir/18#directory_iterator.4_copy.cpp
/home/shu/codeblock/ideas/brm_dir/06#stem_and_extension.3.cpp
/home/shu/codeblock/ideas/brm_dir/11#valid_path_or_invalid.2.cpp
/home/shu/codeblock/ideas/brm_dir/15#directory_iterator.cpp
/home/shu/codeblock/ideas/brm_dir/09#NOTE_path_just_a_string.cpp
/home/shu/codeblock/ideas/brm_dir/one.txt
/home/shu/codeblock/ideas/brm_dir/01#_component_of_path.cpp
/home/shu/codeblock/ideas/brm_dir/temp

*/
