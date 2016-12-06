/**
std::basic_ios
**/

#include <iostream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_ios::good
/**
bool good() const;

Explanation
Return true if the the most recent I/O operation on the stream completed successfully.
Specifically, returns result of rdstate() = 0;
**/

int main() {
    {
        /// mine : did not know
        int i;
        cin>>i;
        if(cin.good())
            cout<<i<<endl;
        else
            cout<<"You enter incorrect input\n";
        cout<<endl;
        std::string s;
        cin>>s;
        std::ios_base::iostate t;
        t = std::ios_base::goodbit;
        cin.setstate(t);
        if(cin.good())
            cout<<s<<' '<<cin.good()<<endl;
        else
            cout<<"you enter incorrect input\n";

    }
    {
        /// the site no sample
    }
}





















