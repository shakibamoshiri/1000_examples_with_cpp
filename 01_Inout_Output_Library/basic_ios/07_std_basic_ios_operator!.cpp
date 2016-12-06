/**
std::basic_ios
**/

#include <iostream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_ios::operator!
/**
bool operator!() const;

Explanation
Return true if error had occurred on the associated stream.
Specifically, return true if beadbit or failbit is set in rdstate().
**/

int main() {
    {
        /// mine : did not know
    }
    {
        /// the site sample
        std::ifstream file("test_bad.txt");
        if(!file){
            cout<<"File opening failed\n";
            return EXIT_FAILURE;
        }
        for(char n; file>>n; ){ /// It must be char and not int
            cout<<n<<' ';
        }
        cout<<endl;
        file.setstate(std::ios_base::goodbit);
        if(!file.bad())
            cout<<"Occurred bad bit\n";
        /// because of using ! operator, otherwise no file.bad bit.
    }
}





















