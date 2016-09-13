
#include <iostream>
struct oneBit {
    unsigned int a:1;   // 0..1
    unsigned int b:2;   // 0..3
    unsigned int c:3;   // 0..7
    unsigned int d:4;   // 0..15

    unsigned int e:8;   // 0..255
    unsigned int f:9;   // 0..511
    unsigned int j:10;  // 0..1023
};

int main(){
    oneBit one;
    one.a=1;        // more than 1 is overflow      : 2^1
    one.b=3;        // more than 3 is overflow      : 2^2
    one.c=7;        // more than 7 is overflow      : 2^3
    one.d=15;       // more than 15 is overflow     : 2^4

    one.e=255;      // more than 255 is overflow    : 2^8
    one.f=511;      // more than 512 is overflow    : 2^9
    one.j=1023;     // more than 1023 is overflow   : 2^10

    std::cout<<one.j<<std::endl;
}
