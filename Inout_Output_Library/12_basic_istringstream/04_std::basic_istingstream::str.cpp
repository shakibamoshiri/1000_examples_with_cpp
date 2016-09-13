/**
std::basic_istringstream
**/
/// 04_std::basic_istringstream::str
/**
std::basic_string<CharT,Traits,Allocator> str() const;
void str( std::basic_string<CharT,Traits,Allocator>& new_str );

Manages the contents of the underlying string object.
1)  Returns a copy of the underlying string as if by calling rdbuf()-str().
2)  Returns the contents of the underlying string as if calling redbuf()->str(new_str).


**/
#include <iostream>
#include <sstream>
#include <fstream>
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        int n;
        std::istringstream isbuf; /// could also use isbuf("1 2")
        isbuf.str("1 2");
        isbuf >> n;
        std::cout<<"After reading the first int from \"1 2\", the int is: "
                 <<n <<", str(): \""<<isbuf.str()<<"\"\n";

        std::ostringstream osbuf("1 2");
        osbuf << -9;
        std::cout<<"osbuf << 4 : "<<osbuf.rdbuf()->str()<<std::endl;
        osbuf << -8;
        std::cout<<"osbuf << 4 : "<<osbuf.rdbuf()->str()<<std::endl;
        osbuf << -7;
        std::cout<<"osbuf << 4 : "<<osbuf.rdbuf()->str()<<std::endl;

        std::ostringstream osbuf_ate("1 2", std::ios_base::ate);
        osbuf_ate<<'-';
        osbuf_ate << 3 ;
        std::cout<<"osbuf_ate(\"1 2\"): "<<osbuf_ate.rdbuf()->str()<<std::endl;

    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
