#include "init_from_input_file.h"
#include "init_tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef PRINT_ERRORS
/* Simplify the calls to printError, which is declared in init_tools.h */
#define error(kMsg, kFileName, kKeyName) printError(kMsg, __FILE__, __LINE__, kFileName, kKeyName)
#endif

/*
BRIEF
initNonBoolNonStr calls findKey and findValue (in that order), where both of
those functions are declared in init_tools.h, to properly set the file
pointer's position indicator. It subsequently calls fscanf to populate the non-
bool, non-string, passed-by-reference variable.

PARAMETER(S)
pFile
    The file pointer
kKeyName
    The name of the key to search the file for
kFormatSpec
    The format specifier (passed to fscanf)
pVar
    The address of the non-bool, non-string, to-be-populated variable
#ifdef PRINT_ERRORS
kFileName
    The name of the file "pointed" to by the file pointer
#endif

RETURN VALUE
true if the passed-by-reference variable was populated; false otherwise. That
is, a Boolean.
*/
#ifndef PRINT_ERRORS
static bool initNonBoolNonStr(FILE* pFile,
                              const char* kKeyName,
                              const char* kFormatSpec,
                              void* pVar);
#else
static bool initNonBoolNonStr(FILE* pFile,
                              const char* kKeyName,
                              const char* kFormatSpec,
                              void* pVar,
                              const char* kFileName);
#endif

/*
BRIEF
initBool calls findKey and findValue (in that order), where both of those
functions are declared in init_tools.h, to properly set the file pointer's
position indicator. It subsequently calls fscanf to populate the Boolean,
passed-by-reference variable.

The value corresponding to the key must be either "true" or "false"--without
quotation marks. ("1" and "0" are not supported.)

PARAMETER(S)
pFile
    The file pointer
kKeyName
    The name of the key to search the file for
pVar
    The address of the Boolean, to-be-populated variable
#ifdef PRINT_ERRORS
kFileName
    The name of the file "pointed" to by the file pointer
#endif

RETURN VALUE
true if the passed-by-reference variable was populated; false otherwise. That
is, a Boolean.
*/
#ifndef PRINT_ERRORS
static bool initBool(FILE* pFile, const char* kKeyName, bool* pVar);
#else
static bool initBool(FILE* pFile,
                     const char* kKeyName,
                     bool* pVar,
                     const char* kFileName);
#endif

/*
BRIEF
initString calls findKey and findValue (in that order), where both of those
functions are declared in init_tools.h, to properly set the file pointer's
position indicator. It subsequently repeatedly calls freadChar--which is
declared in init_tools.h--to populate the string, passed-by-reference variable.

The value corresponding to the key must be preceded and followed by a double
quotation mark and cannot contain a double quotation mark. Additionally, the
passed-in string must have space allocated for (at least) the entire value plus
the null terminator. For example, if "Hey, Bob!" is the value, then the length
of the passed-in string must be at least 10 {i.e., it must be defined as either
char[10] or (char*)malloc(10 * sizeof(char))}. If insufficient space is
allocated, 1) the chars of the value will be assigned to successive segments of
memory after the block dedicated to the passed-in string, until the double
quotation mark that follows the value is reached, and 2) the behavior is
undefined.

PARAMETER(S)
pFile
    The file pointer
kKeyName
    The name of the key to search the file for
pVar
    The address of the string, to-be-populated variable
#ifdef PRINT_ERRORS
kFileName
    The name of the file "pointed" to by the file pointer
#endif

RETURN VALUE
true if the passed-by-reference variable was populated; false otherwise. That
is, a Boolean.
*/
#ifndef PRINT_ERRORS
static bool initString(FILE* pFile, const char* kKeyName, char* pVar);
#else
static bool initString(FILE* pFile,
                       const char* kKeyName,
                       char* pVar,
                       const char* kFileName);
#endif

bool initFromInputFile(const char* const kFileName,
                       const char* const kVarType,
                       const char* const kKeyName,
                       void* const pVar)
{
    bool successFlag;
    FILE* pFile;
    char* varType;

    successFlag = true;

    pFile = fopen(kFileName, "r");
    if (pFile == NULL)
    {
#ifdef PRINT_ERRORS
        error("Unable to open the input file.", kFileName, kKeyName);
#endif
        return (successFlag = false);
    }

    /*
    Handle potential typos by removing the white space from kVarType and
    converting it to lowercase
    */
    varType = (char*)malloc((strlen(kVarType) + 1) * sizeof(char));  /* "+ 1" for the null terminator */
    if (varType == NULL)
    {
#ifdef PRINT_ERRORS
        error("Unable to dynamically allocate memory.", kFileName, kKeyName);
#endif
        fclose(pFile);
        return (successFlag = false);
    }
    stripAndLower(kVarType, varType);

    /* Call the appropriate initialization function based on varType */
#ifndef PRINT_ERRORS
    if (strcmp(varType, "char") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%c", pVar);
    else if (strcmp(varType, "schar") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%d", pVar);
    else if (strcmp(varType, "uchar") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%u", pVar);
    else if (strcmp(varType, "short") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%hd", pVar);
    else if (strcmp(varType, "ushort") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%hu", pVar);
    else if (strcmp(varType, "int") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%d", pVar);
    else if (strcmp(varType, "uint") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%u", pVar);
    else if (strcmp(varType, "long") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%ld", pVar);
    else if (strcmp(varType, "ulong") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%lu", pVar);
    else if (strcmp(varType, "float") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%f", pVar);
    else if (strcmp(varType, "double") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%lf", pVar);
    else if (strcmp(varType, "ldouble") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%Lf", pVar);
    else if (strcmp(varType, "bool") == 0)
        successFlag = initBool(pFile, kKeyName, (bool*)pVar);
    else if (strcmp(varType, "string") == 0)
        successFlag = initString(pFile, kKeyName, (char*)pVar);
    else
        successFlag = false;
#else
    if (strcmp(varType, "char") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%c", pVar, kFileName);
    else if (strcmp(varType, "schar") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%d", pVar, kFileName);
    else if (strcmp(varType, "uchar") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%u", pVar, kFileName);
    else if (strcmp(varType, "short") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%hd", pVar, kFileName);
    else if (strcmp(varType, "ushort") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%hu", pVar, kFileName);
    else if (strcmp(varType, "int") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%d", pVar, kFileName);
    else if (strcmp(varType, "uint") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%u", pVar, kFileName);
    else if (strcmp(varType, "long") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%ld", pVar, kFileName);
    else if (strcmp(varType, "ulong") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%lu", pVar, kFileName);
    else if (strcmp(varType, "float") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%f", pVar, kFileName);
    else if (strcmp(varType, "double") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%lf", pVar, kFileName);
    else if (strcmp(varType, "ldouble") == 0)
        successFlag = initNonBoolNonStr(pFile, kKeyName, "%Lf", pVar, kFileName);
    else if (strcmp(varType, "bool") == 0)
        successFlag = initBool(pFile, kKeyName, (bool*)pVar, kFileName);
    else if (strcmp(varType, "string") == 0)
        successFlag = initString(pFile, kKeyName, (char*)pVar, kFileName);
    else
    {
        /*
        Call error with a message that states the specified, unsupported
        variable type. Note that, regarding the argument passed to malloc,
        "- 2" is for the format specifier in kFormatMsg that will be replaced
        with kVarType, and "+ 1" is for the null terminator.
        */
        const char* const kFormatMsg = "\"%s\" is an unsupported variable type.";
        char* const msg = (char*)malloc((strlen(kFormatMsg) - 2 + strlen(kVarType) + 1) * sizeof(char));
        if (msg == NULL)
        {
            error("Unable to dynamically allocate memory.", kFileName, kKeyName);
            free(varType);
            fclose(pFile);
            return (successFlag = false);
        }
        sprintf(msg, kFormatMsg, kVarType);
        error(msg, kFileName, kKeyName);
        free(msg);

        successFlag = false;
    }
#endif

    free(varType);
    fclose(pFile);

    return successFlag;
}

#ifndef PRINT_ERRORS
bool initNonBoolNonStr(FILE* const pFile,
                       const char* const kKeyName,
                       const char* const kFormatSpec,
                       void* const pVar)
#else
bool initNonBoolNonStr(FILE* const pFile,
                       const char* const kKeyName,
                       const char* const kFormatSpec,
                       void* const pVar,
                       const char* const kFileName)
#endif
{
#ifndef PRINT_ERRORS
    if (findKey(pFile, kKeyName) && findValue(pFile))
#else
    if (findKey(pFile, kKeyName, kFileName) && findValue(pFile, kFileName, kKeyName))
#endif
    {
        const int kNumRxArgsAssigned = fscanf(pFile, kFormatSpec, pVar);

        if (kNumRxArgsAssigned == 0)
        {
#ifdef PRINT_ERRORS
            error("Receiving argument was not assigned.", kFileName, kKeyName);
#endif
            return false;
        }

        if (kNumRxArgsAssigned == EOF)
        {
#ifdef PRINT_ERRORS
            error("EOF or an error occurred before the receiving argument was assigned.", kFileName, kKeyName);
#endif
            return false;
        }

        return true;
    }

    return false;
}

#ifndef PRINT_ERRORS
bool initBool(FILE* const pFile, const char* const kKeyName, bool* const pVar)
#else
bool initBool(FILE* const pFile,
              const char* const kKeyName,
              bool* const pVar,
              const char* const kFileName)
#endif
{
/*
Define the length of the temp. A length of seven supports "true\0" (five chars)
and "false\0" (six chars) plus one additional char used to ensure that, e.g.,
"falsely" isn't parsed as "false"--only the whole words "true" and "false" are
accepted. (Refer to the implementation below for further details.)
*/
#define TEMP_LEN 7

#ifndef PRINT_ERRORS
    if (findKey(pFile, kKeyName) && findValue(pFile))
#else
    if (findKey(pFile, kKeyName, kFileName) && findValue(pFile, kFileName, kKeyName))
#endif
    {
        /* Initialize all the elements of temp to the null terminator */
        char temp[TEMP_LEN] = {'\0'};

        /*
        Assign temp. The width is set to TEMP_LEN - 1 == 6 because fscanf null-
        terminates the string. (Yes, the format specifier can be made a
        variable that uses TEMP_LEN for a variable width, but that would
        require dynamic memory, math functions, etc.--overkill.)
        */
        const int kNumRxArgsAssigned = fscanf(pFile, "%6s", temp);

        int i;

        if (kNumRxArgsAssigned == 0)
        {
#ifdef PRINT_ERRORS
            error("Receiving argument was not assigned.", kFileName, kKeyName);
#endif
            return false;
        }

        if (kNumRxArgsAssigned == EOF)
        {
#ifdef PRINT_ERRORS
            error("EOF or an error occurred before the receiving argument was assigned.", kFileName, kKeyName);
#endif
            return false;
        }

        /*
        Don't need "tolower" the last two chars of temp as each of them should
        just be the null terminator. If not, the value is invalid anyway.
        */
        for (i = 0; i < TEMP_LEN - 2; i++)
            temp[i] = tolower(temp[i]);

        if (strcmp(temp, "true") == 0)
            *pVar = true;
        else if (strcmp(temp, "false") == 0)
            *pVar = false;
        else
        {
#ifdef PRINT_ERRORS
            error("Value is invalid. (Only \"true\" and \"false\"--without quotation marks--are supported.)", kFileName, kKeyName);
#endif
            return false;
        }

        return true;
    }

    return false;

#undef TEMP_LEN
}

#ifndef PRINT_ERRORS
bool initString(FILE* const pFile,
                const char* const kKeyName,
                char* const pVar)
#else
bool initString(FILE* const pFile,
                const char* const kKeyName,
                char* const pVar,
                const char* const kFileName)
#endif
{
#ifndef PRINT_ERRORS
    if (findKey(pFile, kKeyName) && findValue(pFile))
#else
    if (findKey(pFile, kKeyName, kFileName) && findValue(pFile, kFileName, kKeyName))
#endif
    {
        FileIoStatus fileIoStatus;
        char temp;
        int i;

        /* Skip the opening double quotation mark */
        if ((fileIoStatus = freadChar(pFile, &temp)) == FILE_IO_STATUS_FERROR)
        {
#ifdef PRINT_ERRORS
            error("Unable to read from the input file.", kFileName, kKeyName);
#endif
            return false;
        }

        /* Read up to the closing double quotation mark */
        i = 0;
        while (true)
        {
            if ((fileIoStatus = freadChar(pFile, &temp)))
            {
                /*
                Entered if fileIoStatus != FILE_IO_STATUS_ALL_GOOD, i.e., if
                freadChar encountered an error
                */

                switch (fileIoStatus)
                {
                    case FILE_IO_STATUS_FEOF:
#ifdef PRINT_ERRORS
                        error("EOF occurred before the receiving argument was completely assigned.", kFileName, kKeyName);
#endif
                        break;
                    case FILE_IO_STATUS_FERROR:
#ifdef PRINT_ERRORS
                        error("Unable to read from the input file.", kFileName, kKeyName);
#endif
                        break;
                    default:
#ifdef PRINT_ERRORS
                        error("Default case was reached.", kFileName, kKeyName);
#endif
                        break;
                }

                return false;
            }

            if (temp == '"')
            {
                /* Null-terminate pVar */
                *(pVar + i) = '\0';
                break;
            }

            /*
            Assign temp to the ith element of pVar and subsequently increment i

            CAUTION: This "assign and increment" step repeats until the closing
            double quotation mark is reached (or freadChar encounters an
            error). So, sufficient space must be allocated for pVar based on
            the length of the corresponding string value. (Refer to the brief
            before the declaration of this function for further explanation.)
            */
            *(pVar + i++) = temp;
        }

        return true;
    }

    return false;
}
