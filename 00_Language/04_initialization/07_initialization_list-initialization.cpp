/*
Initialization:
    value       initialization
    copy        initialization
    direct      initialization
    aggregate   initialization
    list        initialization
    reference   initialization
    zero        initialization
    constant    initialization
********************************
List Initialization
Initializes an object form braced-initialization-list

direct list initialization
1   T object {arg1, arg2, ...};
2   T { arg1, arg2, ... };
3   new T {arg1, arg2, ... }
4   class {T member { arg1, arg2, ...}; };
5   class::class() : member { arg1, arg2, ...}{...

copy list initialization
1   T object = { arg1, arg2, ... };
2   function ( {arg1, arg2, ...} );
3   return {arg1, arg2, ...};
4   object [ {arg1, arg2, ... } ];
5   object = { arg1, arg2, ... };
6   U ( {arg1, arg2, ...} );
7   class { T member = { arg1, arg2, ...}; };
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

struct F {
    std::vector<int> mem = {1,2,3}; // list-initialization of non-static member
    std::vector<int> mem2;
    F() : mem2{-1,-2,-3} {}
};

std::pair<std::string, std::string> f (std::pair<std::string, std::string> p){
    return {p.first, p.second}; // list-initialization in return statement
}


int main(){
    int n0{};       // value-initialization ( to zero )
    int n1{1};      // direct-list-initialization

    std::string s1{'a','b','c','d'};    // initializer-list constructor call
    std::string s2{s1,2,2};             // regular constructor call
    std::string s3{0x61,'a'};           // initializer-list constructor is preferred to (int, char)

    int n2 = {1};           // copy-list-initialization
    double d = double{1.2}; // list-initialization of a temporary, then copy-list

    std::map<int, std::string> m { // nested list-initialization
        {1, "aaa"},
        {2, {'b','b','b'}},
        {3, s1}
    };

    std::cout<<f({"hello", "world"}).first<<std::endl;    // list-initialization in function call

    const int (&ar)[2] = {1,2};     // binds a l-value reference to a temporary array
    int&& r1 = {1};                 // binds a r-value reference to a temporary int
//    int& r2 = {2};                  // error, cannot bind r-value to a non-const l-value reference

//    int bad{1.0};       // error, narrowing conversion
    unsigned char uc1{10};  // okay,
//    unsigned char uc1{-1};  // error, narrowing conversion

    std::cout<<n0<<' '<<n1<<' '<<n2<<std::endl
             <<s1<<' '<<s2<<' '<<s3<<std::endl;

    for ( std::pair<int, std::string> t: m)
        std::cout<<t.first<<' '<<t.second<<std::endl;

    F f; // create an object from F
    for ( const int t: f.mem )
        std::cout<<t<<' ';
    for ( const int t: f.mem2)
        std::cout<<t<<' ';
}










