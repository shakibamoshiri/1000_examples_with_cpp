#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::find_last_not_of
/*
size_type find_last_not_of( const basic_string& str, size_type pos = npos ) const;(1)
size_type find_last_not_of( const CharT* s, size_type pos, size_type count ) const;(2)
size_type find_last_not_of( const CharT* s, size_type pos = npos ) const;(3)
size_type find_last_not_of( CharT ch, size_type pos = npos ) const;(4)

*/

int main() {
    {
        /// size_type find_last_not_of( const basic_string& str, size_type pos = npos ) const;(1)




        /// size_type find_last_not_of( const CharT* s, size_type pos, size_type count ) const;(2)
        /// size_type find_last_not_of( const CharT* s, size_type pos = npos ) const;(3)
        /// size_type find_last_not_of( CharT ch, size_type pos = npos ) const;(4)

    }
    { /// Sample from the website cplsuplus.com
      std::string str ("Please, erase trailing white-spaces   \n");
      std::string whitespaces (" \t\f\v\n\r");

      std::string::size_type found = str.find_last_not_of(whitespaces);
      if (found!=std::string::npos)
        str.erase(found+1);
      else
        str.clear();            // str is all whitespace

      std::cout << '[' << str << "]\n";
    }
}





















