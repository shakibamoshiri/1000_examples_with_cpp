/// Null-terminate string

/// 41_std::strerror
/// definition in header < cstring >
/// character array manipulation
/**

char* strerror ( int errnum );

Returns a pointer to the  textual description of the system error
code errnum, identical to the description that would be pointed by
perror(). Errnum is usually acquired from the errno variable, however
the function accepts any value of type int. The contents of the string
are locale-specific. The returned string must not be modified by the
program, but may be overwritten by subsequence call to the strerror
function. strerror is not required to be tread-safe. Implementation
may be returning different pointer to static read-only string literals
of may be returning the same pointer over and over.

Return Value:

**/

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <clocale>

#include <unistd.h>

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        double not_a_number = std::log(-1.0);
        if ( errno == EDOM ){
            std::cout<<"log(-1) failed: "<<std::strerror(errno)<<std::endl;
            std::setlocale(LC_MESSAGES, "de_DE.utf8");
            std::cout<<"Or, in German, "<<std::strerror(errno)<<std::endl;
        }
    }

}
/*
#ifndef _ASM_GENERIC_ERRNO_BASE_H
#define _ASM_GENERIC_ERRNO_BASE_H

#define	EPERM		 1	 Operation not permitted
#define	ENOENT		 2	/No such file or directory
#define	ESRCH		 3	/* No such process
#define	EINTR		 4	/* Interrupted system call
#define	EIO		 5	/* I/O error
#define	ENXIO		 6	/* No such device or address
#define	E2BIG		 7	/* Argument list too long
#define	ENOEXEC		 8	/* Exec format error
#define	EBADF		 9	/* Bad file number
#define	ECHILD		10	/* No child processes
#define	EAGAIN		11	/* Try again
#define	ENOMEM		12	/* Out of memory
#define	EACCES		13	/* Permission denied
#define	EFAULT		14	/* Bad address
#define	ENOTBLK		15	/* Block device required
#define	EBUSY		16	/* Device or resource busy
#define	EEXIST		17	/* File exists
#define	EXDEV		18	/* Cross-device link
#define	ENODEV		19	/* No such device
#define	ENOTDIR		20	/* Not a directory
#define	EISDIR		21	/* Is a directory
#define	EINVAL		22	/* Invalid argument
#define	ENFILE		23	/* File table overflow
#define	EMFILE		24	/* Too many open files
#define	ENOTTY		25	/* Not a typewriter
#define	ETXTBSY		26	/* Text file busy
#define	EFBIG		27	/* File too large
#define	ENOSPC		28	/* No space left on device
#define	ESPIPE		29	/* Illegal seek
#define	EROFS		30	/* Read-only file system
#define	EMLINK		31	/* Too many links
#define	EPIPE		32	/* Broken pipe
#define	EDOM		33	/* Math argument out of domain of func
#define	ERANGE		34	/* Math result not representable
#endif

**/















