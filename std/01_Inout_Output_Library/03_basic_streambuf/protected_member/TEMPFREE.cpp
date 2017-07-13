/**
std::basic_streambuf
**/


/// 35_std::basic_streambuf::pbackfail
/**

*  - eback() returns the beginning pointer for the input sequence
*  - gptr() returns the next pointer for the input sequence
*  - egptr() returns the end pointer for the input sequence

*  - pbase() returns the beginning pointer for the output sequence
*  - pptr() returns the next pointer for the output sequence
*  - epptr() returns the end pointer for the output sequence

      char_type* 		_M_in_beg;     ///< Start of get area.
      char_type* 		_M_in_cur;     ///< Current read area.
      char_type* 		_M_in_end;     ///< End of get area.
      char_type* 		_M_out_beg;    ///< Start of put area.
      char_type* 		_M_out_cur;    ///< Current put area.
      char_type* 		_M_out_end;    ///< End of put area.

      /// Current locale setting.
      locale 			_M_buf_locale;
**/
#include <iostream>
#include <sstream>
#include <array>
int main()
{
    {
        /// owner
        std::stringstream s("this is a test");
        s.rdbuf()->epptr();
    }
    {
        /// en.reference.com
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













