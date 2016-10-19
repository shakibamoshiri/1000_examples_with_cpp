/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 27_std::list::merge
/// definition in header < list >

/**
void merge ( list& other );
void merge ( list&& other );

template<class Compare>
    void merge ( list& other, Compare comp );
template<class Compare>
    void merge ( list&& other, Compare comp );

Merges two sorted lists into one. The lists should be sorted into ascending order.
No element are copies. The container 'other' become empty after the operation.
The function does nothing if 'this'==&other. If get_allocator() != other.get_allocator()
, the behavior is undefined. No iterators or references become invalidated, expect that
the iterators of moved elements now refer into *this, not into 'other'. The first version
uses operator< to compare the element, the second version uses the given comparison function comp.

**/


#include <iostream>
#include <list>
#include <string>
#include <iomanip>
//#include <unistd.h>
class Phone {
private:
    const char* name;
    const int age;
protected:
public:
    Phone() : name(""), age(0)
    {}
    Phone(const char* nameTemp,const int ageTemp)
        :name(nameTemp),age(ageTemp) {

        }
    friend std::ostream& operator<<(std::ostream& out,const Phone* objectTemp ){
        std::cout<<objectTemp->name<<' '<<objectTemp->age;
        return out;
    }
};
template < typename L>

std::ostream& operator<<(std::ostream& out, const std::list<L>& listTemp){
    out.put('{');
    out.put('\n');
    char camma = ' ';
    for ( const L l : listTemp ){
        out<< camma << l;
        /// for class boy must use &
         //out<< camma << &l;
        camma=',';
    }
    out.put('\n');
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
        std::list<int> one {1,4,0,3,9,8};
        std::list<int> two {2,5,7,6};

        /// first we should sort lists
        one.sort();
        two.sort();
        std::cout<<one<<std::endl;
        std::cout<<two<<std::endl;

        /// one + two
        one.merge(two);

        /// it sorted.
        std::cout<<one<<std::endl;
    }

}
/* out put */
/*


*/
