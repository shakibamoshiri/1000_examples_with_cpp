/*
Miscellaneous:
    01 asm declaration
    02 extending the namespace std
    03 undefined behavior
    04 RAII ( Resource Acquisition Is Initialization )
    05 The rule of three / five / zero

    06 The as-if rule

    07 copy elision
    08 Empty base optimization
*/
//
//
/// 06 the as-if rule
// Allows any and all transformations that do not change the observable
// behavior of the program.
// for more detail read the main site.
//
//
//
/// 07 copy elision
// oxford:
// elision is a noun and elide is a verb: meaning: the leave out the sound of part of a word when you are pronouncing it.
// The 't' in "often" may be elided.
//
// Optimize out copy-and move-constructor, resulting in zere-copy pass-by-value semantic
// for more detail read the mine site.
//
//
// example
#include <iostream>
#include <vector>
struct Noisy {
    Noisy() { std::cout<<"constructed\n"; }
    Noisy(const Noisy&) { std::cout<<"copied\n"; }
    Noisy(Noisy&&) { std::cout<<"moved\n"; }
    ~Noisy() { std::cout<<"destructed\n"; }
};
std::vector<Noisy> f() {         // simple function
    std::vector<Noisy> v = std::vector<Noisy>(3);   // copy elision form temporary to v
    return v;                    // NRVO form v to the nameless temporary that is returned
                                 // if optimization are disabled. move constructor is called here.
}

void fn_by_val ( std::vector<Noisy> arg) {
    std::cout<<"arg.sizer() = "<<arg.size()<<std::endl;

}
int main(){
    std::vector<Noisy> v = f();     // copy elision form returned temporary to v
    fn_by_val(f());                 // and from temporary to the argument of fn_by_val()fn_by_val
}
