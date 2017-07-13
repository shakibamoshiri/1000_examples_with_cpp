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


#include <vector>
#include <iostream>
#include <initializer_list>

template<class T> struct S {
    std::vector<T> vector;

    // constructor
    S (std::initializer_list<T> i_list): vector( i_list ) { std::cout << "constructed with a " << i_list.size() << "-element list\n"; }

    // initializer_list as a argument in a function call
    void append (std::initializer_list<T> il){ vector.insert( vector.end(), il.begin(), il.end() ); }

    // as return
    // copy list-initialization in return statement
    // This is NOT a use of std::initializer_list
    std::pair<const T*, std::size_t> c_arr () const { return {&vector[0], vector.size()}; }

}; // end of struct S

template<typename T> void templated_fn (T tmp) {
    for( const int i : tmp ) std::cout << i << ' ';
}


int main(){

    S<int> s = {1, 2, 3, 4, 5};     // copy list-initialization
    s.append( {6, 7, 8} );          // list-initialization in function call

    std::cout << "The vector size is now: " << s.c_arr().second << " ints\n";

    for( const int tmp : s.vector ) std::cout << tmp << ' '; // print the content of s.vector

    std::cout << "\nRange-for over brace-init-list\n";
    for( int tmp : {-3, -2, -1, 0, 1, 2, 3} ) std::cout << tmp << ' ';  // the rule for auto make this ranged-for work

    auto alist = {9, 10, 11, 12};   // special rule for auto
    std::cout << "The list bound to auto has size: " << alist.size() << '\n';

//    templated_fn( {1, 3, 5} );  // compile error, "{1,3,5}" is not a expression

    templated_fn<std::initializer_list<int>>( {1, 3, 5} );  // okay it works, because now it knows its argument
    std::cout << '\n';

    templated_fn<std::vector<int>>( {5, 3, 1} );            // also it knows what it is.


}
