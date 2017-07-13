
#include <boost/filesystem.hpp>
//#include <cstdio>
#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <regex>


namespace fs = boost::filesystem;



int main(  ){

    for( const fs::directory_entry& de : fs::recursive_directory_iterator( fs::current_path() ) ){
        std::cout << ( fs::is_empty( de ) ? ( de.path().string() + "  -> empty\n" ) : "NOT empty\n" );
    }

}
/* the output:

NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
/home/shu/codeblock/ideas/brm_dir/a/b/c  -> empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
NOT empty
/home/shu/codeblock/ideas/brm_dir/01/one.txt  -> empty
NOT empty
NOT empty

*/
