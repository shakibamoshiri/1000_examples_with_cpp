/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 21_std::vector::insert
/// definition in header < vector >
/**
iterator insert ( iterator pos, const T& value);
iterator insert ( const_iterator pos, const T& value);
iterator insert ( const_iterator pos, T&& value);
void insert ( iterator pos, size_type count, const T& value);
iterator insert ( const_iterator pos, size_type count, const T& value);
template <class InputIt>
    void insert ( iterator pos, InputIt first, InputIt last);
template<class InputIt>
    iterator insert (const_iterator pos,InputIt first, InputIt last);
iterator insert ( const_iterator pos, std::initializer_list<T> ilist);

Insert element at the specified location in the container.

1,2)    insert 'value' before pos
3)      insert 'count' copies of the 'value' before 'pos'
4)      insert elements from range [first, last) before 'pos'
        This overload has the same effect as overload (3) if
        InputIt is an integral types. This overload only participated
        in overload resolution if 'InputIt' qualifies as 'InputIterator'
        to avoid ambiguity with the overload (3). The behavior is undefined
        if 'first' and 'last' are iterator into *this.
5)      inserts elements from initializer list 'ilist' before 'pos'

Causes reallocation if the new size() is greater then the old capacity()
.If the new size() is greater then capacity(), all iterators and reference
are invalidated. Otherwise, only the iterators and reference before the
insertion point remain valid. The past-the-end iterator is also invalidated.

Return:

**/


#include <iostream>
#include <vector>

//#include <unistd.h>
template<typename V>
std::ostream& operator<<(std::ostream& out,const std::vector<V>& v){
    out.put('(');
    char comma = '\0';
    for ( const auto& ve : v){
        out << comma << ve;
        comma = ',';
    }
    return out << ')';
}

template < typename V>
using vec = std::vector<V>;

template <typename T>
void print_vector(const std::vector<T>& v){
    for (auto& x : v ){
        std::cout<<'-'<<x;
    }
    std::cout<<std::endl;
}
int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::vector<int> v(3,100);
        print_vector(v);

        auto it = v.begin();
        it = v.insert(it,200);
        print_vector(v); /// 200 100 100 100

        v.insert(it,2,399);
        print_vector(v); /// 399 399 200 100 100 100

        /// "it" no longer is valid, get a new one.
        it = v.begin(); /// it -> 399

        std::vector<int> v2(2,400);
        v.insert(it+2, v2.begin(),v2.end());
        print_vector(v);

        int arr[] = {888,889,900};
        v.insert(v.begin(), arr,arr+3);
        print_vector(v);






    }

}
