/// Sequence containers : set
/// std::map
///
/// Non-member function
/// 29_std::map::operator ==,!=,<,>,<=,>= ( std::map )
/// definition in header < map >

/**
template< class Key, class T, class Compare, class Alloc >

bool operator==( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs );
	(1)
template< class Key, class T, class Compare, class Alloc >

bool operator!=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs );
	(2)
template< class Key, class T, class Compare, class Alloc >

bool operator<( const map<Key,T,Compare,Alloc>& lhs,
                const map<Key,T,Compare,Alloc>& rhs );
	(3)
template< class Key, class T, class Compare, class Alloc >

bool operator<=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs );
	(4)
template< class Key, class T, class Compare, class Alloc >

bool operator>( const map<Key,T,Compare,Alloc>& lhs,
                const map<Key,T,Compare,Alloc>& rhs );
	(5)
template< class Key, class T, class Compare, class Alloc >

bool operator>=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs );
	(6)


Compares the contents of two containers.
1-2) Checks if the contents of lhs and rhs are equal, that is,
whether lhs.size() == rhs.size() and each element in lhs compares
equal with the element in rhs at the same position.
3-6) Compares the contents of lhs and rhs lexicographically. The


Return value
1) true if the contents of the containers are equal, false otherwise
2) true if the contents of the containers are not equal, false otherwise
3) true if the contents of the lhs are lexicographically less than the
    contents of rhs, false otherwise
4) true if the contents of the lhs are lexicographically less than or
    equal the contents of rhs, false otherwise
5) true if the contents of the lhs are lexicographically greater than
    the contents of rhs, false otherwise
6) true if the contents of the lhs are lexicographically greater than
    or equal the contents of rhs, false otherwise
**/


//#include <unistd.h>
#include <iostream>
#include <string>
#include <map>

template<typename F,typename S>
std::ostream& operator<<(std::ostream& out,const std::map<F,S>& mp ){
    out.put('(').put(' ');
    for ( const std::pair<F,S> t : mp ) /// std::map<F,S> t is not true.
        out<<t.first<<':'<<t.second<<' ';
    return out.put(')');
}
void getStuff(){
    std::cout.put('\n');
}
template<typename F,typename... L>
void getStuff (F first, L... list){
    std::cout<<first.size()<<' ';
    getStuff(list...);
}
int main(){


    { /// my sample

    }
    { /// en.reference.com
        std::map<int,int> i2i;
        i2i[1]=100;
        i2i[2]=200;
        i2i[3]=300;

        std::map<int,int> i2i2;
        i2i2[1]=100;
        i2i2[2]=200;
        i2i2[3]=300;

        std::map<int,int> i2i3;

        if ( i2i == i2i2 )
            std::cout<<"These container are equal"<<std::endl;

        if ( i2i != i2i3 )
            std::cout<<"This two container are not equal"<<std::endl;
    }


}
