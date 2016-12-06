/// ios_base

#include <iostream>
#include <string>
#include <locale>
#include <functional>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::ios_base::register_callback
/*

    void register_callback ( event_callback function , int index );

*/

typedef std::pair<std::string, std::size_t> cache_t;

void update_cache ( cache_t& cache , std::locale loc ){
    auto& fct = std::use_facet < std::messages<char> > (loc);
    std::messages_base::catalog cat = fct.open("sed", loc);
    cache.first = cat < 0 ? "" : fct.get(cat, 0, 0, "Memory exhausted");
    cache.second = std::hash<std::string>()(cache.first);
}

void true_callback (std::ios_base::event evt, std::ios_base& str, int inx ){
    if (evt == std::ios_base::imbue_event){
        cache_t* ptr = static_cast<cache_t*>(str.pword(inx));
        update_cache(*ptr, str.getloc());
    }
}

struct CacheSetup {
    CacheSetup (std::ostream& os, std::ios_base::event_callback f, cache_t* cache){
        int index = std::ostream::xalloc();
        os.pword(index) = cache ;
        os.register_callback(f, index);
        update_cache(*cache, os.getloc());
    }
};

struct S {};

std::ostream& operator<<(std::ostream& os, const S&){
    static cache_t cache;
    static CacheSetup setup (os, true_callback,&cache);
    return os << cache.first <<" : "<< cache.second;
}

int main() {
    {
        /// mine : did not know
    }
    {
        /// the site no sample
        std::locale loc("en_US.utf8");
        S s;
        cout.imbue(loc);
        cout<<s<<endl;

        cout.imbue(std::locale (loc, new std::messages_byname<char>
                                ("de_DE.utf8")));
        cout<<s<<endl;

        cout.imbue(std::locale (loc, new std::messages_byname<char>
                                ("ja_JP.utf8")));
        cout<<s<<endl;

        cout.imbue(std::locale (loc, new std::messages_byname<char>
                                ("ru_RU.utf8")));
        cout<<s<<endl;
    }
}





















