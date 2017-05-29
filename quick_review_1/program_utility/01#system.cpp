/*
    quick review:
    General-Purpose Utility

    01. program utility
    02. date and time
    03. bitset
    04. function object
    05. pair
    06. tuple
    07. swap, forward, move
    08. type operations
    09. hash support

*/
/// 01. program utility
//  <cstdlib>
//  in system( const char* command ){}


#include <iostream>
#include <cstdlib>
#include <fstream>



int main(){

    system( "ls -l > list_of" );    // runs the ls -l command and store it to the list_of ( plain text file )
    std::cout << std::ifstream( "list_of" ).rdbuf();     // print the content of the list_of


}

/* output:

total 84
drwxrwxr-x 2 shu shu  4096 دسامب  2 22:39 abstractoin
drwxrwxr-x 2 shu shu  4096 ژانوی 17 17:48 algorithm
drwxrwxr-x 2 shu shu  4096 دسامب  3 21:42 containers
drwxrwxr-x 2 shu shu  4096 ژانوی 28 11:36 dynamic_memory_management
drwxrwxr-x 2 shu shu  4096 ژانوی 28 12:15 error_handling
drwxrwxr-x 2 shu shu  4096 ژانوی 28 13:04 initializer_list
drwxrwxr-x 2 shu shu  4096 ژانوی 24 19:48 iterator
drwxrwxr-x 2 shu shu 12288 ژانوی  6 18:23 language.1
drwxrwxr-x 2 shu shu  4096 ژانوی 16 12:09 language.2
-rw-rw-r-- 1 shu shu     0 ژانوی 30 12:09 list_of
drwxrwxr-x 2 shu shu  4096 ژانوی 24 19:48 regex
-rw-rw-r-- 1 shu shu  3841 ژانوی 29 14:58 split_ask.cpp
drwxrwxr-x 2 shu shu  4096 نوامب 24 19:22 string
-rwxrwxr-x 1 shu shu  8088 ژانوی 30 12:09 temp
-rw-rw-r-- 1 shu shu   617 ژانوی 30 12:09 temp.cpp
-rw-rw-r-- 1 shu shu  2288 ژانوی 30 12:09 temp.o
-rw-rw-r-- 1 shu shu  1588 ژانوی 30 12:02 test_split_v_3.cpp
drwxrwxr-x 2 shu shu  4096 ژانوی 27 16:26 type_support
-rw-rw-r-- 1 shu shu     6 ژانوی 28 13:55 window_siz

*/
