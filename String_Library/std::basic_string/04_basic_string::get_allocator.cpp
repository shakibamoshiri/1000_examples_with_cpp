#include <iostream>
#include <string>
#include <cassert>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// basic_string::get_allocator
/*
    allocator_type get_allocator( ) const;
*/

std::ostream& operator<<(std::ostream& out,std::basic_string& str){
    out<<str;
    return out;
}
std::allocator_type

int main (int ac,char **av, char **lvs) {
    std::string s("Test get_allocator of class string");
    std::string d(s.get_allocator());
    cout<<s<<endl;
    cout<<s.get_allocator();
}


















