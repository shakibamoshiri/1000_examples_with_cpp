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
/// class
//  copy assignment
//  It can be:
//  user-defined
//  = default
//  = delete


/******************/
#include <iostream>


class A {
private:
    int number = 0;
    const char* name = "";

public:
    A( int temp_number, const char* temp_cstring )
        : number( temp_number ),
          name( temp_cstring )
          { puts( "user-defined constructor" ); }
    A& operator =( const A& other ){
        // check for self-assignment
        if( this == &other ){
            puts( "this was a self-assignment" );

            return *this;
        }
        puts( "check for self-assignment was pass" );
        this->number = other.number;
        this->name   = other.name;

        return *this;
    }

    void print(){
        std::cout << "number: " << this->number << ' '
                  << "name: " << this->name << '\n';
    }
};



int main(){

    A one( 1, "one" );
    A two( 2, "two" );
    one.print();
    two.print();

    puts( "-------------------" );

    one.operator=( two );
    one.print();
    two.print();

    puts( "-------------------" );

    two.operator=( two );
    one.print();
    two.print();



}

/* output:

user-defined constructor
user-defined constructor
number: 1 name: one
number: 2 name: two
-------------------
check for self-assignment was pass
number: 2 name: two
number: 2 name: two
-------------------
this was a self-assignment
number: 2 name: two
number: 2 name: two

*/
