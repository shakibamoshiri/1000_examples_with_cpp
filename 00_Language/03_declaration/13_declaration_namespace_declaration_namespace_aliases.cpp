/**
/// Namespaces alias
///
///
Namespae aliases allow the programmer to define an alternate name for a namespace.
They are commonly used as a convenient shortcut for long or deeply-nested namespace.

Syntax:
namespace alias_name = ns_name;
namespace alias_name = ::ns_name;
namespace alias_name = nested_name::ns_name;

Explanation:
The new alias alias_name provides an alternate method of accessing ns_name.
Alias_name must be a name not previously used. Alias_name is valid for the
duration of the scope in which it is introduced.


**/
#include <iostream>
#include <vector>

namespace one {
    namespace two {
        namespace three {
            int i = 3;
        }
    }
}

namespace o_t_th = one::two::three;

namespace s = std;


int main(){
    s::cout<<"Nmaespace Aliases"<<s::endl;
    s::cout<<o_t_th::i<<s::endl;
}












