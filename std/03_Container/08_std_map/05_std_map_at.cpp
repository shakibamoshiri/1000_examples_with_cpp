/// Sequence containers : set
/// std::map
///
/// Access.
/// 05_std::map::at
/// definition in header < map >

/**
T& at( const Key& key );
const T& at ( const Key& key ) const;

Returns a reference to the mapped value of the element with key
equivalent to key. If no such element exists, an exception of type
std::out_of_range is thrown.

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
        std::map<int,int> i2i{
            {10,1}, {20,2}, {30,3}
        };

        std::cout<<i2i.at(20)<<std::endl;
        i2i.at(20) = 200;
        std::cout<<i2i<<std::endl;
    }


}
/**
// map::at
#include <iostream>
#include <string>
#include <map>

int main ()
{
  std::map<std::string,int> mymap = {
                { "alpha", 0 },
                { "beta", 0 },
                { "gamma", 0 } };

  mymap.at("alpha") = 10;
  mymap.at("beta") = 20;
  mymap.at("gamma") = 30;

  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << '\n';
  }

  return 0;
}
**/
