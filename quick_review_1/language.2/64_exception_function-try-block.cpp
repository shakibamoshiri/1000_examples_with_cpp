/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// 3. exception
//  function try-block


/******************/
#include <iostream>
/******************/

void f_try_block() try {
    std::cout << "inside the function: " << __func__ << '\n';
    std::cout << "okay...\n";
    std::cout << "okay...\n";
    std::cout << "throw an exception...\n";
    throw std::runtime_error( "an exception is occurred!" );

} catch ( std::exception& ex ){
    std::cout << "inside the catch block\n";
    std::cout << "and it says: \n";
    std::cout << ex.what() << std::endl;
}

int main(){

    f_try_block();

}

/* output:

inside the function: f_try_block
okay...
okay...
throw an exception...
inside the catch block
and it says:
an exception is occurred!

*/
