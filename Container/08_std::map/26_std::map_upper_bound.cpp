/// Sequence containers : set
/// std::map
///
/// Lookup
/// 26_std::map::upper_bound
/// definition in header < map >

/**
iterator upper_bound( const Key& key );               (1)
const_iterator upper_bound( const Key& key ) const;     (1)
template< class K >
iterator upper_bound( const K& x );                       	(2) 	(since C++14)
template< class K >
const_iterator upper_bound( const K& x ) const;             (2) 	(since C++14)

1) Returns an iterator pointing to the first element that is greater than key.
2) Returns an iterator pointing to the first element that compares greater to
    the value x. This overload only participates in overload resolution if the
    qualified-id Compare::is_transparent is valid and denotes a type. They allow
    calling this function without constructing an instance of Key.
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
        i2i.emplace(1,2);
        i2i.emplace(2,3);
        i2i.emplace(3,4);
        i2i.emplace(4,5);
        i2i.emplace(5,6);

        std::cout<<i2i<<std::endl;

        std::map<int,int>::iterator itLower,itUpper;

        itLower = i2i.lower_bound(2);
        itUpper = i2i.upper_bound(3);

        std::cout<<itLower->first<<':'<<itLower->second<<std::endl;
        std::cout<<itUpper->first<<':'<<itUpper->second<<std::endl;

        i2i.erase(itLower,++itUpper); /// form 2:3 to itself itUpper

        std::cout<<i2i<<std::endl;
    }


}
/**
// map_upper_bound.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   map <int, int> m1;
   map <int, int> :: const_iterator m1_AcIter, m1_RcIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_RcIter = m1.upper_bound( 2 );
   cout << "The first element of map m1 with a key "
        << "greater than 2 is: "
        << m1_RcIter -> second << "." << endl;

   // If no match is found for the key, end is returned
   m1_RcIter = m1. upper_bound ( 4 );

   if ( m1_RcIter == m1.end( ) )
      cout << "The map m1 doesn't have an element "
           << "with a key greater than 4." << endl;
   else
      cout << "The element of map m1 with a key > 4 is: "
           << m1_RcIter -> second << "." << endl;

   // The element at a specific location in the map can be found
   // using a dereferenced iterator addressing the location
   m1_AcIter = m1.begin( );
   m1_RcIter = m1. upper_bound ( m1_AcIter -> first );
   cout << "The 1st element of m1 with a key greater than\n"
        << "that of the initial element of m1 is: "
        << m1_RcIter -> second << "." << endl;
}
**/
