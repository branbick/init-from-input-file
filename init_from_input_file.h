/*
Allow this header file to be easily #included in both C and C++ programs.
References:
- https://isocpp.org/wiki/faq/mixing-c-and-cpp#include-c-hdrs-personal
- https://en.cppreference.com/w/cpp/language/language_linkage
*/
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef INIT_FROM_INPUT_FILE_H
#define INIT_FROM_INPUT_FILE_H

#include <stdbool.h>

/*
BRIEF
initFromInputFile parses the specified input text file, which must contain key-
value pairs, and populates the passed-by-reference variable with the value that
matches the specified key. It does that by calling either initNonBoolNonStr,
initBool, or initString--all of which are declared in init_from_input_file.c--
based on the specified variable type.

PARAMETER(S)
kFileName
    The relative or absolute path of the input text file
kVarType
    The variable type:
    - "char" for char
    - "schar" for signed char
    - "uchar" for unsigned char
    - "short" for (signed) short (int)
    - "ushort" for unsigned short (int)
    - "int" for (signed) int
    - "uint" for unsigned int
    - "long" for (signed) long (int)
    - "ulong" for unsigned long (int)
    - "float" for float
    - "double" for double
    - "ldouble" for long double
    - "bool" for bool
    - "string" for char*
    All C90 data types are supported.
kKeyName
    The name of the key to search the file for
pVar
    The address of the to-be-populated variable

RETURN VALUE
true if the passed-by-reference variable was populated; false otherwise. That
is, a Boolean.
*/
bool initFromInputFile(const char* kFileName,
                       const char* kVarType,
                       const char* kKeyName,
                       void* pVar);

#endif  /* INIT_FROM_INPUT_FILE_H */

#ifdef __cplusplus
}
#endif
