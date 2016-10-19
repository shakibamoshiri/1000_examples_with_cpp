/// ios_base

#include <iostream>
#include <string>





using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::iword
/*
long& iword (int index);

*/
struct FOO {
    static int foo_xalloc;
    std::string date;
    FOO (const std::string& s) : date(s) {}
};

int FOO::foo_xalloc = std::ios_base::xalloc();

std::ostream& operator<<(std::ostream& os,FOO& f){
    if(os.iword(FOO::foo_xalloc))
    /// if(os.iword(FOO::foo_xalloc == 1)) not wording
       return os << std::string(f.date.rbegin(), f.date.rend());
    else
        return os << f.date;
}

std::ios_base& rev (std::ios_base& os){
    os.iword(FOO::foo_xalloc) = !os.iword(FOO::foo_xalloc);
    return os;
}

int main() {
    {
        /// mine : did not know
    }
    {
        /// the site no sample : nope
        FOO f("example");
        cout << f << '\n' <<rev << f << '\n' << rev << f << '\n';
    }
}





















