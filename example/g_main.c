#include "bg_lib.h"

void printf(const char *fmt, ...);


/** @brief Simple function to sum up character values.
  This is used for a test in the makefile.
  @param[in] f pointer to string.
  @return test number. */
int testCase(const char* f);

/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .qvm file
================
*/
int vmMain(int command,
           int arg0, int arg1, int arg2,  int arg3,
           int arg4, int arg5, int arg6,  int arg7,
           int arg8, int arg9, int arg10, int arg11)
{
    int i;
    char str[] = "Hello %s\n";
    volatile float f = 0.0f;
    volatile float df = 0.0001f;

    printf(str, "World");

    for (i=0;i<20000000;i++)
    {
        f += df;
    }

    return testCase(str) - 694;
}

void printf(const char *fmt, ...)
{
    va_list     argptr;
    char        text[1024];

    va_start (argptr, fmt);
    vsprintf (text, fmt, argptr);
    va_end (argptr);

    trap_Printf( text );
}

int testCase(const char* f)
{
    int sum=0;
    while(*f)
    {
        sum += *f;
        f++;
    }
    return sum;
}
