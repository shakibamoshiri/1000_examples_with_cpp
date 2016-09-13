/// Sequence containers : list
/// std::list
///
/// Iterators
/// 10_std::list::reverse_begin_and_constant_reverse_begin
/// definition in header < list >

/**
reverse_iterator rbeing();
const_reverse_iterator rbeging() const;
const_reverse_iterator crbegin() const;

Returns a reverse iterator to the first element of the reversed container.
It corresponds to the last element of the non-reversed container.

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
void getBack(){
    std::cout<<std::endl;
}
template<typename F,typename... L>
void getBack (F first,L... lists){
    std::cout<<first.back()<<' ';
    getBack(lists...);
}

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::list<const char*> you {"How","are","you","today?"};

        /// rbegin point to last element, "today?"
        std::cout<<*you.rbegin()<<std::endl;

        *you.rbegin() = "?yadot"; // okay

        std::cout<<*you.rbegin()<<std::endl;

        /// this is wrong:
        // *you.crbegin()  = "anything";
    }

}
/* out put */
/*
*/
