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
/// std::regex_constants::match_flag_type
// match_flag_type is a BitmaskType that specified additional regular expression
// matching options.
//
// constants [first,last) refers to the character sequence begin matched
//
// match_not_bol 	    The first character in [first,last) will be treated as if it is not at the beginning of a line (i.e. ^ will not match [first,first)
// match_not_eol    	The last character in [first,last) will be treated as if it is not at the end of a line (i.e. $ will not match [last,last)
// match_not_bow 	    "\b" will not match [first,first)
// match_not_eow 	    "\b" will not match [last,last)
// match_any 	        If more than one match is possible, then any match is an acceptable result
// match_not_null 	    Do not match empty sequences
// match_continuous 	Only match a sub-sequence that begins at first
// match_prev_avail 	--first is a valid iterator position. When set, causes match_not_bol and match_not_bow to be ignored
// format_default 	    Use ECMAScript rules to construct strings in std::regex_replace (syntax documentation)
// format_sed 	Use     POSIX sed utility rules in std::regex_replace. (syntax documentation)
// format_no_copy 	    Do not copy un-matched strings to the output in std::regex_replace
// format_first_only 	Only replace the first match in std::regex_replace
//
// All constants, except for match_default and format_default, are bitmask elements. The match_default and format_default constants are empty bitmasks
//
/// NOTE:
// In C++11, these constants were specified with redundant keyword static,
// which was removed by C++14 via LWG issue 2053
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

/// NOTE:
// In C++11, these constants were specified with redundant keyword static,
// which was removed by C++14 via LWG issue 2053

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
