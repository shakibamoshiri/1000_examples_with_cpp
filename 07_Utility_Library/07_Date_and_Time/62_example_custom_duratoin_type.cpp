/*
            Date and Time
            *************



*/




#include <iostream>
#include <chrono>


/// Example:
//  shows how to define several custom duration type and convert between types
int main (){

    using shakes = std::chrono::duration< int, std::ratio<1, 1000000000> >;
    using jiffies = std::chrono::duration< int, std::centi >;
    using microfortnights = std::chrono::duration< float, std::ratio<12096, 10000> >;
    using nanocenturies = std::chrono::duration< float, std::ratio<3155, 10000> >;

    std::chrono::seconds sec(1);

    std::cout << "1 second is:\n";
    std::cout << std::chrono::duration_cast< shakes >(sec).count() << " shakes\n"
              << std::chrono::duration_cast< jiffies >(sec).count() << " jiffeis\n"
              << microfortnights(sec).count() << " microfortnights\n"
              << nanocenturies(sec).count() << " nanocenturies"
              << std::endl;

}


/* output for me:

1 second is:
1000000000 shakes
100 jiffeis
0.82672 microfortnights
3.16957 nanocenturies

*/






