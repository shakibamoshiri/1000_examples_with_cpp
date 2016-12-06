/*
Template:
    01 template parameter and template argument
    02 class template
    03 function template
    04 variable template
    05 template argument deduction
    06 explicit (full) template specialization
    07 partial template specialization
    08 parameter pack
    09 sizeof ... operator
    10 fold expression

    11 dependent names

    12 SFINAE
    13 constraints and concepts
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

/// 10 Depending Name
// Inside the definition of a template ( both class-template and function-template ),
// the meaning of some constructs may differ form one instantiation to another. In
// particular types and expression may depend on types of type template parameter and
// value of non-type template parameter.
//
//
//
//
/// Example
//
// Bas idea: operator in global namespce, but its argument are in std::
std::ostream& operator<<(std::ostream& out, std::pair<int, double> p) {
    return out<<p.first<<' '<<p.second;
}



int main() {
    typedef std::pair<int, double> elem_t;
    std::vector<elem_t> v(10);
    std::cout<<v[0]<<std::endl;     // okay, ordinary lookup find ::operator
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<elem_t>(std::cout, " ")); // ERROR
    // Both ordinary lookup from the point of definition of std::ostream_iterator
    // and ADL will only consider the std namespace, and will find many overloads of
    // std::operator<<, so the lookup will be done. Overload resolution will then
    // fail to find operator<< for elem_t in the set found by the lookup.
}
