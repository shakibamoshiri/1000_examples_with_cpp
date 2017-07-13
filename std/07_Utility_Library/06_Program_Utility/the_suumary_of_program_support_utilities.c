/*
            Program Support Utility
            ***********************

Program Termination:
The following functions manage program termination and resource cleanup
(defined in header <cstdlib>)

    > abort             : causes abnormal program termination (without cleaning up)
    > exit              : causes normal program termination with cleaning up
    > quick_exit        : causes quick program termination without completely cleaning up
    > _Exit             : causes normal program termination without cleaning up
    > atexit            : registers a function to be called on std::exit() invocation
    > at_quick_exit     : registers a function to be called on quick_exit invocation
    > EXIT_SUCCESS      : indicate program execution execution status
    > EXIT_FAILURE      : same as above

Communicating with the Environment:

    > system            : calls the host environment's command processor
    > getenv            : access the list environment variables

Signals:

    > signal            : sets a signal handler for a particular signal
    > raise             : runs the signal handler for a particular signal
    > sig_atomic_t      : the integer type that can be accessed as an atomic entity form an asynchronous signal handler
    > SIG_DFL, SIG_JGN  : defines signal handling strategies
    > SIG_ERR           : returns value of signal specifying that an error was encountered

Signal Types

    > SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEG, SITTERM : define signal types

Non-local Jumps (in header <csetjmp>)

    > setjmp            : saves the context
    > longjmp           : jumps the specified location

Types:

    > jmp_buf           : execution context type

*/

