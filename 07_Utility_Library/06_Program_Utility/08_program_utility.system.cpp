/*
            Program support Utility
            ***********************

Communicating with the Environment:
( in header <stdlib.h> )
( in header <cstdlib> )
    > system            : calls the host environment's command processor
    > getenv            : access the list environment variables

*/
/// std::system
//  int system (const char* command);
//
//  Calls the host environment's command processor (/bin/sh, cmd.exe, command.com)
//  with the parameter command. Returns an implementation-defined value (usually
//  the value that the invoked program returns).

#include <iostream>
#include <cstdlib> // std::system
#include <fstream>

int main (){

    std::system("ls | cat -n > list_count.txt");    // execute the UNIX command ls and cat
    std::cout << std::fstream("list_count.txt").rdbuf() << std::endl;

}
