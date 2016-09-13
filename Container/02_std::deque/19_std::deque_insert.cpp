/// Sequence containers : deque
/// capacity

/// 19_std::deque::insert
/// definition in header < deque >

/**
iterator insert ( iterator pos, const T& value);
iterator insert ( const_iterator pos,const T& value);
iterator insert ( const_iterator pos, T&& value);
void insert ( iterator pos, size_type count, const T& value);
iterator insert ( const_iterator pos, size_type count, const T& value);
template < class InputIt >
    void insert ( iterator pos, InputIt first, Input last);
template < class InputIt >
    iterator insert (const_iterator pos, InputIt first, InputIt last);
iterator insert ( const_iterator pos, std::initializer_list<T> ilist);

Insert element at the specified location in the container.

1,2)    Insert 'value' before 'pos'
3)      Insert 'count' copies of the 'value' before 'pos'
4)      Insert element form range [first, last) before 'pos'. This overload
        has the same effect as overload 3 if 'InputIt' is an integral type.
        This overload only participates in overload resolution if 'InputIt'
        qualifies as 'InputIterator', to avoid ambiguity with the overload 3.
5)      Insert elements from initializer list 'ilist' before 'pos'

All iterators, including the past-the-end iterator, are invalidated. References
are invalidated too, unless pos == beign() or pos == end() in which cae they are
not invalidated.

Return:

**/

#include <iostream>
#include <array>
#include <deque>

//#include <unistd.h>

template<typename ALL_TYPE>
std::ostream& operator<<(std::ostream& out, std::deque<ALL_TYPE>& de){
    out.put('[');

    char ch = '\0';
    for ( const auto& t : de ){
        out<<ch<<t;
        ch = ',';
    }
    out.put(']');
    return out;
}
template<typename ALL_TYPE>
std::ostream& operator<<(std::ostream& out, const std::deque<ALL_TYPE>& de){
    out.put('[');

    char ch = '\0';
    for ( const auto& t : de ){
        out<<ch<<t;
        ch = ',';
    }
    out.put(']');
    return out;
}


template < typename D>
using ded = std::deque<D>;

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::deque<const char*> you {"How","you","today?"};
        std::deque<const char*>::iterator deit = you.begin();
        deit++;
        you.insert(deit,"are");
        std::cout<<you<<std::endl;
    }

}
/**


// deque_insert.cpp
// compile with: /EHsc
#include <deque>
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    deque <int> c1, c2;
    deque <int>::iterator Iter;

    c1.push_back(10);
    c1.push_back(20);
    c1.push_back(30);
    c2.push_back(40);
    c2.push_back(50);
    c2.push_back(60);

    cout << "[ c1 = ";
    for (auto c1_iter : c1)
        cout << c1_iter << " ";
    cout << "]" << endl;

    Iter = c1.begin();
    Iter++;
    c1.insert(Iter, 100);
    cout << "[ c1 = ";
    for (auto c1_iter : c1)
        cout << c1_iter << " ";
    cout << "]" << endl;

    Iter = c1.begin();
    Iter++;
    Iter++;
    c1.insert(Iter, 2, 200);

    cout << "[ c1 = ";
    for (auto c1_iter : c1)
        cout << c1_iter << " ";
    cout << "]" << endl;

    c1.insert(++c1.begin(), c2.begin(), --c2.end());

    cout << "[ c1 = ";
    for (auto c1_iter : c1)
        cout << c1_iter << " ";
    cout << "]" << endl;

    // initialize a deque of strings by moving
    deque < string > c3;
    string str("a");

    c3.insert(c3.begin(), move(str));
    cout << "Moved first element: " << c3.front() << endl;

    c1.insert(c1.end(), { 70, 80, 90 });
    for (auto c1_iter : c1)
        cout << c1_iter << " ";
    cout << endl;
}// deque_insert.cpp
// compile with: /EHsc
#include <deque>
#include <iostream>
#include <string>

int main( )
{
    using namespace std;
    deque <int> c1, c2;
    deque <int>::iterator Iter;

    c1.push_back( 10 );
    c1.push_back( 20 );
    c1.push_back( 30 );
    c2.push_back( 40 );
    c2.push_back( 50 );
    c2.push_back( 60 );

    cout << "[ c1 = ";
    for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )
        cout << *Iter << " ";
    cout << "]" << endl;

    Iter = c1.begin( );
    Iter++;
    c1.insert( Iter, 100 );
    cout << "[ c1 = ";
    for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )
        cout << *Iter << " ";
    cout << "]" << endl;

    Iter = c1.begin( );
    Iter++;
    Iter++;
    c1.insert( Iter, 2, 200 );

    cout << "[ c1 = ";
    for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )
        cout << *Iter << " ";
    cout << "]" << endl;

    c1.insert( ++c1.begin( ), c2.begin( ),--c2.end( ) );

    cout << "[ c1 = ";
    for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )
        cout << *Iter << " ";
    cout << "]" << endl;

// initialize a deque of strings by moving
    deque < string > c3;
    string str("a");

    c3.insert( c3.begin(), move( str ) );
    cout << "Moved first element: " << c3.front( ) << endl;
}

Output

[ c1 = 10 20 30 ]
[ c1 = 10 100 20 30 ]
[ c1 = 10 100 200 200 20 30 ]
[ c1 = 10 40 50 100 200 200 20 30 ]
Moved first element: a
10 40 50 100 200 200 20 30 70 80 90


**/
