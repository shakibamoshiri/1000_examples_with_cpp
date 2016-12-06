/// Sequence containers : set
/// std::map
///
/// Lookup
/// 24_std::map::equal_range
/// definition in header < map >

/**
std::pair<iterator,iterator> equal_range ( const Key& key );
std::pair<const_iterator,const_iterator> equal_range ( const Key& key )const;
template<class K>
std::pair<iterator,iterator> equal_range ( const K& x );
std::pair<const_iterator,const_iterator> equal_range ( const K& x )const;

Returns a range containing all elements with the given key in the container.
The range is defined by two iterator, one  pointing to the first element that
is not "less" than 'key' and another pointing to the first element "greater"
than 'key'. Alternatively, the first iterator may be obtained with lower_bound(),
and the second with upper_bound().
1,2     Compares key to the 'key'
3,4     Compares the key to the value 'x'.
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


        std::pair<std::map<int,int>::iterator ,std::map<int,int>::iterator > p;

        p = i2i.equal_range(2);
        std::cout<<"lower_bound point to: ";
        std::cout<<p.first->first<<':'<<p.first->second<<std::endl;

        std::cout<<"upper_bound point to: ";
        std::cout<<p.second->first<<':'<<p.second->second<<std::endl;
    }


}
/**
// map_equal_range.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   typedef map <int, int, less<int> > IntMap;
   IntMap m1;
   map <int, int> :: const_iterator m1_RcIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   pair <IntMap::const_iterator, IntMap::const_iterator> p1, p2;
   p1 = m1.equal_range( 2 );

   cout << "The lower bound of the element with "
        << "a key of 2 in the map m1 is: "
        << p1.first -> second << "." << endl;

   cout << "The upper bound of the element with "
        << "a key of 2 in the map m1 is: "
        << p1.second -> second << "." << endl;

   // Compare the upper_bound called directly
   m1_RcIter = m1.upper_bound( 2 );

   cout << "A direct call of upper_bound( 2 ) gives "
        << m1_RcIter -> second << "," << endl
        << " matching the 2nd element of the pair"
        << " returned by equal_range( 2 )." << endl;

   p2 = m1.equal_range( 4 );

   // If no match is found for the key,
   // both elements of the pair return end( )
   if ( ( p2.first == m1.end( ) ) && ( p2.second == m1.end( ) ) )
      cout << "The map m1 doesn't have an element "
           << "with a key less than 40." << endl;
   else
      cout << "The element of map m1 with a key >= 40 is: "
           << p2.first -> first << "." << endl;
}
**/
