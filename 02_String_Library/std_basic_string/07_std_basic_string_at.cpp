#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::at
/*
    reference       at( size_type pos );
    const_reference at( size_type pos ) const;
*/

//std::ostream& operator<<(std::ostream& out, std::basic_string<char>* str){
//    out<<*str<<" And test overloading";
//    return out;
//}

int main (int ac,char **av, char **lvs) {
    {/* 1 */
        std::basic_string<char> s ("Test at in basic_string");
        cout<<s.at(3)<<endl;
        s.at(3) = 'T';
        cout<<s<<endl;
    }
    { /* cpp reference */
        std::string s("message");
        s = "abc";
        s.at(2) = 'X';
        cout<<s<<endl;
        cout<<"String size = "<<s.size()<<endl;
        cout<<"String capacity = "<<s.capacity()<<endl;

        try{
            s.at(4) = '4';
        }
        catch(std::out_of_range const& exc){
            cout<<exc.what()<<endl;
        }
    }
}


















