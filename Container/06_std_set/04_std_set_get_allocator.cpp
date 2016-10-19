/// Sequence containers : set
/// std::set
///
/// Member Function
/// 04_std::set::get_allocator
/// definition in header < set >

/**
allocator_type get_allocator() const;
Returns the allocator associated with the container.

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
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out, CON& container){
    out<<'{'<<*container.begin();
    for ( auto it = ++(container.begin());it != container.end();++it)
        out<<','<<*it;
    return out<<'}';
}
template<class CH, class TR, class CON>
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out, std::set<CON>& container){
    out<<'{'<<*container.begin();
    for ( auto it = ++(container.begin());it != container.end();++it)
        out<<','<<*it;
    return out<<'}';
}
void printStuff(){
    std::cout<<std::endl;
}
template<typename F, typename... L>
void printStuff(F first,L... list){
    std::cout<<' ';
    std::cout<<first.size();
    printStuff(list...);
}
int main(){


    { /// my sample
    }
    { /// en.reference.com
        std::set<int>::allocator_type firstInt;
        std::set<char>::allocator_type secondChar;
        std::set<double>::allocator_type thirdDouble;

        std::set<int> one;
        firstInt = one.get_allocator();
        std::set<char> two;
        secondChar = two.get_allocator();

        /// I do not know, what is it :(
        if ( secondChar == firstInt )
            std::cout<<"Okay"<<std::endl;


        /// another sample,like cplusplus.com
        std::set<int> interger;
        int* p;
        p = interger.get_allocator().allocate(5); // allocate 5 element

        int i=6;
        while(--i){
            *p = i*10;
            p++;
        }
        p-=5;

        i=5;
        while(i--){
            std::cout<<*p<<std::endl;
            p++;
        }
        p-=5;

        interger.get_allocator().deallocate(p,5);

    }

}

/* msdn.microsoft.com

// set_get_allocator.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int>::allocator_type s1_Alloc;
   set <int>::allocator_type s2_Alloc;
   set <double>::allocator_type s3_Alloc;
   set <int>::allocator_type s4_Alloc;

   // The following lines declare objects
   // that use the default allocator.
   set <int> s1;
   set <int, allocator<int> > s2;
   set <double, allocator<double> > s3;

   s1_Alloc = s1.get_allocator( );
   s2_Alloc = s2.get_allocator( );
   s3_Alloc = s3.get_allocator( );

   cout << "The number of integers that can be allocated"
        << endl << "before free memory is exhausted: "
        << s2.max_size( ) << "." << endl;

   cout << "\nThe number of doubles that can be allocated"
        << endl << "before free memory is exhausted: "
        << s3.max_size( ) <<  "." << endl;

   // The following line creates a set s4
   // with the allocator of multiset s1.
   set <int> s4( less<int>( ), s1_Alloc );

   s4_Alloc = s4.get_allocator( );

   // Two allocators are interchangeable if
   // storage allocated from each can be
   // deallocated by the other
   if( s1_Alloc == s4_Alloc )
   {
      cout << "\nThe allocators are interchangeable."
           << endl;
   }
   else
   {
      cout << "\nThe allocators are not interchangeable."
           << endl;
   }
}


    { /// cplusplus.com sample
        // set::get_allocator

          std::set<int> myset;
          int * p;
          unsigned int i;

          // allocate an array of 5 elements using myset's allocator:
          p=myset.get_allocator().allocate(5);

          // assign some values to array
          for (i=0; i<5; i++) p[i]=(i+1)*10;

          std::cout << "The allocated array contains:";
          for (i=0; i<5; i++) std::cout << ' ' << p[i];
          std::cout << '\n';

          myset.get_allocator().deallocate(p,5);

    }
*/













