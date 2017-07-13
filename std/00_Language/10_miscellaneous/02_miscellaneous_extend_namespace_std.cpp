/*
Miscellaneous:
    01 asm declaration

    02 extending the namespace std

    03 undefined behavior
    04 RAII ( Resource Acquisition Is Initialization )
    05 The rule of three / five / zero
    06 The as-if rule
    07 copy elision
    08 Empty base optimization
*/
//
//
/// 02 extended the namespace STD
//
//
//
//  Adding declaration to std
//  It is undefined behavior to add declaration or definition to namespace std
//  or to any namesapce nested within STD, with a few exception.
//  note below:
#include <utility>
namespace std {
    // a function definition added to namespace std: undefined behavior
    pair<int,int> operator+(pair<int,int> a, pair<int,int> b){
        return {a.first + b.frist, a.second + b.second };
    }
}
// It is allowed to added template specialization for any standard library
// template to the namesapce std only if the declaration depends on a user-defined
// type and the specialization satisfies all requirement for the original template,
// except where such specialization are prohibited.
// For more detail read the main site.
//
//
//
//  Other restriction
//  The namespace STD may not be declared as an inline namesapce.
