/// Sequence containers : list
/// std::list
///
/// Iterators
/// 11_std::list::reverse_end_and_constant_reverse_end
/// definition in header < list >

/**
reverse_iterator end();
const_reverse_iterator rend() const;
const_reverse_iterator crend() const;

Returns a reverse iterator to the element  following the last element of the
reverse container. It corresponds to the element preceding the first element
of the non-reverse container. This element atcs as a placeholder, attempting
to access it results in undefined behavior.

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

        /// the similar of end, with rend,we have to minus-minus it before using;
        std::cout<<*(--you.rend())<<std::endl; /// point to How
        std::cout<<*--you.rend()<<std::endl; /// point to How

        const char* &it = *--you.rend();
        it = "hhh ooo www";
        std::cout<<it<<std::endl;
        std::cout<<you<<std::endl;
    }

}
/* out put */
/*
*/
