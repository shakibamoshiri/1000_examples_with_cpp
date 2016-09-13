#include <iostream>
#include <string>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::empty
/*
bool empty() const;

*/
 /// true if the string is empty, false otherwise



int main() {
    {
        std::basic_string<char> s;
        std::boolalpha(cout);
        cout<<s.empty()<<endl;
    }
    { /// Sample of en c plus plus reference
        std::string s ;
        std::boolalpha(cout);

        cout<<"s.empty() : "<<s.empty()<<"\t s:'"<<s<<"'\n";
        s = "Exemplary";
        cout<<"s.empty() : "<<s.empty()<<"\t s:'"<<s<<"'\n";
        s = "";
        cout<<"s.empty() : "<<s.empty()<<"\t s:'"<<s<<"'\n";

    }
}


















