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
/// std::regex_traits::primary
// For the character sequence [first,last) obtains the primary sort key in
// imbued locale's collation order, that is, the sort key that is based on
// the position of the letters and collation units in the national alphabet
// ignoring, diacritic, variants, etc. If a primary sort key compares less then
// another primary sort key with operator <, then the character sequence that
// produced the first key comes before the character sequence that produced the
// second sort key currently imbued locale's primary collation order.

#include <iostream>
#include <regex>

// #include <iterator>
// #include <algorithm>
// #include <string>




int main(){

    std::locale::global(std::locale("en_US.UTF-8"));
    std::wstring str = L"AÀÁÂÃÄÅaàáâãäå";
    std::wregex re(L"[[=a=]]*", std::regex::basic);
    std::cout << std::boolalpha << std::regex_match(str, re) << '\n';

return 0;}
