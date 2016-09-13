/// Sequence containers : set
/// std::set
///
/// Observes
/// 25_std::set::operator comparison
/// definition in header < set >

/**
template< class Key, class Compare, class Alloc >

bool operator==( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs );
	(1)
template< class Key, class Compare, class Alloc >

bool operator!=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs );
	(2)
template< class Key, class Compare, class Alloc >

bool operator<( const set<Key,Compare,Alloc>& lhs,
                const set<Key,Compare,Alloc>& rhs );
	(3)
template< class Key, class Compare, class Alloc >

bool operator<=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs );
	(4)
template< class Key, class Compare, class Alloc >

bool operator>( const set<Key,Compare,Alloc>& lhs,
                const set<Key,Compare,Alloc>& rhs );
	(5)
template< class Key, class Compare, class Alloc >

bool operator>=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs );
	(6)

Compares the contents of the containers.
1,2)    Checks if the contents of 'lhs' and 'rsh' are equal
3 to 6) Compares the contents of 'rhs' and 'lhs' lexicographically.

Return value
1) true if the contents of the containers are equal, false otherwise
2) true if the contents of the containers are not equal, false otherwise
3) true if the contents of the lhs are lexicographically less than the contents of rhs, false otherwise
4) true if the contents of the lhs are lexicographically less than or equal the contents of rhs, false otherwise
5) true if the contents of the lhs are lexicographically greater than the contents of rhs, false otherwise
6) true if the contents of the lhs are lexicographically greater than or equal the contents of rhs, false otherwise
**/


//#include <unistd.h>
#include <iostream>
#include <string>
#include <set>


/// helper function for printing pairs
template<class CH,class TR,class A,class B>
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out,std::pair<A, B>& pair){
    return out <<'('<<pair.first<<','<<pair.second<<')';
}

/// helper function for printing containers
template<class CH, class TR, class CON>
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out, std::set<CON>& container){
    out<<'{'<<*container.begin();
    for ( auto it = ++(container.begin());it != container.end();++it)
        out<<','<<*it;
    return out<<'}';
}

int main(){


    { /// my sample

    }
    { /// en.reference.com
        std::set<const char*> she{"she"};
        std::set<const char*> Marry{"she"};
        std::set<const char*> he{"he"};

        std::boolalpha(std::cout);

        bool result = she == Marry;
        std::cout<<result<<std::endl;

        /// or
        std::cout<<(she == Marry)<<std::endl;

        std::cout<<(she != he)<<std::endl;

    }


}
