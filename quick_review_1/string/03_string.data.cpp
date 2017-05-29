/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>
#include <string.h>
#include "../../en.cppreference/helpful/user_assert"
// date

int main(){
    typedef std::basic_string<char> string;

    string str = "date member function";

    user_assert(str.size() == str.capacity());
    user_assert(str.size() == strlen(str.data()) );
    user_assert(0 == *(str.data() + str.size()));

}




