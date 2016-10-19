/*
Algorithm Library C++
The algorithm library defines functions for a variety of purposes.
(e.g. searching, sorting, counting, manipulating ) that operate on
range of elements. Note that a range is defined as [ first, last )
where last refers to the element past the last element to inspect
or modify.
------------------------------------------------------------------
You can read the original implementation in:
stl_algobase.h and stl_algo.h and algorithmfwd.h
------------------------------------------------------------------
Defined in header <algorithm>

Sorting Operation

    is_sorted           checks whether a range is sorted into according order
    is_sorted_until     finds the largest sorted subrange
    sort                sorts a range into according order
    partial_sort        sorts the first N elements of a range
    partial_sort_copy   copies and partially sort a range of elements
    stable_sort         sorts a range of elements while preserving order between equal elements
    nth_elements        partially sorts the given range making sure that it is partitioned by the given elements

*/
/// stable_sort
// Sorts the elements in the range [first, last) in ascending order.
// The order of equal elements is guaranteed to be preserved.
// The first version uses operator <.
// The second version used comparison function.


#include <iostream>
#include <algorithm>
#include <iomanip>

// #include <iterator>
// #include <functional>
#include <vector>
#include <string>

// #include <array>
// #include <random>
// #include <cstdlib>
// #include <ctime>

struct Employee {
    int age;            // it does
    std::string name;   // does not participate in comparison
    Employee(int age, std::string name): age(age), name(name){}
};
// not using this overload, but using lambda expression as you can see below.
bool operator<(const Employee& lo, const Employee& ro){
    return lo.age < ro.age;
}

int main(){
    std::vector<Employee> ev {
        Employee(23,"Jim"),
        Employee(14,"John"),
        Employee(33,"Jodi"), };

    typedef const Employee& cEm;
    std::stable_sort(ev.begin(),
                     ev.end(),
                     [](cEm a,cEm b){return a.age > b.age;}); // using the expression for comparison
    for(cEm et:ev)std::cout<<et.age<<' '<<et.name<<'\n';

}

