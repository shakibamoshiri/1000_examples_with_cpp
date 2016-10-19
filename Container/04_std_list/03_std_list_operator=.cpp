/// Sequence containers : list
/// std::list
///
/// Member function:
/// 03_std::list::operator=
/// definition in header < list >

/**
list& operator= (const list& other );
list& operator= (const list&& other);
list& operator= ( std::initializer_list<T> ilist);

Replace the contents of the container.

First:   copy assignment
Second:  move assignment
Last:    replace the contents with those identified by initializer_list ilist

return:
*this

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
        std::list<int> i1 {1,2,3,6,7,7};
        std::list<int> i2;
        std::list<int> i3;

        std::cout<<"initially               : ";
        getSize(i1,i2,i3);

        /// copy assignment
        i2 = i1;
        std::cout<<"After assignment        : ";
        getSize(i1,i2,i3);

        /// move assignment moves data from i1 to i3
        /// modifying both i1 and i3
        i3 = std::move(i1);
        std::cout<<"After move-assignment   : ";
        getSize(i1,i2,i3);
    }

}
/* out put */
/*

*/
