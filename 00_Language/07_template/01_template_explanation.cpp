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
/// 01 template parameter and template argument
// Every template is parametrized by one or more template parameter,
// included in the parameter-list of the template declaration
// syntax:
// template < parameter-list > declaration
// three type of parameter-list are:
// 001  a non-type template parameter
// 002  a type template parameter
// 003  a template template parameter ( since c++17 )
//
/// first Non-type template parameter
// syntax:
// type name ( optional )
// type name ( optional ) = default;
// type ...  ( optional )           since c++11
// type is one of the following types ( optionally constant-volatile-qualified, the qualifiers are ignored )
// # std::nullptr_t
// # integral type , ( like int )
// # l-value reference type ( to object or to function )
// # pointer type ( to object or to function )
// # pointer to member type ( to member object or to member function )
// # enumeration type
//
/// second Type parameter pack
// typename name ( optional )
// class    name ( optional )
// typename or class name ( optional ) = default
// typename or class ... name ( optional )
// Note: there is no different between typename and class in the type template parameter declaration
//
/// third   Template template parameter
// template< parameter-list> typename (c++17) | class name ( optional )
// template< parameter-list> typename (c++17) | class name ( optional ) = default
// template< parameter-list> typename (c++17) | class  ... name ( optional )

// this is a template template parameter:

template<typename T> class my_array{};
template<typename K, typename V, template<typename> typename C = my_array>
class Map {
    C<K> kay;
    C<V> value;
};

int main(){}

