/**
std::basic_filebuf
**/

/// protected  member :
/// 12_std::basic_filebuf::seekoff
/**

protected:
virtual  pos_type seekoff ( off_type off, std::ios_base::seekdir dir, std::ios_base::openmode = std::ios_base::in|std::ios_base::out);

Reposition the file pointer, if possible, to the position that corresponds to exactly off character
form beginning, end, or current position of the file ( depending on the value of dir). if the associated
file is not open ( is_open() == false, files immediately. if the multibyte character encoding is state-
dependent ( codecvt::encoding() return -1) or variable-length ( codecvt::encoding() returned 0) and the
offset off is not 0, fails immediately: this function cannot determine the number of bytes that correspond
to off character.
if dir is not std::basic_ios::cur or te offset off is not 0, and the most resent operation done on this
filebuf object was output ( that is, either the put buffer is not empty, or the most recently called function
was overflow()), then calls std::codecvt::unshift to determine the unshift sequence necessary, and write that
sequence to the file by calling overflow(). Then converts the argument dir to a value whence of type int as follow

Value of dir                Value of whence
std::basic::ios::beg        SEEK_SET
std::basic::ios::end        SEEK_END
std::basic::ios::cur        SEEK_CUR

**/
#include <iostream>
#include <locale>
#include <fstream>

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        /// prepare a 10-byte file holding 4 characters in UTF-8
        std::ofstream ("test_seekoff.txt") << u8"z\u000df\u6c34\U0001d10b"; /// or u8"z...

        /// open using a non-converting encoding
        std::ifstream ifs1("test_seekoff.txt");
        std::cout<<"ifs1's locale's encoding() returns: "
                 <<std::use_facet<std::codecvt<char, char,std::mbstate_t>>(ifs1.getloc()).encoding() <<std::endl
                 <<"pubseedoff(3,  beg) returns: "<<ifs1.rdbuf()->pubseekoff(3, std::ios_base::beg) << std::endl
                 <<"pubseekoff(0 , end) returns: "<<ifs1.rdbuf()->pubseekoff(0, std::ios_base::end) << std::endl;
        /// open using UTF-8
        std::wifstream wifs("test_seekoff.txt");
        wifs.imbue(std::locale("en_US.UTF-8"));
        std::cout<<"wifs's lacale's encoding() returns: "<<std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(wifs.getloc()).encoding()<<std::endl
                 <<"pubseekoff(3, beg) returns: " <<wifs.rdbuf()->pubseekoff(3, std::ios_base::beg) << std::endl
                 <<"pubseekoff(3, end) returns: " <<wifs.rdbuf()->pubseekoff(3, std::ios_base::end) << std::endl;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

