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
/// 01 template parameter and template argument

// template type argument

// note: A template argument for a type-template parameter must be type-id,
// which may name an incomplete type
template<typename T> class A {};        // class template

struct B;               // not complete, or incomplete type

typedef struct {} C;    // type alias to an unnamed type

int main(){
    A<B> a1;    // okay 'B'  name a type
    A<B*> a2;   // okay 'B*' names a type
    A<C> a3;    // okay 'C' names a type
}
