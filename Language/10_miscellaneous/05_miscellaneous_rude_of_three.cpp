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
// Rule of three
// If a class requires a user-defined destructor, a user-defined copy constructor
// , or a user-defined copy assignment operator, it almost certainly requires all three.


class rule_of_three {
    char* cstring;      // raw printer used as a handle to a dynamically-allocated memory block
public:
    rule_of_three(const char* arg)
        : cstring(new char[std::strlen(arg)+1])     // allocate
        {
            std::strcpy(cstring, arg);
        }
        ~rule_of_three(){
            delete[] cstring;
        }
        rule_of_three(const rule_of_three& other){   // copy constructor
            cstring = new char[std::strlen(other.cstring)+1];
            std::strcpy(cstring, other.cstring);
        }
        rule_of_three& operator=(const rule_of_three& other){   // copy assignment
            char* temp_cstring = new char[std::strlen(other.cstring)+1];
            std::strcpy(temp_cstring,other.cstring);
            delete[] cstring;
            cstring = temp_cstring;
            return *this;
        }
};
// alternatively, reuse destructor and copy constructor
rule_of_three& operator=(rule_of_three other){
    std::swap(cstring, other.cstring);
    return *this;
}
