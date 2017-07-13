/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************


*/
/// Fixed width integer types (since C++11)


#include <iostream>


#define _(...)  endl (std::cout<< sizeof #__VA_ARGS__ )


int main(){

     _(int);

     _(int8_t);   _(int16_t);   _(int32_t);    _(int64);

     _(int_fast16_t);

     _(intmax_t);

     _(uintmax_t);

     /// For more detail see the main site

}
