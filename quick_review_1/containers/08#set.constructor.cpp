/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <set>

// constructor

int main(){

    std::set<int> one {3,1,5,2,6,7,1,1,2,3,6,5,4,3,2,1,2,3,4,5,6,7};

    for (int t : one) std::cout << t << ' ';    // sorted and got unique

}




