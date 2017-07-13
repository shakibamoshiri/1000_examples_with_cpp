/*
            Program support Utility
            ***********************

Signals:

    > signal            : sets a signal handler for a particular signal
    > raise             : runs the signal handler for a particular signal
    > sig_atomic_t      : the integer type that can be accessed as an atomic entity form an asynchronous signal handler
    > SIG_DFL, SIG_IGN  : defines signal handling strategies
    > SIG_ERR           : returns value of signal specifying that an error was encountered

*/
/// std::signal
//  void (*signal (int sig, void (*handler)(int))) (int);
//
//  Sets the error handler for signal 'sig'. The signal handler can be set
//  so that default handling will occur, signal is ignored, or a user-defined
//  function is called.

#include <iostream>
#include <csignal>

namespace { volatile std::sig_atomic_t gSignalStatus; }

void signal_handler (int signal){ gSignalStatus = signal; }

int main (){

    // install a signal handler
    std::signal( SIGINT, signal_handler );

    std::cout << "Signal Value: " << gSignalStatus << '\n';
    std::cout << "sending signal " << SIGINT << '\n';

    std::raise( SIGINT );
    std::cout << "Signal Value: " << gSignalStatus << '\n';

}

