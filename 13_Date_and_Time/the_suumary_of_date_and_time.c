/*
            Date and Time
            *************


    C++ includes support for two types of time manipulation

*   The chrono library, a flexible collation of types that track time with
    varying degrees of precision (e.g. std::chrono::time_point).

*   C-style date and time library (e.g. std::time)

---------------------------------------------------------------------------
chrono library:
    The chrono library defines three main types (durations,clocks,and time points)
    as well as utility functions and command typedefs.

    Duration:
    A duration consists of a span of time, defined as some number of ticks of some
    time unit. For example, "42 seconds" could be represented by a duration consisting
    of 42 ticks of a 1-second time unit.

    1. duration

        > (constructor)   constructs new duration
        > operator=       assigns the contents
        > count           returns the count of ticks
        > zero            returns the special duration value zero
        > min             returns the special duration value min
        > max             returns the special duration value max
        > operator+
        > operator-	        implements unary + and unary -
        > operator++
        > operator++(int)
        > operator--
        > operator--(int)     increments or decrements the tick count
        > operator+=
        > operator-=
        > operator*=
        > operator/=
        > operator%=  	    implements compound assignment between two durations

        Non-member functions
        > std::common_type<std::chrono::duration>                 specializes the std::common_type trait
        > operator+
        > operator-
        > operator*
        > operator/
        > operator%           implements arithmetic operations with durations as arguments

        > operator==
        > operator!=
        > operator<
        > operator<=
        > operator>
        > operator>=      compares two durations

        > duration_cast   converts a duration to another, with a different tick interval

        > floor(std::chrono::duration)    converts a duration to another, rounding down
        > ceil(std::chrono::duration)     converts a duration to another, rounding up
        > round(std::chrono::duration)    converts a duration to another, rounding to nearest, ties to even
        > abs(std::chrono::duration)      obtains the absolute value of the duration

        Helper types
        Type 	Definition
        > std::chrono::nanoseconds 	duration</*signed integer type of at least 64 bits, std::nano>
        > std::chrono::microseconds 	duration</*signed integer type of at least 55 bits, std::micro>
        > std::chrono::milliseconds 	duration</*signed integer type of at least 45 bits, std::milli>
        > std::chrono::seconds 	    duration</*signed integer type of at least 35 bits>
        > std::chrono::minutes 	    duration</*signed integer type of at least 29 bits, std::ratio<60>>
        > std::chrono::hours 	        duration</*signed integer type of at least 23 bits, std::ratio<3600>>

        Note: each of the predefined duration types covers a range of at least ±292 years.

        Helper classes
        > treat_as_floating_point     indicates that a duration is convertible to duration with different tick period
        > duration_values             constructs zero, min, and max values of a tick count of given type

        Defined in inline namespace std::literals::chrono_literals
        > operator""h             A std::chrono::duration literal representing hours
        > operator""min           A std::chrono::duration literal representing minutes
        > operator""s             A std::chrono::duration literal representing seconds
        > operator""ms            A std::chrono::duration literal representing milliseconds
        > operator""us            A std::chrono::duration literal representing microseconds
        > operator""ns            A std::chrono::duration literal representing nanoseconds


    2. Clocks:
    A clock consist of a starting point (or epoch) and a tick rate. For example, a clock
    may have an epoch of January 1, 1970 and tick every second. C++ defines three clock types:

        2.1 system_clock
            Member types
            rep 	    signed arithmetic type representing the number of ticks in the clock's duration
            period 	a   std::ratio type representing the tick period of the clock, in seconds
            duration 	std::chrono::duration<rep, period>, capable of representing negative durations
            time_point 	std::chrono::time_point<std::chrono::system_clock>

            Member constants
            constexpr bool is_steady    true if the time between ticks is always constant, i.e. calls to now()
                                        return values that increase monotonically even in case of some external clock adjustment

            Member functions
            > now             returns a std::chrono::time_point representing the current point in time
            > to_time_t       converts a system clock time point to std::time_t
            > from_time_t     converts std::time_t to a system clock time point

        2.2 steady_clock
            Member types
            Member type 	Definition
            rep 	        arithmetic type representing the number of ticks in the clock's duration
            period      	a std::ratio type representing the tick period of the clock, in seconds
            duration 	    std::chrono::duration<rep, period>
            time_point 	    std::chrono::time_point<std::chrono::steady_clock>
            Member constants
            constexpr bool is_steady    steady clock flag, always true

            Member functions
            > now             returns a time_point representing the current value of the clock


        2.3 high_resolution_clock
            Member types
            Member type 	Definition
            rep 	        arithmetic type representing the number of ticks in the clock's duration
            period 	        a std::ratio type representing the tick period of the clock, in seconds
            duration 	    std::chrono::duration<rep, period>
            time_point 	    std::chrono::time_point<std::chrono::high_resolution_clock>

            Member constants
            constexpr bool is_steady    true if the time between ticks is always constant, i.e. calls to now()
                                        return values that increase monotonically even in case of some external
                                        clock adjustment
            Member functions
            > now             returns a std::chrono::time_point representing the current value of the clock

    3. Time point
    A time point is a duration fo time that had passed since the epoch of specific clock
    (defined in header <chrono>)
    time_point
        Member types
        Member type 	Definition
        clock 	        Clock, the clock on which this time point is measured
        duration 	    Duration, a std::chrono::duration type used to measure the time since epoch
        rep 	        Rep, an arithmetic type representing the number of ticks of the duration
        period 	        Period, a std::ratio type representing the tick period of the duration

        Member functions
        (constructor)       constructs a new time point
        time_since_epoch    returns the time point as duration since the start of its clock
        operator+=
        operator-=          modifies the time point by the given duration
        min                 returns the time point corresponding to the smallest duration
        max                 returns the time point corresponding to the largest duration

        Non-member functions
        std::common_type<std::chrono::time_point>       specializes the std::common_type trait

        operator+
        operator-   modifies the time point by the given duration

        operator==
        operator!=
        operator<
        operator<=
        operator>
        operator>=  compares two time points

        time_point_cast                     converts a time point to another time point on the same clock, with a different duration
        floor(std::chrono::time_point)      converts a time_point to another, rounding down
        ceil(std::chrono::time_point)       converts a time_point to another, rounding up
        round(std::chrono::time_point)      converts a time_point to another, rounding to nearest, ties to even


C-style data and time library
    Also provided are the C-style data and time functions, such as std::time_t, std::difftime,
    and CLOCKS_PER_SEC.
        Functions
        Defined in header <ctime>

        Time manipulation
        difftime        computes the difference between times
        time            returns the current time of the system as time since epoch
        clock           returns raw processor clock time since the program is started

        Format conversions
        asctime         converts a tm object to a textual representation
        ctime       	converts a time_t object to a textual representation
        strftime        converts a tm object to custom textual representation
        wcsftime        converts a tm object to custom wide string textual representation
        gmtime          converts time since epoch to calendar time expressed as Universal Coordinated Time
        localtime       converts time since epoch to calendar time expressed as local time
        mktime          converts calendar time to time since epoch

        Constants
        CLOCKS_PER_SEC  number of processor clock ticks per second

        Types
        tm              calendar time type
        time_t          time since epoch type
        clock_t         process running time


*/

/// some useful information:
std::chrono::duration
hours	        signed integral type of at least 23 bits	ratio<3600,1>
minutes	        signed integral type of at least 29 bits	ratio<60,1>
seconds	        signed integral type of at least 35 bits	ratio<1,1>
milliseconds	signed integral type of at least 45 bits	ratio<1,1000>
microseconds	signed integral type of at least 55 bits	ratio<1,1000000>
nanoseconds	    signed integral type of at least 64 bits	ratio<1,1000000000>
