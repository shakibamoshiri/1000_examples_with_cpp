/// Sequence containers : list
/// std::list
///
/// Member function:
/// 01_std::list::list
/// definition in header < list >

/**
explicit list( const Allocator& alloc = Allocator() );(until C++14)
list() : list( Allocator() ) {}
explicit list( const Allocator& alloc );(since C++14)            (2)
explicit list( size_type count,
               const T& value = T(),
               const Allocator& alloc = Allocator());(until C++11)
         list( size_type count,
               const T& value,
               const Allocator& alloc = Allocator());(since C++11)  (3)
explicit list( size_type count );(since C++11) (until C++14)
explicit list( size_type count, const Allocator& alloc = Allocator() );(since C++14)

template< class InputIt >
list( InputIt first, InputIt last,
      const Allocator& alloc = Allocator() );                    (4)

list( const list& other );                                       (5)
list( const list& other, const Allocator& alloc );               (5) 	(since C++11)

list( list&& other )                                             (6) 	(since C++11)
list( list&& other, const Allocator& alloc );                    (6) 	(since C++11)

list( std::initializer_list<T> init,
      const Allocator& alloc = Allocator() );                     (7) 	(since C++11)


Constructs  a new container from a variety of data sources, optionally using
a user supplied allocator 'alloc'
1)  Default constructor. Constructs an empty container.
2)  constructs the container with 'count' copies of element with value 'value'
3)  Constructs the container with 'count' default-inserted instances of T. No
    copies are made.
4)  Constructs the container with contents of the range [first,list). This
    constructor had the same effect as overloaded (2) if InputIt is an integral
    type. This overloaded only participates in overloaded resolution if InputIt
    satisfied InputIterator, to avoid ambiguity with the overload (2).
5)  Copy construct. Constructs the container with the copy of contents of 'other'.
    If 'alloc' is not provided, allocator is obtained by calling
    std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
6)  Move constructor. Constructs the container with the contents of 'other' using
    move semantics. If 'alloc' is not provided, allocator is obtained by move-construction
    form the allocator belonging to 'other'.
7)  Constructs the container with the contents of initializer_list 'init'.
**/


#include <iostream>
#include <list>
#include <string>
#include <iomanip>
//#include <unistd.h>
template < typename L>
std::ostream& operator<<(std::ostream& out, const std::list<L>& listTemp){
    out.put('{');
    char camma = '\0';
    for ( const L l : listTemp ){
        out<< camma << l;
        camma=',';
    }
    out.put('}');

    return out;
}



int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        /// c++11 initializer list syntax:
        std::list<std::string> w1 {"the", "frogurt","is","also","cursed"};
        std::cout<<"w1 = "<<w1<<std::endl;

        /// w2 == w1
        std::list<std::string> w2 ( w1.begin(),w1.end());
        std::cout<<"w2 = "<<w2<<std::endl;

        /// w3 == w1
        std::list<std::string> w3 ( w1 );
        std::cout<<"w3 = "<<w3<<std::endl;

        /// w4 is {"mo" "mo" "mo" "mo" "mo"}
        std::list<std::string> w4 (5,"mo");
        std::cout<<w4<<std::endl;

        /// more sample
        std::list<std::string> mv (std::list<std::string>{"this moved to mv"});
        std::cout<<"mv = "<<mv<<std::endl;

        /// move w1 to mv2
        std::list<std::string> mv2 (std::move(w1));
        std::cout<<"w1  = "<<w1<<std::endl;
        std::cout<<"mv2 = "<<mv2<<std::endl;


    }

}
/* out put */
/*

w1 = {the,frogurt,is,also,cursed}
w2 = {the,frogurt,is,also,cursed}
w3 = {the,frogurt,is,also,cursed}
{mo,mo,mo,mo,mo}
mv = {this moved to mv}
w1  = {}
mv2 = {the,frogurt,is,also,cursed}

Process returned 0 (0x0)   execution time : 0.016 s
Press ENTER to continue.

*/
