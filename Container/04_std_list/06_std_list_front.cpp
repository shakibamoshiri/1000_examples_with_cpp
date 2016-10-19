/// Sequence containers : list
/// std::list
///
/// Element access
/// 06_std::list::front
/// definition in header < list >

/**
reference front();
const_reference front() const;

Returns a reference to the first element in the container.
Calling 'front' on an empty container is undefined.
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
void getFront(){
    std::cout<<std::endl;
}
template<typename F,typename... L>
void getFront (F first,L... lists){
    std::cout<<first.back()<<' ';
    getFront(lists...);
}

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::list<int> one {1,2,3};
        std::list<int> two {2,3,4};
        std::list<int> three {3,4,5};
        getFront(one,two,three); /// output: 1 2 3

        std::list<int> withOutFront;
        /// this container has no back, so using back of it is undefined.
        /// The act of below is wrong
        /// std::cout<<withOutFront.front()<<std::endl;
    }

}
/* out put */
/*
*/
