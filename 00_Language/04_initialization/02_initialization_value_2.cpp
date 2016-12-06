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
Value Initialization
This is the initialization performed when a variable is constructed with an empty initializer:
Syntax:
1   T();
2   new T();
3   class::class(...) : member () {...
4   T object {};
5   T{};
6   new T{}
7   class::class : member{} {...

Note: A constructor is user-provided if ti is user-provided and not explicitly
      defaulted on its first declaration. The syntax T object(); does not initialize
      an object; it declares a function that take no argument and return T. The way
      to value-initialize a named variable before c++11 was T object = T();, which
      value-initializes a temporary and then copy-initializes the object: most compiler
      optimize out the copy in this case.


*/

#include <iostream>
#include <string>
#include <vector>

struct T1 {
    int mem1;
    std::string mem2;
    // implicit default constructor
};

struct T2 {
    int mem1;
    std::string mem2;
    T2(const T2&){} // user-provided copy constructor
                    // no default constructor
};

struct T3 {
    int mem1;
    std::string mem2;
    T3() {} // user-provided default constructor
};

std::string s{};    // class => default initialization ( the value is "" )

int main(){                     // scalar means: (of an quantity ) having size but not direction
    int n{};                    // scalar, zero-initialization: the value is 0
    double d = double();        // scalar, zero-initialization: the value is 0.0
    int* a = new int[10]();     // array, value-initialization of each element
                                //        that the value of each element is 0
    T1 t1{};                    // class with implicit default constructor ( no any user-provided )
    // t1.mem1 is zero-initialized
    // i1.mem2 is default-initialized

    //T2 T2{};                    // error, class with no default constructor
    // needs a user-provided default constructor to initialize their data

    T3 t3{};                    // class with user-provided default constructor
    // t3.mem1 is default-initialized to indeterminate value
    // t3.mem2 is default-initialized, the value is ""

    std::vector<int> v(3);      // the value of each element is value-initialized to 0

    std::cout<<s.size()<<' '<<n<<' '<<d<<' '<<a[9]<<' '<<v[2]<<std::endl;

    // t1.mem1 is int, t3.mme1 int too.
    // but t1, has no default constructor, by default their value is initialized to zero
    // and t3, has an default constructor whitout initialized their values

    std::cout<<t1.mem1<<','<<t1.mem2<<std::endl; // int = 0 and std::string = ""
    std::cout<<t3.mem1<<','<<t3.mem2<<std::endl; // int =   and std::string = ""

}









