/// Sequence containers : list
/// std::list
///
/// Member function:
/// 02_std::list::assign
/// definition in header < list >

/**
void assign ( size_type count, const T& value);
template<calls InputIt>
    void assign ( InputIt first, InputIt last);
void assign (std::initializer_list<T> ilist);

Replaces the contents of the container.

1)  Replace the contents with 'count' copies of value 'value'
2)  Replaces the contents with copies of those in the range [first,last).
    This overload had the same effect as overload (1) if InputIt
    is an integral type. This overload only participates in overload
    resolution in InputIt satisfies InputIterator.
3)  Replaces the contents with the elements form the initializer_list 'list'

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
/// only print size of list member:
void getSize(){
    std::cout<<std::endl;
}
template<typename F,typename... L>
void getSize (F first,L... lists){
    std::cout<<first.size()<<' ';
    getSize(lists...);
}

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::list<char> characters;
        characters.assign(5,'A');
        std::cout<<characters<<std::endl;

        std::list<char> ch2;
        auto itch = characters.begin();

        /// + not overload for list
        /// ch2.assign(characters.begin(),characters.begin()+3);

        /// This sample is possible to be wrong:
        ch2.assign(*itch,*itch+3);
        std::cout<<ch2<<std::endl;


        std::initializer_list<char> c {'a','a','a','a'};
        std::list<char> ch3;
        ch3.assign(c);
        std::cout<<ch3<<std::endl;
    }

}
/* out put */
/*

*/
