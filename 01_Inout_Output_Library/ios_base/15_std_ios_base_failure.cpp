/// ios_base

#include <iostream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::failure
/*

class failure
member function :
    code
    what

    std::system_error::code
    const std::error_code& code() const;

    std::system_error::what
    virtual const char* what() const;
*/

int main() {
    {
        /// mine : did not know
    }
    {
        /// the site no sample
        std::ifstream f("does not exist");
        try{
            f.exceptions(f.failbit);

        }catch (const std::ios_base::failure& e){
            cout<<" Caught an ios_base::failure.\n"
                <<"Explanatory string: "<< e.what() << '\n'
                <<"Error code " << e.code() << endl;
        }
    }
}





















