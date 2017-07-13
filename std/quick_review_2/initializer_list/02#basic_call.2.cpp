/*

A review of initializer_list


*/



#include <iostream>
// #include <iterator>
// #include <fstream>



int main(){

    auto init_list = { 1,2,3,4,4,5 };

    // init_list is a initializer_list object
    std::cout << *init_list.begin() << '\n';
    std::cout << *(init_list.end() - 1)<< '\n';
    std::cout << init_list.size()<< '\n';

}
/* output

1
5
6

Process returned 0 (0x0)   execution time : 0.017 s
Press ENTER to continue.


*/
