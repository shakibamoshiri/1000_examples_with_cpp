/*

A review of algorithm library

Other( or miscellaneous )

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// next_permutation
//  Transform range to the next permutation.

// return is: boolean.

template< typename T, unsigned int N >
T* end_of(T ( &array )[ N ] ){
    return array + N;
}


int main(){

    char array[] = "hello";
    char* begin_array = array;
    char* end_array   = end_of( array );

    while( std::next_permutation( begin_array, end_array ) ){
        for( const char chr : array )
            std::cout << chr;

        std::cout << '\n';
    }

}

/* output


helol
helol
heoll
heoll
heoll
hlelo
hleol
hlleo
hlloe
hloel
hlole
hlelo
hleol
hlelo
hlelo
hleol
hleol
hlleo
hlloe
hlleo
hlleo
hlloe
hlloe
hloel
hlole
hloel
hloel
hlole
hlole
hoell
holel
holle
hoell
hoell
hoell
holel
holle
holel
holel
holle
holle
lehlo
lehol
lelho
leloh
leohl
leolh
lhelo
lheol
lhleo
lhloe
lhoel
lhole
lleho
lleoh
llheo
llhoe
lloeh
llohe
loehl
loelh
lohel
lohle
loleh
lolhe
lehlo
lehol
lelho
leloh
leohl
leolh
lehlo
lehol
lehlo
lehlo
lehol
lehol
lelho
leloh
lelho
lelho
leloh
leloh
leohl
leolh
leohl
leohl
leolh
leolh
lhelo
lheol
lhleo
lhloe
lhoel
lhole
lhelo
lheol
lhelo
lhelo
lheol
lheol
lhleo
lhloe
lhleo
lhleo
lhloe
lhloe
lhoel
lhole
lhoel
lhoel
lhole
lhole
lleho
lleoh
llheo
llhoe
lloeh
llohe
lleho
lleoh
lleho
lleho
lleoh
lleoh
llheo
llhoe
llheo
llheo
llhoe
llhoe
lloeh
llohe
lloeh
lloeh
llohe
llohe
loehl
loelh
lohel
lohle
loleh
lolhe
loehl
loelh
loehl
loehl
loelh
loelh
lohel
lohle
lohel
lohel
lohle
lohle
loleh
lolhe
loleh
loleh
lolhe
lolhe
oehll
oelhl
oellh
ohell
ohlel
ohlle
olehl
olelh
olhel
olhle
olleh
ollhe
oehll
oelhl
oellh
oehll
oehll
oehll
oelhl
oellh
oelhl
oelhl
oellh
oellh
ohell
ohlel
ohlle
ohell
ohell
ohell
ohlel
ohlle
ohlel
ohlel
ohlle
ohlle
olehl
olelh
olhel
olhle
olleh
ollhe
olehl
olelh
olehl
olehl
olelh
olelh
olhel
olhle
olhel
olhel
olhle
olhle
olleh
ollhe
olleh
olleh
ollhe
ollhe

Process returned 0 (0x0)   execution time : 0.035 s
Press ENTER to continue.



*/
