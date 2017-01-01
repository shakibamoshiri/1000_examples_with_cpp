/*
        std::tuple
        **********

defined in header <tuple>

Class template std::tuple is a fixed-size collection of heterogeneous
values. It is a generalization on std::pair.

Non-member Function:
    make_tuple                  creates a tuple object of the type defined by the argument types
    tie                         creates a tuple of l-value reference or unpacks a tuple
    forward_as_tuple            creates a tuple of r-value reference
    std::get( std::tuple )      tuple accesses specified element
    operator ==                 lexicographically compares the value of tuples
    operator !=                 "
    operator >                  "
    operator <                  "
    operator <=                 "
    operator >=                 "
    std::swap ( std::tuple )    specializes the std::swap algorithm



*/
/// std::make_tuple

//  Creates a tuple object, deducing the target type from
//  the types of argument. For each


#include <iostream>
#include <tuple>
#include <functional>

std::tuple< int, int > f (){
    int temp = 2;

    return std::make_tuple( temp, 3 );
}

// it is a illegal syntax but it works
std::tuple< int , int > g (){
    return (std::pair<int, int>){ 3, 2 };
}

int main(){

    // heterogeneous tuple construction
    int number = 1;
    auto tuple = std::make_tuple( 23, "test", 3.2, std::ref( number ), number );

    number = 9;

    std::cout << "the value of the tuple: \n"
              << std::get< 0 >( tuple ) << '\n'
              << std::get< 1 >( tuple ) << '\n'
              << std::get< 2 >( tuple ) << '\n'
              << std::get< 3 >( tuple ) << '\n'
              << std::get< 4 >( tuple ) << '\n';

    // function returning multiple value
    int first, second;

    std::tie( first, second ) = f();
    std::cout << first << ' ' << second << '\n';

    std::tie( first, second ) = g();
    std::cout << first << ' ' << second << '\n';

}

/* output for me
the value of the tuple:
23
test
3.2
9
1
2 3
3 2



*/
