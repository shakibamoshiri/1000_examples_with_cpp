/**

/// Expression
/// Implicit Conversions
/// static_cast

static_cast < new_type > ( expression )

Converts between types using a combination of implicit and user-defined conversion.
Return a value of type new_type


**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"

struct B {};
struct D : B {};
enum class E {ONE, TWO, THREE};
enum EU {ONE, TWO, THREE};

int main(){

    /// 1. initialization conversion.
    int n = static_cast<int>(3.14);
    std::cout<<"n = "<<n<<std::endl;
    std::vector<int> v = static_cast<std::vector<int>>(10);
    std::cout<<"v.size() = "<<v.size()<<std::endl;

    ///2 static downcast
    D d;
    B& br = d; /// upcast via implicit conversion.
    D& another_d = static_cast<D&>(br); /// downcast

    /// 3. l-value to x-value
    std::vector<int> v2 = static_cast<std::vector<int>&&>(v);
    std::cout<<"After move, v.size()  = "<<v.size()<<std::endl;
    std::cout<<"After move, v2.size() = "<<v2.size()<<std::endl;

    /// 4. discarded-value expression.
    static_cast<void>(v2.size());

    /// 5. inverse of implicit conversion.
    void* nv = &n;
    int* ni = static_cast<int*>(nv);
    int* ni2 = (int*)nv;
    int* ni3 = (int*)(nv); /// function call
    std::cout<<"*ni  = "<<*ni<<std::endl;
    std::cout<<"*ni2 = "<<*ni2<<std::endl;
    std::cout<<"*ni3 = "<<*ni3<<std::endl;

    /// 6. array to pointer following by up-cast
    D a[10];
    B* dp = static_cast<B*>(a);
    /// maybe
    D b[10];
    B* dp2 = (B*)b;

    /// 7. scoped enum to int or float
    E e = E::ONE;
    int one = static_cast<int>(e);

    /// 8. int to enum, enum to another enum
    E e2 = static_cast<E>(one);
    EU eu = static_cast<EU>(e2);

    /// 9. pointer to member up-cast


    ///10. void* to any type
    void* vp = &e;
    std::vector<int>* p = static_cast<std::vector<int>*>(vp);

}













