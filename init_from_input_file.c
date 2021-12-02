#include "init_from_input_file.h"
#include "init_tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INIT_BOOL_TEMP_LEN 6  /* Supports "true\0" (5 chars) and "false\0" (6 chars) */

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

RETURN VALUE
true if the passed-by-reference variable was populated; false otherwise. That
is, a Boolean.
*/
static bool initNonBoolNonStr(FILE* pFile,
                              const char* kKeyName,
                              const char* kFormatSpec,
                              void* pVar);

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

RETURN VALUE
true if the passed-by-reference variable was populated; false otherwise. That
is, a Boolean.
*/
static bool initBool(FILE* pFile, const char* kKeyName, bool* pVar);

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

RETURN VALUE
true if the passed-by-reference variable was populated; false otherwise. That
is, a Boolean.
*/
static bool initString(FILE* pFile, const char* kKeyName, char* pVar);

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
        fprintf(stderr, "ERROR (%s, line %d): Unable to open %s.\n", __FILE__, __LINE__, kFileName);
        return (successFlag = false);
    }

    /*
    Handle potential typos by removing the white space from kVarType and
    converting it to lowercase
    */
    varType = (char*)malloc(strlen(kVarType) + 1);  /* "+ 1" for the null terminator */
    if (varType == NULL)
    {
        fprintf(stderr, "ERROR (%s, line %d): Unable to dynamically allocate memory.\n", __FILE__, __LINE__);
        fclose(pFile);
        return (successFlag = false);
    }
    stripAndLower(kVarType, varType);

    /* Call the appropriate initialization function based on varType */
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
    {
        fprintf(stderr, "ERROR (%s, line %d): \"%s\" is an unsupported variable type.\n", __FILE__, __LINE__, kVarType);
        successFlag = false;
    }

    free(varType);
    fclose(pFile);

    return successFlag;
}

bool initNonBoolNonStr(FILE* const pFile,
                       const char* const kKeyName,
                       const char* const kFormatSpec,
                       void* const pVar)
{
    if (findKey(pFile, kKeyName) && findValue(pFile))
    {
        const int kNumRxArgsAssigned = fscanf(pFile, kFormatSpec, pVar);

        if (kNumRxArgsAssigned == 0)
        {
            fprintf(stderr, "ERROR (%s, line %d): Receiving argument was not assigned.\n", __FILE__, __LINE__);
            return false;
        }

        if (kNumRxArgsAssigned == EOF)
        {
            fprintf(stderr, "ERROR (%s, line %d): EOF or an error occured before the receiving argument was assigned.\n", __FILE__, __LINE__);
            return false;
        }

        return true;
    }

    return false;
}

bool initBool(FILE* const pFile, const char* const kKeyName, bool* const pVar)
{
    if (findKey(pFile, kKeyName) && findValue(pFile))
    {
        char temp[INIT_BOOL_TEMP_LEN];
        const int kNumRxArgsAssigned = fscanf(pFile, "%s", temp);
        int i;

        if (kNumRxArgsAssigned == 0)
        {
            fprintf(stderr, "ERROR (%s, line %d): Receiving argument was not assigned.\n", __FILE__, __LINE__);
            return false;
        }

        if (kNumRxArgsAssigned == EOF)
        {
            fprintf(stderr, "ERROR (%s, line %d): EOF or an error occured before the receiving argument was assigned.\n", __FILE__, __LINE__);
            return false;
        }

        for (i = 0; i < INIT_BOOL_TEMP_LEN; i++)
            temp[i] = tolower(temp[i]);

        if (strcmp(temp, "true") == 0)
            *pVar = true;
        else if (strcmp(temp, "false") == 0)
            *pVar = false;
        else
        {
            fprintf(stderr, "ERROR (%s, line %d): \"%s\" is an invalid Boolean value. (Only \"true\" and \"false\"--without quotation marks--are supported.)\n", __FILE__, __LINE__, temp);
            return false;
        }

        return true;
    }

    return false;
}

bool initString(FILE* const pFile,
                const char* const kKeyName,
                char* const pVar)
{
    if (findKey(pFile, kKeyName) && findValue(pFile))
    {
        FileIoStatus fileIoStatus;
        char temp;
        int i;

        /* Skip the opening double quotation mark */
        if ((fileIoStatus = freadChar(pFile, &temp)) == FILE_IO_STATUS_FERROR)
        {
            fprintf(stderr, "ERROR (%s, line %d): Unable to read from the input file.\n", __FILE__, __LINE__);
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
                        fprintf(stderr, "ERROR (%s, line %d): EOF occured before the receiving argument was completely assigned.\n", __FILE__, __LINE__);
                        break;
                    case FILE_IO_STATUS_FERROR:
                        fprintf(stderr, "ERROR (%s, line %d): Unable to read from the input file.\n", __FILE__, __LINE__);
                        break;
                    default:
                        fprintf(stderr, "ERROR (%s, line %d): Default case reached.\n", __FILE__, __LINE__);
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
