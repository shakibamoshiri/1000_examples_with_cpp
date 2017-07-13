/*

    thread support library
    **********************
Defined in header <future>

    std::async
    **********
The template function async runs the function 'f' asynchronously
( potentially in a separate thread which may be part of a thread pool )
and returns a std::future that will eventually hold the result of that function call.

// for more detail see the main website en.cppreference.com
*/
/// std::async

#include <iostream>
#include <future>
#include <algorithm>
#include <vector>
#include <numeric>

template< typename RAIter >
int parallel_sum( RAIter beg, RAIter end ){

    const int len = end - beg;      // an iterator - another iterator => an integer number
    if( len < 1000 ){
        return std::accumulate( beg, end, 0 );
    }
        RAIter mid = len / 2 + beg; // an integer number / 2 then + an iterator => an iterator

        std::future< int > handle = std::async(
            std::launch::async,
            parallel_sum< RAIter >,
            mid,
            end
        );

        int sum = parallel_sum( beg, mid );

        return sum + handle.get();

}


int main(){

    std::vector< int > vector( 10'000, 2 );
    std::cout << "the sum is "
              << parallel_sum( vector.begin(), vector.end() )
              << std::endl;
}

/* output for me:

the sum is 20000

*/








