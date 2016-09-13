#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::copy
/*
std::basic_string::copy
  C++  Strings library std::basic_string
size_type copy( CharT* dest,
                size_type count,
                size_type pos = 0) const;

Copies a substring [pos, pos+count) to character string pointed to by dest. If the requested substring lasts past the end of the string, or if count == npos, the copied substring is [pos, size()). The resulting character string is not null-terminated.
If pos > size(), std::out_of_range is thrown.

Parameters
dest	-	pointer to the destination character string
pos	-	position of the first character to include
count	-	length of the substring

Return value
number of characters copied

Exceptions
std::out_of_range if pos > size().
*/


int main() {
    {
        /// 1)
        std::string t("stupid cunt");
        char s[5];
        t.copy(s,5,0);
        cout<<s<<endl;
        cout<<t<<endl;
    }
    {
  std::string foo("quuuux");
  char bar[7];
  foo.copy(bar, sizeof bar);
  bar[6] = '\0';
  std::cout << bar << '\n';
}
}




















