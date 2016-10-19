/**
std::basic_ios
**/

#include <iostream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_ios::eof
/**
bool eof() const;

Explanation
Return true if the associated stream has reached end-of-file.
Specifically, return true if eofbit is set in rdstate().

**/

int main() {
    {
        /// mine : did not know
    }
    {
        /// the site sample
        std::ifstream file("test.txt");
        if(!file){
            cout<<"File opening failed\n";
            return EXIT_FAILURE;
        }
        for(char n; file>>n; ){
            cout<<n<<' ';
        }
        cout<<endl;
        if(file.bad())
            cout<<"I/O error while reading\n";
        else if (file.eof())
            cout<<"End of file reached successfully\n";
        else if(file.fail())
            cout<<"Non=integer data encountered\n";
    }
}





















