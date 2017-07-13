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
///  std::regex_constants::syntax_option_type
// The syntax_option_type is a BitmaskType that contains options that govern how regular expressions behave.
// The possible values for this type (icase, optimize, etc.) are duplicated inside std::basic_regex.

// Value 	    Effect(s)
// icase 	    Character matching should be performed without regard to case.
// nosubs 	    When performing matches, all marked sub-expressions (expr) are
//              treated as non-marking sub-expressions (?:expr). No matches are
//              stored in the supplied std::regex_match structure and mark_count() is zero
// optimize 	Instructs the regular expression engine to make matching faster,
//              with the potential cost of making construction slower. For example,
//              this might mean converting a non-deterministic FSA to a deterministic FSA.
// collate  	Character ranges of the form "[a-b]" will be locale sensitive.
//ECMAScript 	Use the Modified ECMAScript regular expression grammar
//basic 	    Use the basic POSIX regular expression grammar (grammar documentation).
//extended  	Use the extended POSIX regular expression grammar (grammar documentation).
// awk  	    Use the regular expression grammar used by the awk utility in POSIX (grammar documentation)
// grep 	    Use the regular expression grammar used by the grep utility in POSIX.
//              This is effectively the same as the basic option with the addition of newline '\n' as an alternation separator.
// egrep 	    Use the regular expression grammar used by the grep utility, with the -E option,
//              in POSIX. This is effectively the same as the extended option with the
//              addition of newline '\n' as an alternation separator in addtion to '|'.
//
// At most one grammar option must be chosen out of ECMAScript, basic, extended, awk, grep, egrep.
// If no grammar is chosen, ECMAScript is assumed to be selected. The other options serve as
// modifiers, such that std::regex("meow", std::regex::icase) is equivalent to
// std::regex("meow", std::regex::ECMAScript|std::regex::icase)
//
// Notes
// Because POSIX uses "leftmost longest" matching rule
// (the longest matching subsequence is matched, and if there are several such subsequences, the first one is matched),
// it is not suitable, for example, for parsing markup languages: a POSIX regex such as "<tag[^>]*>.*</tag>"
// would match everything from the first "<tag" to the last "</tag>", including every "</tag>" and "<tag>"
// inbetween. On the other hand, ECMAScript supports non-greedy matches, and the ECMAScript
// regex "<tag[^>]*>.*?</tag>" would match only until the first closing tag.

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

    std::string str("zzxayyzz");

    std::regex rx1(".*(a|xayy)");      // ECMA
    std::regex rx2(".*(a|xayy)",std::regex::extended);  // POSIX

    endl(std::cout<<"Searching for .*(a|xayy) in zzxayyzz:");

    std::smatch m;    // string match

    std::regex_search(str,m,rx1);
    endl(std::cout<<"ECMA (depth first search) match: "<<m[0]); // ADL method using output

    std::regex_search(str,m,rx2);
    endl(std::cout<<"POSIX (leftmost longest) match:  "<<m[0]); // ADL method using output


    /// NOTE
    // the output is wrong for me, why? I do not know, or may be for you.
    // the output should be:
    //
    // Searching for .*(a|xayy) in zzxayyzz:
    // ECMA  : zzxa
    // POSIX : zzxayy
    //
    // for me is:
    // ECMA  : zzxa
    // POSIX : zzxa


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
