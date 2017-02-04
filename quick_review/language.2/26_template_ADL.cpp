/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// 2. template


/******************/
#include <iostream>
/******************/


namespace k5 {

    class ADL {
    private:
        int number = 0;
        const char* name = "";
    public:
        ADL( int temp_number, const char* temp_cstring )
            : number( temp_number ), name( temp_cstring ) {}
        friend void print(ADL&);

        friend std::ostream& operator <<( std::ostream&, ADL& );
    };
    void print( ADL& obj ){
       std::cout << obj.number << ' '
                 << obj.name << '\n';
    }
    std::ostream& operator <<( std::ostream& out, ADL& obj ){
        return out << obj.number << ' ' << obj.name ;
    }
}   // end of namespace k5


int main(){

    k5::ADL one( 1, "one" );
    print( one );           // find via ADL rule
    std::cout << one;       // also

}

/* output:


*/
