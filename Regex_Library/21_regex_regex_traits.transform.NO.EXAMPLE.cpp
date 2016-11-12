/*
            The Regular Expression Library
            ******************************
Defined in header <regex>
// for more detail see: regex.h
                        regex_constants.h

--> Traits:
    The regex traits class is used to encapsulate the localizable aspect of a regex.

>   regex_traits:   provides meta-information about a character type, required by the regex library

    > constructor:          constructs the regex_traits object
    > length:               calculate the length of a null-terminated character string
    > translate:            determines the equivalence key for a character
    > translate_nocase:     determines the case-insensitive equivalence key for a character
    > transform:            determines the sort key for the given string, used to provide collation order
    > transform_primary:    determines the primary sort key for the character sequence, used to determine equivalence class
    > lookup_collatename:   get a collation element by name
    > lookup_classname:     get a character class by name
    > isctype:              indicates membership in a localized character class
    > value:                translates the character representing a numeric digit into an integral value
    > imbue:                sets the locale
    > getloc:               gets the locale

*/
/// std::regex_traits::transform
// Obtains the sort key for the character sequence [first,last), such that if
// a sort key compares less than another sort key with operator <, then the
// character sequence that produced the first sort key comes before the character
// sequence that produced the second sort key, int the currently imbued local's
// collation order.

#include <iostream>
#include <regex>

// #include <iterator>
// #include <algorithm>
// #include <string>


typedef std::regex_traits<char> Regex;

int main(){

    const char *beg_san="San Francisco";
    const char *end_san=beg_san+Regex::length(beg_san);

    const char *beg_SAN="SUN FRANCISCO";
    const char *end_SAN=beg_SAN+Regex::length(beg_SAN);

    Regex rx;
    std::cout<<rx.transform_primary(beg_san,end_san)<<std::endl;
    std::cout<<rx.transform_primary(beg_SAN,end_SAN)<<std::endl;

return 0;}
