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
/// std::common_type (std::chrono::duration)
//
//  Exposes the  type named type, which is the common type of
//  two std::chrono::durations.
//
//  NOTE:
//  The period of the resulting duration is the greatest common
//  divisor or Period1 and Period2. (Period1 and 2 are argument)
//  Also, std::common_type<> is specialized for std::chrono::duration

#include <iostream>
#include <chrono>

/*
std::chrono already finds the greatest common divisor,
likely using std::common_type <>.
We make the type deduction externally
*/

template<typename T, typename S>
auto duration_diff (const T& t, const S& s) -> typename std::common_type<T, S>::type {

    typedef typename std::common_type<T, S>::type Common;

    return Common(t) - Common(s);

} // the end of duration_diff


int main (){

    typedef std::chrono::milliseconds milliseconds;
    typedef std::chrono::microseconds microseconds;

    auto ms = milliseconds(30);
    auto us = microseconds(1100);

    std::cout << ms.count() << " ms - "
              << us.count() << " us = "
              << duration_diff( ms, us ).count() << '\n';

}

/* output for me:

30 ms - 1100 us = 28900

*/
