/*
            The Regular Expression Library
            ******************************
Defined in header <regex>
// for more detail see: regex.h
                        regex_constants.h
                        --> Constants:
    Defined a namespace std::regex_constants

>   syntax_option_type: general options controlling regex behavior
>   match_flag_type:    option specific to matching
>   error_type:



*/
/// std::regex_constants::error_type
// The error type is a type that describes errors that
// may occur during regular expressing parsing.
//
// error_collate 	    the expression contains an invalid collating element name
// error_ctype          the expression contains an invalid character class name
// error_escape 	    the expression contains an invalid escaped character or a trailing escape
// error_backref 	    the expression contains an invalid back reference
// error_brack 	        the expression contains mismatched square brackets ('[' and ']')
// error_paren 	        the expression contains mismatched parentheses ('(' and ')')
// error_brace  	    the expression contains mismatched curly braces ('{' and '}')
// error_badbrace 	    the expression contains an invalid range in a {} expression
// error_range 	        the expression contains an invalid character range (e.g. [b-a])
// error_space  	    there was not enough memory to convert the expression into a finite state machine
// error_badrepeat 	    one of *?+{ was not preceded by a valid regular expression
// error_complexity 	the complexity of an attempted match exceeded a predefined level
// error_stack      	there was not enough memory to perform a match
//
// Note
// In C++11, these constants were specified with redundant keyword static, which was removed by C++14 via LWG issue 2053

#include <iostream>
#include <regex>

// #include <vector>
// #include <array>
// #include <iterator>
// #include <algorithm>
// #include <string>
 //#include <map>
 //#include <set>
 //#include <list>
 #include <sstream>



int main(){

    std::string string("Some people, when confront with a problem, this"
                       "\"I know, I will use regular expression.\""
                       "Now they have two problems.");

    std::regex rx("REGULAR EXPRESSION",std::regex_constants::ECMAScript|std::regex_constants::icase);  // text in upper case
    if(std::regex_search(string,rx)) std::cout<<"Text contains the phrase 'regular expression'\n";

    std::regex rx2("(\\S+)"); // not white space or tab
    std::regex_iterator<std::string::const_iterator> begin_word = std::sregex_iterator(string.begin(),string.end(),rx2);
    std::regex_iterator<std::string::const_iterator> end_word = std::sregex_iterator();
    std::endl(std::cout<<"fount:\t"<<std::distance(begin_word,end_word));

    const int N=6;
    std::endl(std::cout<<"words longer than "<<N<<"characters");
    for(std::sregex_iterator i=begin_word;
        i != end_word;
        ++i){
            std::smatch match = *i;
            std::string mstr = match.str();
            if(mstr.size() > N) endl(std::cout<<' '<<mstr);
        }

    std::regex word7("(\\w{7,})"); // with 7 length or more {7} exactly 7. {7,} 7 or more. {7,10} from 7 to 10
    std::string word7_str = std::regex_replace(string,word7,"[$&]");
    endl(std::cout<<word7_str);



return 0;}

