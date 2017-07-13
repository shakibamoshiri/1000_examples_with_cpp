/*
    quick review:

    Language Support
        01. type support
        02. dynamic memory management
        03. error handling
        04. initializer-list
        05. variadic function
    **********************************

*/
/// 03. error handling
//
//   error category:
//   logic_error:
//      invalid_argument
//      domain_error
//      out_of_range
//      future_error
//
//  runtime_error
//      range_error
//      overflow_error
//      underflow_error
//      regex_error
//      system_error
//          los_base::failure
//
//  bad_typed
//  bad_cast
//  bad_weak_ptr
//  bad_function_call
//  bad_alloc
//      bad_array_new_new_length
//  bad_exception
//  ios_bad::failure



#include <iostream>
#include <stdexcept>





int main(){

    try {
        throw std::logic_error( "an logic error was occurred" );
    }catch( const std::exception& err ){
        std::cout << err.what() << '\n';
    }

}
/* output:

an logic error was occurred

*/
