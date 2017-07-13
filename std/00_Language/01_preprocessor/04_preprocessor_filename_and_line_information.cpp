///
/// preprocessor
///
/// filename and line information
/**
#line lineno
#line lineno "filename"
1.  Change the current preprocessor line number to lineno.
    Expansions of the macro __LINE__ beyond this point will
    expend to linono plus the number of actual source code
    lines encountered since.
2.  Also changes the current preprocessor file name. Expansions
    of the macro __FILE__ from this point will produce filename.

**/

#include <iostream>
#include <cassert>
#define FNAME "test.cc"

int main(){
    { /// my sample
    }
    { /// en.reference.com
        #line 777 FNAME
        assert(2+2 == 5 );
    }

}
