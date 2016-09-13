/**
/// alignas specifier
///
Specifies the alignment requirement of a type or an object.

Syntax:
alignas ( expression )
alignas ( type-id )
alignas ( pack ... )

1)  alignas expression must be an integral constant expression that equivalent to zero
    , or to a valid for an alignment or extended alignment.
2)  Equivalent to alignas ( alignof(type))
3)  Equivalent to multiple alignas specifiers applies to the same declaration, one for
    each member of the parameter pack, which can be either type or non-type parameter pack.

note: it cannot be applied to a function parameter or to the exception parameter of catch clause.
**/
#include <iostream>
#include <string>

// every object of type sse_t will be aligned to 16-byte boundary
struct alignas(16) sse_t {
    float sse_data[4];
};

int main(){
    // the array "cacheline" will be aligned to 128-byte boundary
    alignas(128) char cacheline[128];

    sse_t one;
    std::cout<<sizeof(one)<<std::endl;
    std::cout<<sizeof(cacheline)<<std::endl;

}









