/*
            Initializer List
            ****************

(defined in header <initializer_list>)
An object of type std::initializer_list<T> is a lightweight proxy
that provides access to an array of objects of type const T.

Member Type:
    value_type
    reference
    const_reference
    size_type
    iterator
    const_iterator

Member Function
    > constructor   : creates an empty initializer_list
    > size          : returns the number of the elements in the initializer list
    (non-member function)
    > begin         : returns a pointer to the first element
    > end           : returns a pointer to the last element
    > std::begin( obj ) : specialized for begin
    > std::end( obj )   : specialized for end
    (defined in header <iterator>)
    > rbegin        : specialized for reverse begin
    > rend          : specialized for reverse end
*/
/// end()
//  Returns a pointer to the past the last element in the
//  initializer list. i.e. begin() + size()
//  If the initializer list is empty, the value of begin() and end()
//  are unspecified, but will be identical.


#include <iostream>
#include <initializer_list>



int main(){

    // creates initializer list using list-initialization
    std::initializer_list<int> digits {1, 2, 3, 4, 5};
    std::cout << digits.end()-1 << '\n';      // address before the end
    std::cout << *(digits.end()-1) << '\n';   // value == 5
}
