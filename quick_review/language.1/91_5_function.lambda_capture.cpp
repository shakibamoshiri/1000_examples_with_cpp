/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// function

#include <iostream>



int main(){

    int one = 1;
    int two = 2;

    // error with [ = ]
    // capture by value so all argument is read-only
    // auto pass_by_value = [ = ](  ){ one += two; two += one; };
//    pass_by_value(  );
    std::cout << one << ' ' << two << '\n';

    auto pass_by_ref = [ & ]( ){ one += two; two += one; };
    pass_by_ref();
    std::cout << one << ' ' << two << '\n';

}
/* output:


*/
