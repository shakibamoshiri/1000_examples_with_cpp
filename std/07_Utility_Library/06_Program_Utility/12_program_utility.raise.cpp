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
/// std::raise
//  int raise (int sig);
//
//  Sends signal 'sig'  to the program.
//  The signal handler (specified using the std::signal() function)
//  is invoked.
//  If the used-defined signal handing strategy is not set using std::signal()
//  yet, it is implementation-defined whether the signal will be ignored or
//  default handler will be invoked.

#include <iostream>
#include <csignal>

void signal_handler (int signal){ std::cout << "receiving signal: " << signal << '\n'; }

int main (){

    // install a signal handler
    std::signal( SIGTERM, signal_handler );

    std::cout << "sending signal " << SIGTERM << std::endl;
    std::raise( SIGTERM );



}

