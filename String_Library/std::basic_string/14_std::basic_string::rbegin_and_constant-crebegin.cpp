#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::rbegin, std::basic_string::crbegin
/*

reverse_iterator rbegin();

const_reverse_iterator rbegin() const;

const_reverse_iterator crbegin() const; (since C++11)

*/
 /// Return value : reverse iterator to the first character


int main (int ac,char **av, char **lvs) {
    { /// test reverse_iterator re begin()
        cout<<"test reverse_iterator re begin()"<<endl;

        std::basic_string<char> s ("a b c d e f g h");

        cout<<"Before using iterator : "<<s<<endl;

        *s.rbegin() = 'H'; /// changing 'h' to 'H'

        cout<<"After using iterator : "<<s<<endl;

    }
    { /// continuing test above

        std::basic_string<char> s ("a b c d e f g h");

        std::basic_string<char>::reverse_iterator ris = s.rbegin();

        cout<<*ris<<endl;

        while(*ris){

            cout<<*ris<<' ';

            ++ris;
        }
        ris-=s.size(); /// Okay

        auto bris = (ris); /// Okay

        cout<<endl<<*bris<<endl;
    }
    { /// Test const_reverse_iterator rbegin() const;

        cout<<"Test const_reverse_iterator rbegin() const;"<<endl;

        std::string s ("1 2 3 4 5 6 7 8 9");

        cout<<"Before : "<<s<<endl;

        std::string::const_reverse_iterator cris = s.rbegin();

        cout<<*cris<<endl; /// Output -> 9

        for( ; *cris ; ++cris )
            cout<<*cris<<' '; /// Output -> 9 8 7 6 5 4 3 2 2 1

        cris-= s.size(); /// Reset Address to rbegin
        /*
        *cris = '*' /// error: assignment of read-only location cris...

        for( ; *cris ; ++cris )
            cout<<*cris<<' ';
        */
        cout<<endl;
    }
    { /// Test const_reverse_iterator crbegin() const; (since C++11)

        cout<<"Test const_reverse_iterator crbegin() const; (since C++11)"<<endl;

        std::string s ("A B C D E F G H");

        std::string::const_reverse_iterator cris = s.crbegin();

        cout<<*cris<<endl;
        /*
        *cris = '*' /// error: assignment of read-only location cris...

        for( ; *cris ; ++cris )
            cout<<*cris<<' ';
        */
        while (*cris) {
            cout<<*cris<<' ';
            ++cris;
        }

    }

}


















