/// Sequence containers : list
/// std::list
///
/// Element access
/// 07_std::list::back
/// definition in header < list >

/**
reference back();
const_reference back() const;

Return reference to the last element in the container.
Calling 'back' on an empty container is undefined. <-------
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
        std::list<int> one {1,2,3};
        std::list<int> two {2,3,4};
        std::list<int> three {3,4,5};
        getBack(one,two,three); /// output: 3  4  5

        std::list<int> withOutBack;
        /// this container has no back, so using back of it is undefined.
        /// The act of below is wrong
        /// std::cout<<withOutBack.back()<<std::endl;

        /// using reference feature to change the last element.
        one.back() = 33;
        std::cout<<one<<std::endl; /// output : {1,2,33}
    }

}
/* out put */
/*
*/
