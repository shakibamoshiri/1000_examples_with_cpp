/*
            Error Handling
            **************


1.  Exception Handling:
    The header <exception> provides several classes and function related
    to exception handling in C++ program. (defined in header <exception>)

    1.1 capture and storage of exception object
        > exception             : base class for exceptions thrown by the standard library components
        > uncaught_exception    : checks if exception handling is currently is progress
        > uncaught_exceptions   : "
        > exception_ptr         : shared pointer type for handling exception objects
        > make_exception_ptr    : creates an std::exception_ptr from an exception object
        > current_exception     : capture the current exception in a std::exception_ptr
        > rethrow_exception     : throw an exception from a std::exception_ptr
        > nested_exception      : a mixin type to capture and store current exceptions
        > throw_with_nested     : throw its argument with std::nested_exception mixed in
        > rethrow_if_nested     : throw the exception from a std::nested_exception

*/
/// std::rethrow_if_nested

#include <iostream>
#include <fstream>

#include <exception>
#include <stdexcept>
#include <string>

// prints the explanatory string of an exception, if the exception is nested
// recurses to print the explanatory of the exception is holds
void print_exception (const std::exception& er, int level = 0){

    std::cerr << std::string(level, ' ') << " exception: " << er.what() << std::endl;

    try { std::rethrow_if_nested(er); }
    catch (const std::exception& er2) { print_exception(er2, level + 1); }
    catch (...) {}

}

// sample function that catches an exception and wraps it in a nested exception
void open_file (const std::string& fileName){

    try {
        std::ifstream ifs(fileName);
        ifs.exceptions( std::ios_base::failbit );
    } catch (...){ std::throw_with_nested( std::runtime_error( "could not open " + fileName )); }

}

// sample function that catches an exception and wrapes it in a nested exception
void run (){

    try { open_file( "not_existent_file.file" ); }
    catch (...){ std::throw_with_nested( std::runtime_error( "run() function failed" ) ); }

}

// runs the sample function above and prints the caught exception
int main(){

    try { run(); }
    catch (const std::exception& er){ print_exception(er); }

}
