/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::rel_ops::operator !=, >, <=, >=

//  defined in header <utility>

//  Given a user-defined operator == and operator < for object of
//  type T, implements the usual semantics of other comparison operators.


#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

void wget(const int passed_time){
    system("wget -c -i dl");
    std::this_thread::sleep_for(std::chrono::seconds( passed_time ));
    std::cout << "inside the wget" << std::endl;
}

int main(){

/*
$ # this is before running
$ (exec firefox &> /dev/null &)
$ # and look, we still in side the terminal and can continue working
*/
    std::cout << "before wget" << std::endl;
    wget( 5 );
    std::cout << "after wget" << std::endl;

}
/* output for me:



*/
