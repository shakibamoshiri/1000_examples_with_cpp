/// Sequence containers : set
/// std::map
///
/// Member function.
/// 02_std::map::operator=
/// definition in header < map >

/**
map& operator=( const map& other):
map& operator=( cosnt map&& other);
map& operator=( std::initializer_list<value_type> ilist);

1.  Copy assignment.
2.  Move assignment.
3.  Initializer_list assignment.

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
        std::map<int,int> integer {
            {1,1}, {2,2}, {3,3}, {4,4}, {5,5}
        };
        std::map<int,int> integer_one;
        std::map<int,int> integer_two;

        std::cout<<"Initially           : ";
        getStuff(integer,integer_one,integer_two);

        /// copy assignment
        integer_one = integer;
        std::cout<<"copy assignment     : ";
        getStuff(integer,integer_one,integer_two);

        /// move assignment
        integer_two = (std::move(integer));
        std::cout<<"move assignment     : ";
        getStuff(integer,integer_one,integer_two);




    }


}
