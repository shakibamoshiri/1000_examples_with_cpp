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
/// std::regex_traits::lookup_collatename
// It the character sequence [first,last) represents the name of a valid collating
// element in the currently imbued locale, returns the name of this collation element.
// Otherwise, returns an empty string.
//
// Collation elements are the symbols found in POSIX regular expression between [.and.].
// For example, [.a.] matches the character 'a' in the C locate.
// [.tilde.] matches the character '~' in the C locate as well.
// [.ch.] matches the character 'ch' in Czech locale, but generates std::regex_error
// with error code std::regex_constants::error collate in most other locale.

#include <iostream>
#include <regex>

// #include <iterator>
// #include <algorithm>
// #include <string>

struct noisy_traits : std::regex_traits<char> {
    template<typename Iter>
    string_type lookup_collatename(Iter first,Iter last)const{
        string_type result = regex_traits::lookup_collatename(first,last);
        std::cout<<"regex_traits<>::lookup_collatename(\""
                 <<string_type(first,last)
                 <<"\")return: \""
                 <<result
                 <<"\"\n";

        return result;
    }
};

int main(){

    std::string str = "z}a";        // C locale collation order: x,y,z,{,|,},~

    std::basic_regex<char, noisy_traits> re ("[x-[.tilde.]]*a", std::regex::basic);

    std::cout << std::boolalpha << std::regex_match(str,re) << std::endl;

    // for more detail you can see regex.tcc

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
