#ifndef INIT_TOOLS_H
#define INIT_TOOLS_H

#include <stdbool.h>
#include <stdio.h>

typedef enum FileIoStatus
{
    FILE_IO_STATUS_ALL_GOOD,
    FILE_IO_STATUS_KEY_FOUND,
    FILE_IO_STATUS_VALUE_FOUND,
    FILE_IO_STATUS_KEY_NOT_FOUND,  /* at the start of the line */
    FILE_IO_STATUS_VALUE_NOT_FOUND,  /* after and on the same line as the key */
    FILE_IO_STATUS_FEOF,
    FILE_IO_STATUS_FERROR,
    FILE_IO_STATUS_FTELL_FAIL,
    FILE_IO_STATUS_FSEEK_FAIL
} FileIoStatus;

#ifdef PRINT_ERRORS
/*
BRIEF
printError calls fprintf to print a detailed error message to stderr, in the
following format:

    ERROR: kMsg\n
           Source: kFileMacro | Line: kLineMacro | Input: kFileName | Key: kKeyName\n

PARAMETER(S)
kMsg
    The message to print. Must not include any format specifiers!
kFileMacro
    The name of the source file that called this function, obtained by using
    the __FILE__ macro
kLineMacro
    The line (number) on which this function was called, obtained by using the
    __LINE__ macro
kFileName
    The name of the input text file; maps back to the parameter of
    initFromInputFile, declared in init_from_input_file.h, with the same name
kKeyName
    The name of the (to-be-)searched-for key; maps back to the parameter of
    initFromInputFile, declared in init_from_input_file.h, with the same name

RETURN VALUE
N/A
*/
void printError(const char* kMsg,
                const char* kFileMacro,
                int kLineMacro,
                const char* kFileName,
                const char* kKeyName);
#endif  /* PRINT_ERRORS */

/*
BRIEF
stripAndLower removes the white space from a string and converts it to
lowercase. The original string is not modified. Instead, a second string is
passed by reference and modified.

PARAMETER(S)
kStrIn
    The "input," original string; immutable
strOut
    The "output," stripped-and-lowered string; mutable. Must have space
    allocated for the null terminator!

RETURN VALUE
N/A
 */
void stripAndLower(const char* kStrIn, char* strOut);

/*
BRIEF
findKey searches the file associated with the file pointer for the key and
updates the file position indicator accordingly. If the key was found in the
file, the position indicator "points" to the char immediately after the end of
the key, and true is returned. Otherwise, false is returned.

PARAMETER(S)
pFile
    The file pointer
kKeyName
    The name of the key to search the file for

RETURN VALUE
true if the key was found in the file; false otherwise. That is, a Boolean.
*/
bool findKey(FILE* pFile, const char* kKeyName);

/*
BRIEF
findValue picks up where findKey left off. It searches the remainder of the
line "pointed" to by the file pointer's position indicator for the value
corresponding to the key and updates the position indicator accordingly. If the
corresponding value was found on the line, the position indicator "points" to
the first char of that value, and true is returned. Otherwise, false is
returned.

PARAMETER(S)
pFile
    The file pointer
kKeyName | TODO: Only pass if PRINT_ERRORS
    The name of the key found by findKey; used strictly for error handling

RETURN VALUE
true if the corresponding value was found on the line; false otherwise. That
is, a Boolean.
*/
bool findValue(FILE* pFile, const char* kKeyName);

/*
BRIEF
freadChar calls fread to populate the passed-by-reference char and advance the
file pointer's position indicator. It returns the appropriate FileIoStatus
(e.g., "all good" or "error").

PARAMETER(S)
pFile
    The file pointer
pChar
    The address of the to-be-populated char

RETURN VALUE
A FileIoStatus enumerator representing the file I/O status, used by the calling
function
*/
FileIoStatus freadChar(FILE* pFile, char* pChar);

#endif  /* INIT_TOOLS_H */
