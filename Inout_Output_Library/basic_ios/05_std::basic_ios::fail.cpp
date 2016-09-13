/**
std::basic_ios
**/

#include <iostream>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_ios::fail
/**
bool fail() const;

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
        std::ifstream file("test.txt");
        if(!file){
            cout<<"File opening failed\n";
            return EXIT_FAILURE;
        }
        for(int n; file>>n; ){ /// It must be char and not int
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





















