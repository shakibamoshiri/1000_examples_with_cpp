#include <windows.h>

#include <stdio.h>

#include <wininet.h>

#define FILE_BUFFER_SIZE 4096

#define RETRY_READ         10

char   sInputUrl [INTERNET_MAX_URL_LENGTH] = “”;

char   sOutputPath [MAX_PATH] = “”;

HANDLE hStdOut;

DWORD  dReadFileCount, dWriteFileCount, dWriteFileTotal;

VOID Banner ()

    {

    printf (“\nWDJ EasyDL V1.00 / 07-21-96 Sven B. Schreiber\n\n”);

    }

VOID Usage ()

    {

    printf (“Usage: EasyDL <Source URL> [<Destination>]\n”);

    printf (“\n”);

    printf (“Valid URL schemes are ftp, http, and gopher.\n”);

    printf (“If no destination is specified, STDOUT is assumed.\n”);

    }

DWORD BytesPerSecond (SYSTEMTIME *pStartTime,

                      DWORD      dBytes)

    {

    SYSTEMTIME CurrentTime;

    DWORD      dStartSecond, dSeconds;


    dStartSecond = (((DWORD) pStartTime->wSecond)          ) +

                   (((DWORD) pStartTime->wMinute) * 60     ) +

                   (((DWORD) pStartTime->wHour  ) * 60 * 60);

    GetSystemTime (&CurrentTime);

    dSeconds = (((DWORD) CurrentTime.wSecond)          ) +

               (((DWORD) CurrentTime.wMinute) * 60     ) +

               (((DWORD) CurrentTime.wHour  ) * 60 * 60) –

               dStartSecond;


    if (dSeconds & 0x80000000) {dSeconds += 24 * 60 * 60;}


    return (dSeconds ? (dBytes / dSeconds) : 0);

    }


// =================================================================

// INTERNET INTERFACE

// =================================================================


VOID DownloadFile (HINTERNET hSource,

                   HANDLE    hDestination)

    {

    UINT       uRetry;

    BOOL       fOk;

    BYTE       bFileBuffer [FILE_BUFFER_SIZE];

    SYSTEMTIME StartTime;


    if (hDestination == hStdOut)

        printf (“\n————— [ BEGIN ] —————\n”);


    dWriteFileTotal = 0;

    GetSystemTime (&StartTime);


    do

        {

        if (hDestination != hStdOut)

            {

            printf (“\r%lu bytes transferred … “,

                    dWriteFileTotal);

            printf (“(%lu bytes/sec)         “,

                    BytesPerSecond (&StartTime, dWriteFileTotal));

            }


        uRetry = 0;

        do

            {

            dReadFileCount = 0;

            fOk = InternetReadFile (hSource,

                                    bFileBuffer,

                                    FILE_BUFFER_SIZE,

                                    &dReadFileCount);

            }

        while (!(dReadFileCount || fOk || uRetry++ == RETRY_READ));


        if (dReadFileCount)

            {

            dWriteFileCount = 0;

            fOk = WriteFile (hDestination,

                             bFileBuffer,

                             dReadFileCount,

                             &dWriteFileCount,

                             NULL);

            if (fOk = fOk && (dReadFileCount == dWriteFileCount))

                dWriteFileTotal += dWriteFileCount;

            else

                {

                dReadFileCount = 0;

                printf (“\n!!! Error writing data !!!”);

                }

            }

        else

            {

            if (!fOk)

                printf (“\n!!! Error reading data !!!”);

            }

        }

    while (dReadFileCount);


    if (hDestination == hStdOut)

        printf (“\n—————- [ END ] —————-“);


    printf (“\n\n”);

    }

// —————————————————————–


VOID GetInternetFile (HINTERNET hSession,

                      char sSource [],

                      char sDestination [])

    {

    HINTERNET hSource;

    HANDLE    hDestination;


    printf (“Opening \”%s\”\n”, sSource);

    hSource = InternetOpenUrl (hSession,

                               sSource,

                               NULL,

                               0xFFFFFFFF,

                               INTERNET_FLAG_DONT_CACHE |

                               INTERNET_FLAG_RAW_DATA,

                               0);

    if (hSource != NULL)

        {

        if (!sOutputPath [0])

            {

            printf (“Output directed to STDOUT\n”);

            hDestination = hStdOut;

            }

        else

            {

            printf (“Creating \”%s\”\n”, sDestination);

            hDestination = CreateFile (sDestination,

                                       GENERIC_WRITE,

                                       FILE_SHARE_READ,

                                       NULL,

                                       CREATE_NEW,

                                       FILE_FLAG_WRITE_THROUGH |

                                       FILE_FLAG_SEQUENTIAL_SCAN,

                                       NULL);

            }

        if (hDestination != INVALID_HANDLE_VALUE)

            {

            printf (“\nStarting Download\n”);

            DownloadFile (hSource, hDestination);


            if (hDestination != hStdOut)

                {

                printf (“Closing \”%s\”\n”, sDestination);

                CloseHandle (hDestination);

                }

            }

        else

            printf (“\n!!! Output file not created !!!\n\n”);

        printf (“Closing \”%s\”\n”, sSource);

        InternetCloseHandle (hSource);

        }

    else

        printf (“\n!!! Internet URL not opened !!!\n\n”);

    }

// —————————————————————–


VOID InternetSession (char sCaller [])

    {

    HINTERNET hSession;


    printf (“Opening Internet Session \”%s\”\n”, sCaller);

    hSession = InternetOpen (sCaller,

                             LOCAL_INTERNET_ACCESS,

                             NULL,

                             INTERNET_INVALID_PORT_NUMBER,

                             INTERNET_FLAG_DONT_CACHE);

    if (hSession != NULL)

        {

        GetInternetFile (hSession, sInputUrl, sOutputPath);


        printf (“Closing Internet Session \”%s\”\n”, sCaller);

        InternetCloseHandle (hSession);

        }

    else

        printf (“\n!!! Internet session not opened !!!\n”);

    }

// =================================================================

// MAIN PROGRAM

// =================================================================

void main (int argc, char *argv [], char *envp [])

    {

    hStdOut = GetStdHandle (STD_OUTPUT_HANDLE);

    Banner ();


    if (argc > 1)

        {lstrcpyn (sInputUrl,   argv [1], INTERNET_MAX_URL_LENGTH);}

    if (argc > 2)

        {lstrcpyn (sOutputPath, argv [2], MAX_PATH);}


    if (sInputUrl [0])

        InternetSession (“EasyDL/1.00”);

    else

        Usage ();

    }
