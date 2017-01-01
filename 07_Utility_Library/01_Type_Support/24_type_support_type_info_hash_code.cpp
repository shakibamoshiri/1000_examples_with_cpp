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
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>

struct A { virtual ~A() {} };

struct B : A {};

struct C : A {};

using TypeinfoRef = std::reference_wrapper<const std::type_info>;

struct Hasher {
    std::size_t operator()( TypeinfoRef code) const { return code.get().hash_code(); }
};

struct EqualTo {
    bool operator()(TypeinfoRef lhs, TypeinfoRef rhs) const { return lhs.get() == rhs.get(); }
};

int main(){
    /// std::size_t hash_code const;
    // Returns an unspecified value, which is identical for the type_info
    // object referring to the same type. No order guarantees are given.
    // For example, the same value may be returned for different types.
    // The value can also change between invocation of the same program.

    std::unordered_map<TypeinfoRef, std::string, Hasher, EqualTo> type_names;

    type_names[typeid(int)] = "int";
    type_names[typeid(double)] = "double";
    type_names[typeid(A)] = "A";
    type_names[typeid(B)] = "B";
    type_names[typeid(C)] = "C";

    int i; double d; A a;

    // note that we are storing pointer to type A
    std::unique_ptr<A> b(new B);
    std::unique_ptr<A> c(new C);

    endl( std::cout << "i is:\t" << type_names[typeid(i)] );
    endl( std::cout << "d is:\t" << type_names[typeid(d)] );
    endl( std::cout << "a is:\t" << type_names[typeid(a)] );
    endl( std::cout << "b is:\t" << type_names[typeid(*b)] );
    endl( std::cout << "c is:\t" << type_names[typeid(*c)] );

}