/// Sequence containers : deque

/// 02_std::deque::operator =
/// definition in header < deque >

/**
deque& operator=( const deque& other );
deque& operator=( deque && other );
deque& operator=(std::initializer_list<T> ilist );

Replaces the contents of the container.

1)  copy assignment operator. Replaces the contents with a copy of
    the contents of 'other'. If std::allocator_traits<allocator_type>
    ::propagate_on_container_copy_assignment() is true. the target
    allocator is replaced by a copy of the source allocator. If the
    target source allocator do not compare equal, the target (*this )
    allocator is used to deallocator the memory, the 'other's' allocator
    is used to allocator it before copying the element (since c++11 )
2)  Move assignment operator. Replace the contents with those of 'other'
    using move semantics ( i.e. the date in 'other' is moved form
    'other' into this container ). 'other'is in a valid but unspecified
    state afterwards. If std::allocator_traits<allocator_type>::propagate
    _on_container_move_assignment() is true, the target allocator is
    replaced by a copy of the source allocator, If it is false and the
    source target allocators do not compare equal, the target cannot
    take ownership of the source memory and must move-assign each element
    individually allocating additional memory using its own allocator as needed.
3)  Replaces the contents with those identified by initializer_list 'ilist'
**/

#include <iostream>
#include <string>
#include <deque>

//#include <unistd.h>

template<typename ALL_TYPE>
std::ostream& operator<<(std::ostream& out, std::deque<ALL_TYPE>& de){
    out.put('[');

    char ch = '\0';
    for ( const auto& t : de ){
        out<<ch<<t;
        ch = ',';
    }
    out.put(']');
    return out;
}
typedef const std::deque<int>& deref;
void display_sizes(deref n1,deref n2, deref n3){
    std::cout<<"number one: "<<n1.size()
             <<" number two: "<<n2.size()
             <<" Number three: "<<n3.size() <<std::endl;
}

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::deque<int> num1 {1,2,3,4,5};
        std::deque<int> num2;
        std::deque<int> num3;

        display_sizes(num1,num2,num3);
        std::cout<<num1<<std::endl;
        num2 = num1;
        display_sizes(num1,num2,num3);
        std::cout<<num2<<std::endl;
        num3 = std::move(num1);
        display_sizes(num1,num2,num3);
    }

}
