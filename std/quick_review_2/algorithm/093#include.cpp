/*

A review of algorithm library

merge:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// includes
//  test whether a sorted range includes another sorted range

// return is: boolean


char make_alpha(){
    static char a = 'a';
    return a++;
}
int main(){

    char alphabets[ 26 ]{};
    char* begin_alpha = alphabets;
    char* end_alpha = alphabets + 26;
    std::generate( begin_alpha, end_alpha, make_alpha );    // a b c d e f g h i j k l m n o p q r s t u v w x y z

    const char subset[ 4 ]{ 'b','c','d','e' };
    const char* begin_subset = subset;
    const char* end_subset = subset + 4;

    bool subset_include = std::includes( begin_alpha, end_alpha,    // first range
                                         begin_subset, end_subset ); // second range
    std::cout << ( subset_include ? "yes including" : "no does not include" ) << '\n';
}

/* output

yes including

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.





*/
