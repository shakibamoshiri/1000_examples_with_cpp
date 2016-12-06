/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

    Support Operation
    (I skipped this part) you can read the main site

    Property Query
    > alignment_of           obtains the type's alignment requirement (class template)
    > rank                  obtains the number of dimensions of an array type (class template)
    > extent                obtains the size of an array type along a specified dimension (class template)
*/
/// std::is_alignment_of
// Provides the member constant value equal to the alignment requirement
// of the type T, as if obtained by an alignof expression. If T is an array,
// returns the alignment requirements of the element type. If T is a reference
// type, returns the alignment requirements of the type referred to. If alignof (T)
// is not a valid expression, the behavior is undefined.
//
// note:
// This type traits predates the alignof keyword, which can be used to obtain
// the same value which with less verbosity ( verbose )



#include <iostream>
#include <type_traits>

class A {};

int main() {

    std::cout << std::alignment_of<A>::value << '\n';       // 1
    std::cout << std::alignment_of<int>::value << '\n';     // 4
    std::cout << std::alignment_of<double>::value << '\n';  // 8
}
