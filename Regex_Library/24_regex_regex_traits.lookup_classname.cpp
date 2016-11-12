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
/// std::regex_traits::lookup_classname
// If the character sequence [first,last) represents the name of a valid
// character class in the current imbued locale (that is,the string between [:and:] in regular expression),
// returns the implementation-defined value representing this character class. Otherwise, return zero.
//
// If the parameter 'icase' is true, the character class ignores character case,
// e.g. the regex [:lower:] with std::regex_constants::icase generates a call
// to regex_traits<>::lookup_classname() with [first,last) indicating 'lower'
// and icase==true. This call returns the same bitmask as the call generated
// by the regex [:alpha:] with icase==false.
//
// The following character classes are always recognized, in both narrow and
// wide character forms, and the classification returned (with icase==false)
// correspond to the matching classification obtained by the std::ctype facet
// on the locale, as follows:
//
// character class      std::ctype      classification
// "alnum"              std::ctype      base::alnum
// "alpha"              "               base::alpha
// "blank"              "               base::blank
// "cntrl"              "               base::cntrl
// "digit"              "               and so and and so forth
// "graph"
// "lower"
// "print"
// "punct"
// "space"
// "upper"
// "xdigit"
// "d"                  "               base::digit
// "s"                  "               base::space
// "w"                                  base::alnum with '_' optionally added
//

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


#include <locale>
#include <cwctype>

// This custom regex traits uses wctype/iswctype to implement lookup_classname/isctype
struct wctype_traits : std::regex_traits<wchar_t>
{
    using char_class_type = std::wctype_t;
    template<class It>
    char_class_type lookup_classname(It first, It last, bool=false) const {
        return std::wctype(std::string(first, last).c_str());
    }
    bool isctype(wchar_t c, char_class_type f) const {
        return std::iswctype(c, f);
    }
};

int main(){

    /// NOTE: my by in your locate throw an exception

    std::locale::global(std::locale("ja_JP.utf8"));
    std::wcout.sync_with_stdio(false);
    std::wcout.imbue(std::locale());

    std::wsmatch m;
    std::wstring in = L"風の谷のナウシカ";
    // matches all characters (they are classified as alnum)
    std::regex_search(in, m, std::wregex(L"([[:alnum:]]+)"));
    std::wcout << "alnums: " << m[1] << '\n'; // prints "風の谷のナウシカ"
    // matches only the kanji
    std::regex_search(in, m,
                      std::basic_regex<wchar_t, wctype_traits>(L"([[:jkata:]]+)"));
    std::wcout << "katakana: " << m[1] << '\n'; // prints "ナウシカ"

return 0;}

/**
may be useful
https://msdn.microsoft.com/en-us/library/bb982727.aspx
Regular Expressions (C++)

https://msdn.microsoft.com/en-us/library/bb982803.aspx

struct regex_traits {
   regex_traits();
   static size_type length(const char_type *str);
   char_type translate(char_type ch) const;
   char_type translate_nocase(char_type ch) const;
   template <class FwdIt>
   string_type transform(FwdIt first, FwdIt last) const;
   template <class FwdIt>
   string_type transform_primary(FwdIt first, FwdIt last) const;
   template <class FwdIt>
   char_class_type lookup_classname(FwdIt first, FwdIt last) const;
   template <class FwdIt>
   string_type lookup_collatename(FwdIt first, FwdIt last) const;
   bool isctype(char_type ch, char_class_type cls) const;
   int value(Elem ch, int base) const;
   locale_type imbue(locale_type loc);
   locale_type getloc() const;
   typedef Elem char_type;
   typedef T6 size_type;
   typedef basic_string<Elem>
   string_type;
   typedef T7 locale_type;
   typedef T8 char_class_type;
   };

**/
