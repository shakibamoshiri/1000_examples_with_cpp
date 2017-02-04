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
/// 2. template


/******************/
#include <iostream>
/******************/


void
print( ){
    // never called, except at the end of the recursive call ( print function )
    puts( " end." );
}

template<typename First, typename... Tail>
void
print(First first, Tail... tail){
    std::cout << first << ' ';
    print( tail... );   // tail is pattern, and tail... is parameter pack
}


int main(){

    int number = 3;
    print( 1, 2.2, 0xff, 'T', '\n', "parameter-pack", number );

}

/* output:

1 2.2 255 T
 parameter-pack 3

*/
