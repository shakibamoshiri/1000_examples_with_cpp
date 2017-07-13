///
/// Expression
///
/// Example page 13
/**

**/
#include <iostream>

int main(){
    int n1 = 1;
    int n2 = ++n1;
    int n3 = ++ ++n1;
    int n4 = n1++;

//    int n5 = n1++ ++;   /// Error
//    int n6 = n1 + ++n1; /// Undefined behavior

    std::cout<<"n1 = "<<n1
             <<"\nn2 = "<<n2
             <<"\nn3 = "<<n3
             <<"\nn4 = "<<n4<<std::endl;
}
/**
**It has no explanation and only has a sample**
for getting more information, you can read others documentation.

**NOTE**
There is `friend` definition because of `private date`
If we use `public data` no need to use `friend`
---
**/
