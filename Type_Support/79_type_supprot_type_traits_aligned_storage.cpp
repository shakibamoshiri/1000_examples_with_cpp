
/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Miscellaneous Transformations (in header <type_traits>
    > aligned_storage           defines the type suitable for use as uninitialized storage for type of given size
    > aligned_union             defines the type suitable for use as uninitialized storage for all given types
    > decay                     applies type transformations as when passing a function argument by value
    > enable_if                 hides a function overload or template specialization based on compile-time boolean
    > conditional               chooses one type of another based on compile-type boolean
    > common_type               deduces the result type of mixed-mode arithmetic expression
    > underlying_type           obtains the underlying integer type for a given enumeration type
    > result_of                 deduces the return type of a function call expression
    > void_t                    void variadic alias template

*/
/// std::aligned_storage
// template<std::size_t Len, std::size_t Align> struct alinged_storage {}
//
// Provides the member typedef type, which is a POD Type suitable for use as
// uninitialized storage for any object whose size at most 'Len' and whose
// alignment requirement is a divisor of 'Align'.
// The default value of 'Align' is the most stringent (the largest) alignment
// requirement for any object whose size is at most 'Len'. If the default value
// is not used, 'Align' must be the value of the alignof(T) for some type T. or
// the behavior is undefined.
// The behavior is undefined if Len == 0.



#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>

template<class T, std::size_t N> class static_vector {
private:

    // property aligned uninitialized storage for N T's
    typename std::aligned_storage<sizeof(T), alignof(T)>::type data[N];
    std::size_t m_size = 0;

public:
    // create an object in aligned storage
    template<typename ...ARGS> void emplace_back(ARGS&&... args){

        if(m_size >= N) throw std::bad_alloc(); // possible error handling

        new (data+m_size) T(std::forward<ARGS>(args)...);
        ++m_size;
    }

    // access an object in aligned storage
    const T& operator[]( std::size_t pos) const { return *reinterpret_cast<const T*>(data + pos); }

    // delete objects form aligned storage
    ~static_vector(){
        for( std::size_t pos = 0; pos < m_size; ++pos) reinterpret_cast<const T*>(data + pos) -> ~T();
    }
};

/// Example
// a primitive static vector class, demonstration creation access
// and destruction of objects in aligned storage

int main() {
    static_vector<std::string, 10> sv1;

    sv1.emplace_back(5,'@');
    sv1.emplace_back(10,'@');
    sv1.emplace_back(15,'@');

    std::cout << sv1[0] << '\n'
              << sv1[1] << '\n'
              << sv1[2] << std::endl;
}
