/**

**/

#include <iostream>
#include <string>

// simple pinter
// ptr<int>, becomes int*
// btr<char>, becomes char*
template<typename T> using ptr = T*;

// simple pointer to function that has two difference type or the same type
// like, int ( float ) => T ( * )( U )
// or , void ( int ) => T ( * )( U )
// or , int ( int ) => T ( * )( U )
template<typename T,typename U> using pfunc = T (*)(U); // this is declaration and not allowed to definition
                                                        // using pfunc = T (*)(U){return T} is wrong.


void print (int i){
    std::cout<<i<<std::endl;
}

float print(float f){
    return f;
}

const char* print(const char* s){
    return s;
}
int main(){
    int i = 100;

    // pointer to integer
    ptr<int> p = &i;
    *p = 10000;
    std::cout<<i<<std::endl;

    // pinter to const char*
    // it convert a const char to const char*
    // T = const char
    // become to T*, meaning const char*
    const char* name = "Shakib";
    ptr<const char> tempNmae = name;
    std::cout<<tempNmae<<std::endl;

    // pointer function to void (int)
    pfunc<void,int> f1 = print;
    f1(i);

    // pointer function to float (float)
    pfunc<float, float> f2 = print;
    std::cout<<f2(1.22)<<std::endl;

    // pointer to function const char* ( const char*)
    pfunc<const char*, const char*> f3 = print;
    std::cout<<f3("how are you today?")<<std::endl;

}









