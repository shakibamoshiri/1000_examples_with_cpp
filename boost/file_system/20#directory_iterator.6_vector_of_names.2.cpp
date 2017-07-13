
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

    std::vector< std::string > result_data( list_of_names.size(), "" );
    std::transform( list_of_names.begin(),
                    list_of_names.end(),
                    result_data.begin(),
                    [](const fs::directory_entry& de ){
                        if( !std::regex_search( de.path().string(), std::regex( "\\.cpp" ) ) ){
                            return de.path().string();
                        } else {
                            return std::string();
                        }
                    } );

    // remove empty elements
    result_data.erase(
    std::remove_if( result_data.begin(),
                    result_data.end(),
                    []( const std::string& str){
                        return str.empty();
                    } ),
                    result_data.end() );

    for( const std::string& str : result_data ){
        std::cout << str << '\n';
    }


}
/* the output:
/home/shu/codeblock/ideas/brm_dir/temp.o
/home/shu/codeblock/ideas/brm_dir/one.txt
/home/shu/codeblock/ideas/brm_dir/temp

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.



*/
