/*
Exception:
    01
    02 try-block
    03 function-try-block
    04 noexcept specifier ( since c++11 )

    05 noexcept operator  ( since c++11 )

    06 dynamic exception specifier

    For More Detail Read Main Site = f m d r m s
*/
#include <iostream>
#include <exception>
#include <vector>
#include <utility>
/// noexcept operator ( since c++ 11 )
// The noexcept operator performs a compile-time check that return true
// if an expression is declared no not throw any expression.
// It can be used within a function template's noexcept specifier to declare
// that the function will throw exception for some types but not others.
// syntax:
// noexcept ( expression )
// return a pr-value of type boolean.
//
// Explanation
// The noexcept operator does not evaluate expression
// The result is 'false' if the expression contains at least one of the following potentiality:
//      call to any type of function that does not have non-throwing exception specification, unless it is a constant expression.
//      throw expression
//      dynamic_cast expression when the target type is a reference type, and conversion needs a run time check.
//      typeid expression when argument type is polymorphic class type
// in all other cases the result is true.

void may_thorw();
void no_throw() noexcept;
auto lmay_throw = []{};               // lambda may throw
auto lno_throw = []() noexcept {};    // lambda no throw




class T {
public:
    ~T(){}      // destructor prevents move constructor
                // copy constructor is noexcept
};
class U {
public:
    ~U(){}      // destructor prevents move constructor
                // copy constructor is noexcept ( falst )
    std::vector<int> v;
};
class V {
public:
    std::vector<int> v;
};

int main(){
    T t;
    U u;
    V v;
    std::cout<<std::boolalpha
             << "Is may_thorw()     noexcept? " <<noexcept(may_thorw()) << '\n'
             << "Is no_throw()      noexcept? " <<noexcept(no_throw())  << '\n'
             << "Is lmay_throw()    noexcept? " <<noexcept(lmay_throw())<< '\n'
             << "Is lno_throw()     noexcept? " <<noexcept(lno_throw()) << '\n'
             << "Is ~T()            noexcept? " <<noexcept(std::declval<T>().~T()) << '\n'

             // note: the following test also require that ~T() is noexcept because
             // the expression within noexcept constructs and destroys a temporary

             << "Is T(r-value T)    noexcept? " <<noexcept(T(std::declval<T>()))   << '\n'
             << "Is T(l-value T)    noexcpet? " <<noexcept(T(t))    << '\n'
             << "Is U(r-value U)    noexcpet? " <<noexcept(U(std::declval<U>()))   << '\n'
             << "Is U(l-value U)    noexcept? " <<noexcept(U(u))    << '\n'
             << "Is V(r-value V)    noexcpet? " <<noexcept(V(std::declval<V>()))   << '\n'
             << "Is V(l-value V)    noexcept? " <<noexcept(V(v))    << '\n';
}
