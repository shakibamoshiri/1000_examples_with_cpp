/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>

struct S { char greet[10]={}; };

std::ostream& operator << (std::ostream& out,S* s){

    // good in use
    // checks weather the preparation fo the output stream was successful.
    std::ostream::sentry okay(out);

    if(okay) out.write(s->greet,sizeof (s->greet));

    return out;
}

int main(){

    S s0 = {"hello ..."};
    std::cout << &s0 << std::endl;

}
