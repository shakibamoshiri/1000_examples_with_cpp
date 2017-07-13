/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Element access



/// 08_std::vector::back
/// definition in header < vector >
/**

Returns reference to the last element in the container.
Calling 'back' on an empty container is undefined.

Note: For a container C, the expression c.back(); is equivalent to
 { auto tmp = c.end(); --tmp; return *tmp; }

Return:

**/

#include <iostream>
#include <string>
#include <vector>

//#include <unistd.h>
template<typename V>
std::ostream& operator<<(std::ostream& out,const std::vector<V>& v){
    out.put('(');
    char comma = '\0';
    for ( const auto& ve : v){
        out << comma << ve;
        comma = ',';
    }
    return out << ')';
}

template < typename V>
using vec = std::vector<V>;



int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::vector<const char*> you {"How","are","you","today?"};
        std::cout<<"before any changing: "<<you<<std::endl;

        /// *& takes real address of you.back | taking address by ** is also correct
        /// but by * not and it is wrong, by * it become point to you.back
        /// why can we get a 'const char*' ?
        /// because of std::vector<const char*>
        /// My type is "const char*"
        /// if it was int, we can use int** or int* &

        const char* &back = you.back();
        /// also
        /// const char** back = &you.back();

        std::cout<<"const char* back: "<<back<<std::endl;
        /// also
        /// std::cout<<"const char* back: "<<*back<<std::endl;

        back = "TODAY?";

        /// also
        /// *back = "TODAY?";
        /// point to first letter is possible 'T'
        /// but trying to change it ('T') gives you segmentation fault :)

        std::cout<<"After changing by you.back and const char* : "<<you<<std::endl;


    }

}

/*
// vector_get_allocator.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;
   // The following lines declare objects that use the default allocator.
   vector<int> v1;
   vector<int, allocator<int> > v2 = vector<int, allocator<int> >(allocator<int>( )) ;

   // v3 will use the same allocator class as v1
   vector <int> v3( v1.get_allocator( ) );

   vector<int>::allocator_type xvec = v3.get_allocator( );
   // You can now call functions on the allocator class used by vec
}
*/

/*
// vector::get_allocator
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  int * p;
  unsigned int i;

  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);

  // construct values in-place on the array:
  for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);

  return 0;
}
*/
