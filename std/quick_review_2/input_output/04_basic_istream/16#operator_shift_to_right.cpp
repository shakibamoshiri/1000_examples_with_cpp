/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::operator >>
// arithmetic type:
// (bool& val);
// (short& val);
// (unsigned short& val);
// (int& val);
// (unsigned int& val);
// (long& val);
// (unsigned long& val);
// (long long& val);
// (unsigned long long& val);
// (float& val);
// (double& val);
// (long double& val);
// (void*& val);

// stream buffer
// basic_istream& operator>> (basic_streambuf<char_type,traits_type>* sb );

// manipulator
// basic_istream& operator>> (basic_istream& (*pf)(basic_istream&));
// basic_istream& operator>> (basic_ios<char_type,traits_type>& (*pf)(basic_ios<char_type,traits_type>&));
// basic_istream& operator>> (ios_base& (*pf)(ios_base&));

// Extracts formated input.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <limits>



int main(){


    // stream buffer
    // basic_istream& operator>> (basic_streambuf<char_type,traits_typ
    std::ifstream( "file" ) >> std::ofstream( "file_2" ).rdbuf();


}
/**



**/
