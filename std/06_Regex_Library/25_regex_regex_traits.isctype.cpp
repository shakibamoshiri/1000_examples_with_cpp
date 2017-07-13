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
/// std::regex_traits::isctype
// Determines whether the character 'c' belongs to the character class
// identified by 'f', which, in turn, is a value returned by lookup_classnmae()
// or a bitwise OR of several such values.
//
// NOTE:
// The description above summarized C++14; the C++11 phrasing required this
// function to return true for '_' in all cases (LWG issue 2018)

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


int main(){

    std::regex_traits<char> rx;

    std::string str("alnum");

    std::regex_traits<char>::char_class_type a = rx.lookup_classname(str.begin(),str.end());

    std::string s_w = "w";      // [:w:] is [:alnum:] plus '_'

    std::regex_traits<char>::char_class_type w = rx.lookup_classname(s_w.begin(),s_w.end());

    std::cout << std::boolalpha
              << rx.isctype('A',w) << ' ' << rx.isctype('A',a) << '\n'
              << rx.isctype('_',w) << ' ' << rx.isctype('_',a) << '\n'
              << rx.isctype(' ',w) << ' ' << rx.isctype(' ',a) << '\n';


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
