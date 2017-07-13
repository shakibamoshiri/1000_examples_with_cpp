/*
            Error Handling
            **************

5.  System Error
    The header <system_error> defines types and functions used to report error
    conditions origination from the operating system, stream I/O, std::future
    or other low-level APIs.

        > error_category    : base class for errors categories
        > generic_category  : identifies the generic error category
        > system_category   : identifies the operating system error category
        > error_condition   : holds a portable error code
        > errc              : the std::error_condition enumeration listing all standard <cerror> macro constants
        > error_code        : holds a platform-dependent error code
        > error_system      : exception class used to report conditions that have an error_code
*/
/// std::errc
//  The scoped enumeration std::errc defines the values of
//  portable error conditions that correspond to the POSIX error code.

#include <iostream>
#include <system_error>
#include <thread>


int main() {

    try { std::thread().detach(); }  // detaching a non-a-thread
    catch (const std::system_error& er){
        std::cout << "caught a system error\n";

        if (er.code() == std::errc::invalid_argument) std::cout << "The error code condition is std::errc::invalid_argument\n";

        std::cout << "The error description is: " << er.what() << std::endl;
    }

}


/*

Member constants
Constant 	Explanation
address_family_not_supported 	error condition corresponding to POSIX code EAFNOSUPPORT
address_in_use 	                error condition corresponding to POSIX code EADDRINUSE
address_not_available       	error condition corresponding to POSIX code EADDRNOTAVAIL
already_connected 	            error condition corresponding to POSIX code EISCONN
argument_list_too_long      	error condition corresponding to POSIX code E2BIG
argument_out_of_domain      	error condition corresponding to POSIX code EDOM
bad_address                 	error condition corresponding to POSIX code EFAULT
bad_file_descriptor          	error condition corresponding to POSIX code EBADF
bad_message                 	error condition corresponding to POSIX code EBADMSG
broken_pipe                 	error condition corresponding to POSIX code EPIPE
connection_aborted             	error condition corresponding to POSIX code ECONNABORTED
connection_already_in_progress 	error condition corresponding to POSIX code EALREADY
connection_refused          	error condition corresponding to POSIX code ECONNREFUSED
connection_reset 	            error condition corresponding to POSIX code ECONNRESET
cross_device_link 	            error condition corresponding to POSIX code EXDEV
destination_address_required 	error condition corresponding to POSIX code EDESTADDRREQ
device_or_resource_busy 	    error condition corresponding to POSIX code EBUSY
directory_not_empty 	        error condition corresponding to POSIX code ENOTEMPTY
executable_format_error     	error condition corresponding to POSIX code ENOEXEC
file_exists 	                error condition corresponding to POSIX code EEXIST
file_too_large              	error condition corresponding to POSIX code EFBIG
filename_too_long           	error condition corresponding to POSIX code ENAMETOOLONG
function_not_supported      	error condition corresponding to POSIX code ENOSYS
host_unreachable 	            error condition corresponding to POSIX code EHOSTUNREACH
identifier_removed          	error condition corresponding to POSIX code EIDRM
illegal_byte_sequence       	error condition corresponding to POSIX code EILSEQ
inappropriate_io_control_operation 	error condition corresponding to POSIX code ENOTTY
interrupted 	                error condition corresponding to POSIX code EINTR
invalid_argument            	error condition corresponding to POSIX code EINVAL
invalid_seek 	                error condition corresponding to POSIX code ESPIPE
io_error 	                    error condition corresponding to POSIX code EIO
is_a_directory 	                error condition corresponding to POSIX code EISDIR
message_size 	                error condition corresponding to POSIX code EMSGSIZE
network_down 	                error condition corresponding to POSIX code ENETDOWN
network_reset 	                error condition corresponding to POSIX code ENETRESET
network_unreachable 	        error condition corresponding to POSIX code ENETUNREACH
no_buffer_space 	            error condition corresponding to POSIX code ENOBUFS
no_child_process 	            error condition corresponding to POSIX code ECHILD
no_link 	                    error condition corresponding to POSIX code ENOLINK
no_lock_available 	            error condition corresponding to POSIX code ENOLCK
no_message_available 	        error condition corresponding to POSIX code ENODATA
no_message 	                    error condition corresponding to POSIX code ENOMSG
no_protocol_option 	            error condition corresponding to POSIX code ENOPROTOOPT
no_space_on_device 	            error condition corresponding to POSIX code ENOSPC
no_stream_resources 	        error condition corresponding to POSIX code ENOSR
no_such_device_or_address 	    error condition corresponding to POSIX code ENXIO
no_such_device 	                error condition corresponding to POSIX code ENODEV
no_such_file_or_directory 	    error condition corresponding to POSIX code ENOENT
no_such_process 	            error condition corresponding to POSIX code ESRCH
not_a_directory 	            error condition corresponding to POSIX code ENOTDIR
not_a_socket 	                error condition corresponding to POSIX code ENOTSOCK
not_a_stream 	                error condition corresponding to POSIX code ENOSTR
not_connected 	                error condition corresponding to POSIX code ENOTCONN
not_enough_memory 	            error condition corresponding to POSIX code ENOMEM
not_supported 	                error condition corresponding to POSIX code ENOTSUP
operation_canceled 	            error condition corresponding to POSIX code ECANCELED
operation_in_progress 	        error condition corresponding to POSIX code EINPROGRESS
operation_not_permitted         error condition corresponding to POSIX code EPERM
operation_not_supported 	    error condition corresponding to POSIX code EOPNOTSUPP
operation_would_block 	        error condition corresponding to POSIX code EWOULDBLOCK
owner_dead 	                    error condition corresponding to POSIX code EOWNERDEAD
permission_denied 	            error condition corresponding to POSIX code EACCES
protocol_error 	                error condition corresponding to POSIX code EPROTO
protocol_not_supported 	        error condition corresponding to POSIX code EPROTONOSUPPORT
read_only_file_system 	        error condition corresponding to POSIX code EROFS
resource_deadlock_would_occur 	error condition corresponding to POSIX code EDEADLK
resource_unavailable_try_again 	error condition corresponding to POSIX code EAGAIN
result_out_of_range 	        error condition corresponding to POSIX code ERANGE
state_not_recoverable 	        error condition corresponding to POSIX code ENOTRECOVERABLE
stream_timeout 	                error condition corresponding to POSIX code ETIME
text_file_busy 	                error condition corresponding to POSIX code ETXTBSY
timed_out 	                    error condition corresponding to POSIX code ETIMEDOUT
too_many_files_open_in_system 	error condition corresponding to POSIX code ENFILE
too_many_files_open 	        error condition corresponding to POSIX code EMFILE
too_many_links 	                error condition corresponding to POSIX code EMLINK
too_many_symbolic_link_levels 	error condition corresponding to POSIX code ELOOP
value_too_large 	            error condition corresponding to POSIX code EOVERFLOW
wrong_protocol_type 	        error condition corresponding to POSIX code EPROTOTYPE


*/
