/**
/// Namespaces
///
///
Syntax:

1   namespace ns_name { declaration }
2   inline namespace ns_name { declaration }
3   namespace { declaration }
4   ns_name::name
5   using namespace ns_name;
6   using ns_name::name;
7   namespace name = qualified-namespace;
8   namespace ns_name::name. since c++ 17

This example shows how to  use a namespace to create a class
that already has been named in the std namespace.

**/
#include <iostream>
#include <vector>
/// user defined
//#include "temp.h"
namespace vec {
    template<typename T>
    class vector {
        // implementation
    };
}

int main(){

    std::vector<int> v1;        // Standard vector
    vec::vector<int> v2;        // user-defined vector

//    v1 = v2;                    // Error: v1 and v2 are different object's type

    {
        using namespace std;
        vector<int> v3;         // Same as std::vector
        v1 = v3;                // Okay both are the same type
    }

    {
        using vec::vector;
        vector<int> v4;         // Same as vec::vector
        v2 = v4;                // Okay
    }

}













