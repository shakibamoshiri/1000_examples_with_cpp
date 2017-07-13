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
/// 05 the rule of three / five / zero
//
//
// Rule of zero
// classes that have custom destructor, copy/ move constructor or copy/move
// assignment operator should deal exclusively with ownership ( which follows
// from the Single Responsibility Principle ). Other classes should not have
// custom destructor, copy/move constructor or copy/move assignment operator
clas rule_zero {
    std::string cppstring;
public:
    rule_zero(const std::string& arg) cppstring(arg){}
};
// when a base class is intended for polymorphic use, its destructor may have to
// be declared public and virtual. This blocks implicit moves ( and deprecate implicit
// copies) ,and so that special member function have to be declared as defaulted.
class base_of_five_defaults {
public:
    base_of_five_defaults(const base_of_five_defaults&) = default;
    base_of_five_defaults(base_of_five_defaults&&)      = default;
    base_of_five_defaults& operator=(const base_of_five_defaults&)  = default;
    base_of_five_defaults& operator=(base_of_five_defaults&&)       = default;
    virtual ~base_of_five_defaults() = default;
};

