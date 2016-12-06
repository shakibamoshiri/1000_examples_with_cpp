/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Runtime Type Identification (Defined in header <typeinfo>)

    > type_info     contains some type's information, generated by implementation.
                    This is a class returned by typeid operator
    > type_index    wrapper around a type_info object, that can be used as index in associated and unordered
                    associative containers (class)
    > bad_typeid    exception that is thrown if an argument in a typeid expression is null (class)
    > bad_cast      exception that is thrown by  an invalid dynamic_cast expression i.e. cast of reference
                    type fails (class)
*/
/// std::type_info
// The class type_info holds implementation-defined about a type,
// including the name of the type and means to compares two type
// for equality or collating order. This is the class returned by
// the typeid operator.
//
// The type_info class in neither CopyConstructible nor CopyAssignable
//
//    Member functions
//
//    (constructor)           [deleted]   has neither default nor copy constructors                       (public member function)
//    (destructor)            [virtual]   derived objects are safe to delete through pointer-to-base      (virtual public member function)
//    operator=               [deleted]   can not be copy-assigned                                        (public member function)
//
//    operator==operator!=    checks whether the objects refer to the same type                           (public member function)
//    before                  checks whether the referred type precedes referred type of another type_index
//                            object in the implementation defined order, i.e. orders the referred types  (public member function)
//    hash_code               (C++11) returns a value which is identical for the same types               (public member function)
//    name                    implementation defined name of the type                                     (public member function)
//

#include <iostream>
#include <typeinfo>
#include <string>
#include <utility>

int main(){
    // member function before:
    // Returned 'true' if the referred type precedes type, referred to by
    // 'rhs' is the implementation's collation order. No guarantees are
    // given, in particular, the collation order can change between the
    // invocation of the same program.

    if( typeid(int).before(typeid(char)) ) endl(std::cout << "int goes before char in this implementation");
    else                                   endl(std::cout << "char goes before int in this implementation");
}