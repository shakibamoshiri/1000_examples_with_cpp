/*
Algorithm Library C++
The algorithm library defines functions for a variety of purposes.
(e.g. searching, sorting, counting, manipulating ) that operate on
range of elements. Note that a range is defined as [ first, last )
where last refers to the element past the last element to inspect
or modify.

Defined in header <algorithm>

Non-modifying sequence operation
    all_of
    any_of
    noun_of             check, if the predicate is true for all, any, or none of the element is a range
    for_each            applies a function to a range of element

    count
    count_if            return the number of elements satisfying specific criteria
    mismatch            find the first position, where to ranges differ
    equal               determines if two set of elements are the same
    find
    find_if
    find_if_not         find the first element satisfying specific criteria
    find_end            find the last sequence of elements in certain range
    find_first_of       search for any one of a set of elements
    adjacent_find       find the first two adjacent items that are equal (or satisfy a given predicate)
    search              searches for a range of elements
    search_n            search for a number consecutive copies of an element in a range.
*/
#include <iostream>
#include <algorithm>

/// count
/// count_if
// Returns the number of elements in the range [first, last) satisfying specific
// criteria. The first version counts the elements that are equal to value, the
// second version counts for which predicate p return true.
//
// note: For the number of elements in the range [first, last) without any additional criteria, see std::distance
//
//
//
/*
/// count, possible implementation
template<class InputIt, class T>                                    // template
typename  iterator_traits<InputIt>::difference_type                 // return type function, it depends on iterator type
    count(InputIt first, InputIt last, const T& vlaue){             // function ( names count )
        typename iterator_traits<InputIt>::difference_type ret = 0; // makes a value of return type
        for(; first != last; ++first){
            if (*first == value)
                ret++;
        }
        return ret;
    } // end of count

/// count_if, possible implementation
template<class InputIt, class UnaryPredicate>
typename iterator_traits<InputIt>::different_type
    count_if(InputIt first, InputIt last, UnaryPredicate p){
        typename iterator_traits<InputIt>::different_type ret=0;
        for (; first != last; ++first){
            if ( p(*first) )
                ret++;
        }
    } // end of count_if

*/

#include <vector>

int main(){

    int data[] = {1,2,3,4,4,3,7,8,9,10};

    // *data: 1
    // *date+10: 10
    // so here <int> v(1, 10)
    std::vector<int> v(data, data+10);

    std::cout<<"inside the v: ";
    for(int t : v)
        std::cout<<t<<' ';

    const int target1 = 3;
    const int target2 = 5;

    //count how many 3 are inside the v
    int num_items1 = std::count(v.begin(), v.end(), target1);

    // count how many 5 are inside the v
    int num_items2 = std::count(v.begin(), v.end(), target2);

    std::cout<<"\nnumber: "<<target1 << " count: "<<num_items1;
    std::cout<<"\nnumber: "<<target2 << " count: "<<num_items2<<std::endl;

    // wrong syntax:
    // int num_items3 = std::count_if(v.begin(),v.end(),3);
    // here the third argument return type must be boolean
    // Also it gets a function
    // implementation:
    // operator()(_Iterator __it) { return bool(_M_pred(*__it)); }
    // so using 3 explicitly is wrong


    // this example uses a lambda expression to count element divisible by 3
    // here t is captured one by one of each elements, then is counted each true
    int num_items3 = std::count_if(v.begin(), v.end(), [](int t){ return t % 3 == 0; } );

    std::cout<<"number divisible by 3: "<<num_items3;

}
