/*
    quick review:
    General-Purpose Utility

    01. program utility
    02. date and time
    03. bitset
    04. function object
    05. pair
    06. tuple
    07. swap, forward, move
    08. type operations
    09. hash support

*/
/// 02. data and time ( c++ ) in header <chrono>

//  duration

#include <iostream>
#include <chrono>


int main(){

    std::chrono::duration< long long int, std::ratio< 3600, 1 > > user_one_hour( 1 );
    std::cout << user_one_hour.count() << '\n';

//    std::chrono::duration< double, std::ratio< 1, 1 > > sec = user_one_hour;
//    std::cout << sec.count() << '\n';
//
//    std::chrono::duration< double, std::ratio< 60, 1 > > min = user_one_hour;
//    std::cout << min.count() << '\n';

    std::chrono::seconds sec = user_one_hour;
    std::cout << sec.count() << '\n';   // 3600

    std::chrono::minutes min = user_one_hour;
    std::cout << min.count() << '\n';   // 60

}


/* output:

1
3600
60

*/

/* in standard library:

  typedef ratio<1,       1000000000000000000> atto;
  typedef ratio<1,          1000000000000000> femto;
  typedef ratio<1,             1000000000000> pico;
  typedef ratio<1,                1000000000> nano;
  typedef ratio<1,                   1000000> micro;
  typedef ratio<1,                      1000> milli;
  typedef ratio<1,                       100> centi;
  typedef ratio<1,                        10> deci;
  typedef ratio<                       10, 1> deca;
  typedef ratio<                      100, 1> hecto;
  typedef ratio<                     1000, 1> kilo;
  typedef ratio<                  1000000, 1> mega;
  typedef ratio<               1000000000, 1> giga;
  typedef ratio<            1000000000000, 1> tera;
  typedef ratio<         1000000000000000, 1> peta;
  typedef ratio<      1000000000000000000, 1> exa;

*/
