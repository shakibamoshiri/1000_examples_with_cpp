/**
/// constexpr specifier
///
Specifies that the value of a variable or function can appear
in constant expression.

The constexpr specifier declares that it is possible in evaluate the
of the function or variable at compile time. Such variables and function
can then be used where only compile time constant expressions are allowed
( provided that appropriate function argument are given ). A constexpr
specifier used in an object declaration implies const. A constexpr specifier
used in a function declaration implies inline.
**/
#include <iostream>
#include <string>
#include <stdexcept>

// c++11 constexpr functions use recursion rather than iteration
// c++14 constexpr functions may use local variables and loobs
constexpr int factorial (int n){
    return n <= 1 ? 1 : ( n * factorial(n-1) );
    //    if ?  true  : false
}
class conststr {
private:
    const char* p;
    std::size_t sz;
public:
    template<std::size_t N>
    constexpr conststr(const char (&a)[N]) : p(a), sz(N-1) {}

    // constexpr functions single errors by throwing exception
    // in c++11, they must do so from the conditional operator ?:
    constexpr char operator[](std::size_t n) const {
        return n < sz ? p[n] : throw std::out_of_range("");
    }
    constexpr std::size_t size() const { return sz; }
};

// c++11 constexpr functions has to put everything in a single return statement
// c++14 does not have that requirement
constexpr std::size_t countLower( conststr s, std::size_t n=0, std::size_t c=0){
    return n==s.size() ? c :
        s[n] >= 'a' && s[n] <= 'z' ? countLower(s, n+1, c+1) :
            countLower(s, n+1, c);
}

// output function that requires a compile-time constant, for testing
template<int n>
struct countN {
    // default constructor call when the object is created.
    countN() { std::cout<<n<<std::endl;}
};

int main(){
    // testing Fact
    countN<3> one;

    std::cout<<"4! = ";
    countN<factorial(4)> f4;  // computed at compile time
    volatile int i8 = 8;        // disallow optimization using volatile
    std::cout<<i8<<"! = "<<factorial(8)<<std::endl;  // computed at run-time

    std::cout<<"the number of lowercase letters in \"Hello World\" is: ";
    countN<countLower("Hello World")> hw;
}











