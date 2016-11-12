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
/// std::regex_traits::value
// Determines the value represented by the digit 'ch' in the numeric base
// 'radix' given the currently imbued locale. This function is called by
// std::regex when processing Quantifier such as {1} or {2,5},
// BackReference such \1. and hexadecimal and Unicode character escapes.
//
// Parameters:
// ch       the character that may represent a digit
// radix    either 8,10, or 16

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
#include <map>

// This custom regex traits allows japanese numerals
struct jnum_traits : std::regex_traits<wchar_t>
{
    static std::map<wchar_t, int> data;
    int value(wchar_t ch, int radix ) const {
        wchar_t up = std::toupper(ch, getloc());
        return data.count(up) ? data[up] : regex_traits::value(ch, radix);
    }
};
std::map<wchar_t, int> jnum_traits::data = {{L'〇',0}, {L'一',1}, {L'二',2},
                                            {L'三',3}, {L'四',4}, {L'五',5},
                                            {L'六',6}, {L'七',7}, {L'八',8},
                                            {L'九',9}, {L'Ａ',10}, {L'Ｂ',11},
                                            {L'Ｃ',12}, {L'Ｄ',13}, {L'Ｅ',14},
                                            {L'Ｆ',15}};


int main(){

    std::locale::global(std::locale("ja_JP.utf8"));
    std::wcout.sync_with_stdio(false);
    std::wcout.imbue(std::locale());

    std::wstring in = L"風";

    if(std::regex_match(in, std::wregex(L"\\u98a8")))
        std::wcout << "\\u98a8 matched " << in << '\n';

    if(std::regex_match(in, std::basic_regex<wchar_t, jnum_traits>(L"\\u九八ａ八")))
        std::wcout << L"\\u九八ａ八 with custom traits matched " << in << '\n';
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
