/// Sequence containers : set
/// std::map
///
/// Modifier.
/// 15_std::map::insert
/// definition in header < map >

/**
std::pair<iterator,bool> insert ( const value_type& value);

template<class P>
std::pair<iterator,bool> insert ( P&& value);
std::pair<iterator,bool> insert ( value_type&& value)

iterator insert ( iterator hint, const value_type& value);
iterator insert ( const_iterator hint, const value_type& value);

template<class P>
iterator insert ( const_iterator hint,P&& value);
iterator insert ( const_iterator hint,value_type&& value);

template<class InputIt>
void insert ( InputIt first, InputIt last);

void insert ( std::initializer_list<value_type> ilist);

Inserts element(s) into the container, if the container does not already
contain an element with an equivalent key.
1,2)    Insert 'value'
3,4)    Insert 'value' in the position as close as possible
5)      Insert elements from range [first, last)
6)      Insert elements form initializer list 'ilist'

No iterator or reference are invalidated.
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
        std::map<char,const char*> ch{
           /// if the container does not already contain
           /// an element with an equivalent key.
           {'f',"testing key"}
        };
        std::cout<<ch<<std::endl;
        ch.insert(std::pair<char,const char*>('a',"how"));
        ch.insert(std::pair<char,const char*>('b',"are"));
        ch.insert(std::pair<char,const char*>('c',"you"));
        ch.insert(std::pair<char,const char*>('d',"today ?"));
        ch.insert(std::pair<char,const char*>('e',"goodbye :)"));
        /// testing key
        ch.insert(std::pair<char,const char*>('f',"hey, key 'f' was changed"));

        std::cout<<ch<<std::endl;

        ch.clear();
        ch.insert(ch.begin(),std::pair<char,const char*>('A',"insert begin"));
        ch.insert(ch.end(),std::pair<char,const char*>('Z',"insert end"));

        std::cout<<ch<<std::endl;

        std::map<char,const char*> ch2;
        ch2.insert(ch.begin(),ch.end());
        std::cout<<"ch2 = "<<ch2<<std::endl;

        ch.clear();
        ch2.clear();
        ch.insert({'i',"Initializer list"});
        std::cout<<ch<<std::endl;
    }


}
/**
// map::insert (C++98)
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  std::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
**/
/**
// map_insert.cpp
// compile with: /EHsc
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>  // make_pair()

using namespace std;

template <typename M> void print(const M& m) {
    cout << m.size() << " elements: ";

    for (const auto& p : m) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    cout << endl;
}

int main()
{

    // insert single values
    map<int, int> m1;
    // call insert(const value_type&) version
    m1.insert({ 1, 10 });
    // call insert(ValTy&&) version
    m1.insert(make_pair(2, 20));

    cout << "The original key and mapped values of m1 are:" << endl;
    print(m1);

    // intentionally attempt a duplicate, single element
    auto ret = m1.insert(make_pair(1, 111));
    if (!ret.second){
        auto pr = *ret.first;
        cout << "Insert failed, element with key value 1 already exists."
            << endl << "  The existing element is (" << pr.first << ", " << pr.second << ")"
            << endl;
    }
    else{
        cout << "The modified key and mapped values of m1 are:" << endl;
        print(m1);
    }
    cout << endl;

    // single element, with hint
    m1.insert(m1.end(), make_pair(3, 30));
    cout << "The modified key and mapped values of m1 are:" << endl;
    print(m1);
    cout << endl;


    // The templatized version inserting a jumbled range
    map<int, int> m2;
    vector<pair<int, int>> v;
    v.push_back(make_pair(43, 294));
    v.push_back(make_pair(41, 262));
    v.push_back(make_pair(45, 330));
    v.push_back(make_pair(42, 277));
    v.push_back(make_pair(44, 311));

    cout << "Inserting the following vector data into m2:" << endl;
    print(v);

    m2.insert(v.begin(), v.end());

    cout << "The modified key and mapped values of m2 are:" << endl;
    print(m2);
    cout << endl;

    // The templatized versions move-constructing elements
    map<int, string>  m3;
    pair<int, string> ip1(475, "blue"), ip2(510, "green");

    // single element
    m3.insert(move(ip1));
    cout << "After the first move insertion, m3 contains:" << endl;
    print(m3);

    // single element with hint
    m3.insert(m3.end(), move(ip2));
    cout << "After the second move insertion, m3 contains:" << endl;
    print(m3);
    cout << endl;

    map<int, int> m4;
    // Insert the elements from an initializer_list
    m4.insert({ { 4, 44 }, { 2, 22 }, { 3, 33 }, { 1, 11 }, { 5, 55 } });
    cout << "After initializer_list insertion, m4 contains:" << endl;
    print(m4);
    cout << endl;
}

**/
