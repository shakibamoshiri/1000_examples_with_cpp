/// Sequence containers : set
/// std::set
///
/// Modifier
/// 15_std::set::emplace_hint
/// definition in header < set >

/**
template<class... Args>
iterator emplace_hint ( const_iterator hint, Args&&... args);

Inserts a new element into the container as close as possible to the
position just before 'hint'. The element in constructed in-place,
i.e. no copy or move operations are performed.
The constructor of the element is called with exactly the same argument
as supplies to the function, forwarded with std::forward<Args>(args)...

No iterator or reference are invalidated.


**/


//#include <unistd.h>
#include <iostream>
#include <string>
#include <set>
#include <chrono>
#include <functional>
#include <iomanip>

/// helper function for printing pairs
template<class CH,class TR,class A,class B>
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out,std::pair<A, B>& pair){
    return out <<'('<<pair.first<<','<<pair.second<<')';
}
/*
/// helper function for printing containers
template<class CH, class TR, class CON>
std::basic_ostream<CH, TR>& operator<<(std::basic_ostream<CH, TR>& out, CON& container){
    out<<'{'<<*container.begin();
    for ( auto it = ++(container.begin());it != container.end();++it)
        out<<','<<*it;
    return out<<'}';
}
*/
void printStuff(){
    std::cout<<std::endl;
}
template<typename F, typename... L>
void printStuff(F first,L... list){
    std::cout<<' ';
    std::cout<<first.size();
    printStuff(list...);
}
const int nof_operations = 100500;

int set_emplace(){
    std::set<int> set;
    for (int i=0; i<nof_operations;++i)
        set.emplace(i);
    return set.size();
}
int set_emplace_hint(){
    std::set<int> set;
    auto it = set.begin();
    for (int i=0;i<nof_operations;i++){
        set.emplace_hint(it,i);
    }
    return set.size();
}
int set_emplace_hint_wrong(){
    std::set<int> set;
    auto it = set.begin();
    for (int i = nof_operations; i>0;i--){
        set.emplace_hint(it,i);
        it = set.end();
    }
    return set.size();
}
int set_emplace_hint_corrected(){
    std::set<int> set;
    auto it = set.begin();
    for ( int i = nof_operations;i > 0; i--){
        set.emplace_hint(it,i);
        it = set.begin();
    }
    return set.size();
}
int set_emplace_hint_closest(){
    std::set<int> set;
    auto it = set.begin();
    for (int i =0;i < nof_operations;i++){
        it = set.emplace_hint(it, i);
    }
    return set.size();
}
void timeIt(std::function<int()> set_test, std::string what = ""){
    auto start = std::chrono::system_clock::now();
    int setSize = set_test();
    auto stop = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> time = stop - start;
    if ( what.size() > 0 && setSize > 0){
        std::cout<<std::fixed<<std::setprecision(2)
                 <<time.count()<<" ms for "<<what<<std::endl;
    }
}
int main(){


    { /// my sample

    }
    { /// en.reference.com
        timeIt(set_emplace); /// stack warmup
        timeIt(set_emplace, "plain emplace");
        timeIt(set_emplace_hint, "emplace with correct hint");
        timeIt(set_emplace_hint_wrong, "emplace with wrong hint");
        timeIt(set_emplace_hint_corrected, "corrected emplace");
        timeIt(set_emplace_hint_closest, "emplace using returned iterator");

    }


}
