#include <iostream>
#include <list>

template<typename L>
std::ostream& operator<<(std::ostream& out,L& list){
    for ( auto p : list )
        out<<p<<'\n';
    return out;
}
template<typename L>
std::ostream& operator<<(std::ostream& out, std::list<L>& list){
    out.put('(');
    for ( auto p : list )
        out<<p;
    return out.put(')');
}
int main(int argc,const char** argv){
    std::list<int> one{1,2,3,4,5};
    std::cout<<one<<std::endl;
}
