/*
Template:
    01 template parameter and template argument
    02 class template
    03 function template
    04 variable template
    05 template argument deduction
    06 explicit (full) template specialization
    07 partial template specialization
    08 parameter pack
    09 sizeof ... operator
    10 fold expression
    11 dependent names
    12 SFINAE
    13 constraints and concepts
*/
#include <iostream>
#include <vector>
#include <typeinfo>
/// 05 template argument deduction
/**
**/
//  Non-deduced Contexts
// P means: Parameter
// A means: Argument
//
//  09  For P of array type (but not reference to array or pointer to array)
//      the major array bounded
template<int i>  void f1(int a[10][i]){}
template<int i>  void f2(int a[i][20]){}        // P = int[i][20], array type
template<int i>  void f3(int (&a)[i][20]){}     // P = int(&)[i][20], reference to array
void g(){

    int v[10][20];
    f1(v);      // okay, i deduced to be 20
    f1<20>(v);  // okay


//    f2(v);      // error, cannot deduce template-argument i
    f2<10>(v);  // okay

    f3(v);      // okay, i deduced to be 10
}

template<int i>  void ft(int a[i][20]){}        // P = int[i][20], array type
void s(){
    int t[20][20];
    ft(t);      // wrong, a(*)[20] cannot deduce from t[20][20]
    /// why is the syntax wrong?
    /// because int a(*)[20] that here is: i = (*)
    /// cannot deduce from t[20][20]. here t[20] cannot bind to i
    /// so i neet to be initialize explicitly
    /// this syntax is correct:
    ft<20>(t);
/**

temp.cpp: In function ‘void s()’:
temp.cpp:48:9: error: no matching function for call to ‘ft(int [20][20])’
     ft(t);
         ^
temp.cpp:45:23: note: candidate: template<int i> void ft(int (*)[20])
template<int i>  void ft(int a[i][20]){}        // P = int[i][20], array type
                       ^
temp.cpp:45:23: note:   template argument deduction/substitution failed:
temp.cpp:48:9: note:   couldn't deduce template parameter ‘i’
     ft(t);

**/
}
int main(){
return 0; }

