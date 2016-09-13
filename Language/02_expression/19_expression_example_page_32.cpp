///
/// Expression
///
/// Comparison Operators
///
///

/**
Compare the argument.
name                        syntax              overload
equal to                    a == b              yes
not equal to                a != b              yes
less than                   a <  b              yes
greater than                a >  b              yes
less than or equal to       a <= b              yes
greater than or equal to    a >= b

Note:
All build-in operator return boolean, and most user-defined overload also
return boolean so that the the user-defined operators can be used in the_
same manner as the built-in. However, in a user-defined operator overload,
any type can be used as return type ( including void )
**/


#include <iostream>
#include <string>
class Operand {
private:
    int data;
public:
    Operand(const int tempData) : data (tempData) {}
    Operand() : Operand(0) {}
    Operand(const double tempData) : Operand(static_cast<int>(tempData)) {}
    friend std::ostream& operator<<(std::ostream& out, const Operand& object){
        out << object.data;
        return out;
    }
    /************************************************/
};

struct Foo { int n1,n2; };
union Uoo { int n; double d;};

int main(){
    char a[4]= "abc";

    char* p1 = &a[1];
    char* p2 = &a[2];

    std::cout<<"Pointers to array elements: p1 == p2 "<<(p1==p2)
             <<", p1 < p2 " <<( p1 < p2 ) <<std::endl;

    Foo f;
    int* i1 = &f.n1;
    int* i2 = &f.n2;
    std::cout<<"Pointers to members of  a struct: i1 == i2 "<<(i1==i2)
             <<", i1 < i2 "<<(i1 < i2 )<<std::endl;

    Uoo u;
    int* u1 = &u.n;
    double* u2 = &u.d;
    std::cout<<"pointers to members of union: u1 == ( void* ) u2 "<<(u1 == (void*)u2)
             <<", u1 < u2 " <<(u1 < (void*)u2)<<std::endl;

    /// it is false to compare ( u1 == u2 )
    /// int* == double* but we can compare anyway with:
    /// int* == (void*) double*, like above sample

    /**
    Note:
        Comparison between pointers and null pointer contents was removed in c++14

        void f ( char* p ) {
            if (p > 0 ) {...} OK in c++98..c++11, but does not compile in c++14
            if (p > nullptr ) {...} OK in c++98..c++11, but does not compile in c++14
        }
    **/
}

