/// Sequence containers : list
/// std::list
///
/// Member function:
/// 05_std::list::get_allocator
/// definition in header < list >

/**
allocator_type get_allocator() const;

Returns the allocator associated with the container.

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
        /// This sample is form the cpluscplus.com not en.reference.com and I did not understand ):
        std::list<int> mylist;
        int * p;

        // allocate an array of 5 elements using mylist's allocator:
        p=mylist.get_allocator().allocate(5);

        // assign some values to array
        for (int i=0; i<5; ++i) p[i]=i;

        std::cout << "The allocated array contains:";
        for (int i=0; i<5; ++i) std::cout << ' ' << p[i];
        std::cout << '\n';

        mylist.get_allocator().deallocate(p,5);


        /// the list is empty but why ???
        std::cout<<mylist<<std::endl;
    }

}
/* out put */
/*
// list::get_allocator
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  int * p;

  // allocate an array of 5 elements using mylist's allocator:
  p=mylist.get_allocator().allocate(5);

  // assign some values to array
  for (int i=0; i<5; ++i) p[i]=i;

  std::cout << "The allocated array contains:";
  for (int i=0; i<5; ++i) std::cout << ' ' << p[i];
  std::cout << '\n';

  mylist.get_allocator().deallocate(p,5);


  // list_get_allocator.cpp
// compile with: /EHsc
#include <list>
#include <iostream>

int main( )
{
   using namespace std;
   // The following lines declare objects
   // that use the default allocator.
   list <int> c1;
   list <int, allocator<int> > c2 = list <int, allocator<int> >( allocator<int>( ) );

   // c3 will use the same allocator class as c1
   list <int> c3( c1.get_allocator( ) );

   list<int>::allocator_type xlst = c1.get_allocator( );
   // You can now call functions on the allocator class used by c1
}

*/
