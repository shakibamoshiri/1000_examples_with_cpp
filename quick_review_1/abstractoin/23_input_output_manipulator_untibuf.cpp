/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <chrono>




int main(){

    std::unitbuf(std::cout); // enable automatic flushing

    auto start = std::chrono::high_resolution_clock::now();

    volatile int stuff = 0;
    for(int a = 0; a < 5; ++a){
        for(int b = 0; b < 10000; ++b)
            for(int c = 0; c < 10000; ++c)
                stuff = b * c;
        auto end = std::chrono::high_resolution_clock::now();
        // auto time = (end - start); or using end - strat below
        std::cout << "...(" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms)...";
    }

}
