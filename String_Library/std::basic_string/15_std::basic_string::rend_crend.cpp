#include <iostream>
#include <string>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::rend, std::basic_string::crend
/*
1 . reverse_iterator rend();
2 . const_reverse_iterator rend() const;
3 . const_reverse_iterator crend() const;

*/
 /// reverse iterator to the character following the last character


int main() {
    { /// 1. reverse_iterator rend();
        std::basic_string<char> s ("a b d e f g");
        std::string::reverse_iterator ri_s = s.rend();

        --ri_s;

        *ri_s  = 'A'; /// changing 'a' to 'A'

        cout<<*ri_s<<endl;

        while(*ri_s){
            cout<<*ri_s<<' ';
            --ri_s;
        }

    }
    { /// 2. const_reverse_iterator rend() const;
        std::string s ("shakiba_moshiri");

        std::string::const_reverse_iterator cri_s = s.rend();

        cri_s--;

        cout<<*cri_s<<endl;

       /// *cri_s = 'S'; ERROR : assignment of read-only location cri_s ...
    }
    { /// 3. the same is above sample
        ///
    }
    { /// Sample of en.c plus plus reference
        std::string s ("A man, a plan, a canal : Panama");
        {
            std::string t;
            std::copy(s.rbegin(), s.rend(), std::back_inserter(t));
            cout<<t<<endl;
        }
        {
            std::string t;
            std::copy(std::crbegin(s), std::crend(s),std::back_inserter(t));
            cout<<t<<endl;
        }
    }
}


















