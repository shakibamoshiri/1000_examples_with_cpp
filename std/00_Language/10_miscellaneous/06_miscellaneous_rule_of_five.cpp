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
// Rule of five
class rule5 {
    char* cstring;      // raw pointer used as a handle to a dynamically-allocated memory block
public:
    rule5 (const char* arg): cstring(new char[std::strlen(arg)+1]) { // allocate
        std::strcpy(cstring, arg);  // populate
    }

    ~rule5(){ delete[] cstring;     // deallocate
    }

    rule5 (const rule5& other){     // copy constructor
        cstring = new char[std::strlen(other.cstring)+1];
        std::strcpy(cstring, other.cstring);
    }

    rule5 ( const rule5&& other): cstring(other.cstring){
        other.cstring = nullpter;
    }

    rule5& operator=(const rule5& other){     // copy assignment
        char ctemp = new char[std::strlen(other.cstring)+1];
        std::strcpy(ctemp, other.cstring);
        delete [] cstring;
        cstring = ctemp;
        return *this;
    }

    rule5& operator= ( rule5&& other){          // more assignment
        delete cstring;
        cstring = other.cstring;
        other.cstring = nullptr;
        return *this;
    }
}
//
//
// Alternatively, replace both assignment operators with
rule5& operator=(rule5 other){
    std::swap(cstring, other.cstring);
    return *this;
}
// Unlike rule of three ( 05 sample ), failing to provide move constructor
// and move assignment is usually not an error, but a missed optimization opportunity.
