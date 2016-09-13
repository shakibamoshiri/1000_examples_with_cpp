/// Sequence containers : set
/// std::map
///
/// Member function.
/// 01_std::map::map
/// definition in header < map >

/**
explicit map ( const Compare& comp = Compares(), const Allocator& alloc = Allocator() );
map() : map ( Compare() ) {}
explicit map ( const Compare& comp, const Allocator& alloc = Allocator() );
explicit map ( const Allocator& alloc );

template<class InputIterator>
map ( InputIterator first, InputIterator last , const Compare& comp = Compare() );
template<class InputIterator>
map ( InputIterator first, InputIterator last , const Allocator& alloc );

map ( const map& other );
map ( const map& other, const Allocator& alloc);

map ( const map&& other);
map ( const map&& other, const Allocator& alloc);

map ( std::initializer_list<value_type> init, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
map ( std::initializer_list<value_type> init, const Allocator& );

1.  Default constructor.
2.  Constructs the container with the contents of the range [first,last).
3.  Copy constructor.
4.  Move constructor.
5.  Constructs the container with the contents of the initializer list 'init'.
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
int main(){


    { /// my sample

    }
    { /// en.reference.com
        /// 1. default constructor
        std::map<std::string, int> m1;
        m1["something"] = 69;
        m1["anything"] = 199;
        m1["that thing"] = 50;
        std::cout<<m1<<std::endl;

        /// 2. range constructor
        typedef std::map<std::string, int> mapsi;
        mapsi iter ( m1.find("anything"), m1.end());
        std::cout<<iter<<std::endl;

        /// 3. copy constructor
        mapsi cp(m1);
        std::cout<<cp<<std::endl;

        ///4. move constructor
        mapsi mv(std::move(m1));
        std::cout<<mv<<std::endl;

        ///5. Initializer_list constructor
        const mapsi in {
            {"this",100},
            {"can",100},
            {"be",100},
            {"constant",100}
        };
        std::cout<<in<<std::endl;

    }


}
