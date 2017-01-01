/*
            Date and Time
            *************

    1. duration
        (constructor)   constructs new duration
        operator=       assigns the contents
        count           returns the count of ticks
        zero            returns the special duration value zero
        min             returns the special duration value min
        max             returns the special duration value max
        operator+
        operator-	        implements unary + and unary -
        operator++
        operator++(int)
        operator--
        operator--(int)     increments or decrements the tick count
        operator+=
        operator-=
        operator*=
        operator/=
        operator%=  	    implements compound assignment between two durations

        Non-member functions
        std::common_type<std::chrono::duration>                 specializes the std::common_type trait
        operator+
        operator-
        operator*
        operator/
        operator%           implements arithmetic operations with durations as arguments

        operator==
        operator!=
        operator<
        operator<=
        operator>
        operator>=      compares two durations

        duration_cast   converts a duration to another, with a different tick interval

        floor(std::chrono::duration)    converts a duration to another, rounding down
        ceil(std::chrono::duration)     converts a duration to another, rounding up
        round(std::chrono::duration)    converts a duration to another, rounding to nearest, ties to even
        abs(std::chrono::duration)      obtains the absolute value of the duration

        Helper types
        Type 	Definition
        std::chrono::nanoseconds 	duration<signed integer type of at least 64 bits, std::nano>
        std::chrono::microseconds 	duration<signed integer type of at least 55 bits, std::micro>
        std::chrono::milliseconds 	duration<signed integer type of at least 45 bits, std::milli>
        std::chrono::seconds 	    duration<signed integer type of at least 35 bits>
        std::chrono::minutes 	    duration<signed integer type of at least 29 bits, std::ratio<60>>
        std::chrono::hours 	        duration<signed integer type of at least 23 bits, std::ratio<3600>>

        Note: each of the predefined duration types covers a range of at least ±292 years.

        Helper classes
        treat_as_floating_point     indicates that a duration is convertible to duration with different tick period
        duration_values             constructs zero, min, and max values of a tick count of given type

        Defined in inline namespace std::literals::chrono_literals
        operator""h             A std::chrono::duration literal representing hours
        operator""min           A std::chrono::duration literal representing minutes
        operator""s             A std::chrono::duration literal representing seconds
        operator""ms            A std::chrono::duration literal representing milliseconds
        operator""us            A std::chrono::duration literal representing microseconds
        operator""ns            A std::chrono::duration literal representing nanoseconds

*/
/// std::chrono::treat_as_floating_point
//  The std::chrono::treat_as_floating_point trait helps determine if a
//  duration can be converted to another duration with a different tick period.
//
// Implicit conversions between two durations normally depends on the tick
//  period of the durations. However, if std::chrono::treat_as_floating_point<Rep>::value == true.


#include <iostream>
#include <chrono>
#include <thread>

void timed_piece_of (){
    std::chrono::milliseconds ms (3);
    std::this_thread::sleep_for( ms );
} // end of timed_piece_of

int main (){

    // record the starting point
    std::chrono::time_point< std::chrono::high_resolution_clock > start =
        std::chrono::high_resolution_clock::now();
    // you can use auto start = blah, blah, blah :)

    std::cout << "running some timed piece of code ...\n";
    timed_piece_of();

    // record the ending point
    std::chrono::time_point< std::chrono::high_resolution_clock > end =
        std::chrono::high_resolution_clock::now();

    // a floating-point milliseconds type
    using fp_milliseconds = std::chrono::duration< float, std::chrono::milliseconds::period >;

    static_assert( std::chrono::treat_as_floating_point< fp_milliseconds::rep >::value, "Rep required to be floating-point" );

    // NOTE:
    // that implicit conversion is not allowed here:
    std::chrono::milliseconds integer_ms = std::chrono::duration_cast< std::chrono::milliseconds >( end - start ); // subtract start from end
    // or
    // auto integer_ms = std::chrono::duration_cast< std::chrono::milliseconds >( end - start );

    // NOTE:
    // that implicit conversion is allowed here:
    std::chrono::duration< float, std::chrono::milliseconds::period > float_ms = fp_milliseconds( end - start ); // subtract start from end
    // or:
    // auto float_ms = fp_milliseconds( end - start );
    // fp_milliseconds float_ms = fp_milliseconds( end - start );

    std::cout << "time in milliseconds in default rep: "
              << integer_ms.count() << '\n';

    std::cout << "time is milliseconds, using floating-point rep: "
              << float_ms.count() << '\n';
}

/* output for me:

running some timed piece of code ...
time in milliseconds in default rep: 3
time is milliseconds, using floating-point rep: 3.13184

*/
