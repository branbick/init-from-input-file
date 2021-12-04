#include "init_tools.h"

#include <string.h>
#include <ctype.h>

/*
BRIEF
checkStartOfLine is a recursive function called by findKey that 1) checks the
start of the line "pointed" to by the file pointer's position indicator for the
key and 2) returns the appropriate FileIoStatus (e.g., "key found," "key not
found," or "error").

PARAMETER(S)
pFile
    The file pointer
keyName
    The name of the key to check the start of the line for

RETURN VALUE
A FileIoStatus enumerator representing the file I/O status, used by findKey
*/
static FileIoStatus checkStartOfLine(FILE* pFile, const char* keyName);

/*
BRIEF
proceedToNextLine is called by findKey to advance the file pointer's position
indicator to the start of the next line. It returns the appropriate
FileIoStatus (e.g., "all good" or "error").

PARAMETER(S)
pFile
    The file pointer

RETURN VALUE
A FileIoStatus enumerator representing the file I/O status, used by findKey
*/
static FileIoStatus proceedToNextLine(FILE* pFile);

/*
BRIEF
skipSpacesAndTabs is called by findValue to advance the file pointer's position
indicator to the start of the value. It returns the appropriate FileIoStatus
(e.g., "value found," "value not found," or "error").

PARAMETER(S)
pFile
    The file pointer

RETURN VALUE
A FileIoStatus enumerator representing the file I/O status, used by findValue
*/
static FileIoStatus skipSpacesAndTabs(FILE* pFile);

#ifdef PRINT_ERRORS
void printError(const char* const kMsg,
                const char* const kFileMacro,
                const int kLineMacro,
                const char* const kFileName,
                const char* const kKeyName)
{
    fprintf(stderr,
        "ERROR: %s\n       Source: %s | Line: %d | Input: %s | Key: %s\n",
        kMsg, kFileMacro, kLineMacro, kFileName, kKeyName);
}
#endif

void stripAndLower(const char* const kStrIn, char* const strOut)
{
    size_t whiteSpaceOffset;
    size_t i;
    const size_t kStrLen = strlen(kStrIn);

    whiteSpaceOffset = 0;

    for (i = 0; i < kStrLen; i++)
    {
        /* Don't add white space to strOut */
        if (isspace(*(kStrIn + i)))
            whiteSpaceOffset++;
        else
            *(strOut + i - whiteSpaceOffset) = tolower(*(kStrIn + i));
    }

    /* Null-terminate strOut */
    *(strOut + kStrLen - whiteSpaceOffset) = '\0';
}

bool findKey(FILE* const pFile, const char* const kKeyName)
{
    while (true)
    {
        FileIoStatus fileIoStatus;

        /* Check the first strlen(kKeyName) chars of the line */
        if ((fileIoStatus = checkStartOfLine(pFile, kKeyName)))
        {
            /* Entered if fileIoStatus != FILE_IO_STATUS_ALL_GOOD */
            switch (fileIoStatus)
            {
                case FILE_IO_STATUS_KEY_FOUND:
                    return true;
                case FILE_IO_STATUS_KEY_NOT_FOUND:
                    break;
                case FILE_IO_STATUS_VALUE_NOT_FOUND:
                    fprintf(stderr, "ERROR (%s, line %d): Did not find a value after \"%s\" (on the same line).\n", __FILE__, __LINE__, kKeyName);
                    return false;
                case FILE_IO_STATUS_FEOF:
                    fprintf(stderr, "ERROR (%s, line %d): \"%s\" was not found in the input file.\n", __FILE__, __LINE__, kKeyName);
                    return false;
                case FILE_IO_STATUS_FERROR:
                    fprintf(stderr, "ERROR (%s, line %d): Unable to read from the input file.\n", __FILE__, __LINE__);
                    return false;
                default:
                    fprintf(stderr, "ERROR (%s, line %d): Default case reached.\n", __FILE__, __LINE__);
                    return false;
            }
        }

        /*
        If the key wasn't found at the start of the line (and there wasn't an
        error), "fast-forward" to the start of the next line
        */
        if ((fileIoStatus = proceedToNextLine(pFile)))
        {
            /* Entered if fileIoStatus != FILE_IO_STATUS_ALL_GOOD */

            switch (fileIoStatus)
            {
                case FILE_IO_STATUS_FEOF:
                    fprintf(stderr, "ERROR (%s, line %d): \"%s\" was not found in the input file.\n", __FILE__, __LINE__, kKeyName);
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
    }
}

FileIoStatus checkStartOfLine(FILE* const pFile, const char* keyName)
{
    static bool atStartOfLine = true;

    /* Populate temp and advance the file position indicator */
    char temp;
    const FileIoStatus kFileIoStatus = freadChar(pFile, &temp);

    if (kFileIoStatus)
    {
        /*
        Entered if kFileIoStatus != FILE_IO_STATUS_ALL_GOOD, i.e., if freadChar
        encountered an error
        */
        atStartOfLine = true;  /* Reset */
        return kFileIoStatus;
    }

    if (*keyName == '\0')
    {
        if (temp == ' ' || temp == '\t')
        {
            atStartOfLine = true;  /* Reset */
            return FILE_IO_STATUS_KEY_FOUND;
        }

        if (temp == '\n')
        {
            atStartOfLine = true;  /* Reset */
            return FILE_IO_STATUS_VALUE_NOT_FOUND;
        }
    }

    /* Skip blank lines */
    if (atStartOfLine && temp == '\n')
        return checkStartOfLine(pFile, keyName);

    if (temp == *keyName)
    {
        keyName++;
        atStartOfLine = false;  /* Line is not blank */
        return checkStartOfLine(pFile, keyName);
    }

    atStartOfLine = true;  /* Reset */
    return FILE_IO_STATUS_KEY_NOT_FOUND;
}

FileIoStatus proceedToNextLine(FILE* const pFile)
{
    while (true)
    {
        /* Populate temp and advance the file position indicator */
        char temp;
        const FileIoStatus kFileIoStatus = freadChar(pFile, &temp);

        if (kFileIoStatus)
            /*
            Entered if kFileIoStatus != FILE_IO_STATUS_ALL_GOOD, i.e., if
            freadChar encountered an error
            */
            return kFileIoStatus;

        if (temp == '\n')
            return FILE_IO_STATUS_ALL_GOOD;
    }
}

bool findValue(FILE* const pFile, const char* const kKeyName)
{
    switch (skipSpacesAndTabs(pFile))
    {
        case FILE_IO_STATUS_VALUE_FOUND:
            return true;
        case FILE_IO_STATUS_VALUE_NOT_FOUND:
            /* Intentional fallthrough */
        case FILE_IO_STATUS_FEOF:
            fprintf(stderr, "ERROR (%s, line %d): Did not find a value after \"%s\" (on the same line).\n", __FILE__, __LINE__, kKeyName);
            break;
        case FILE_IO_STATUS_FERROR:
            fprintf(stderr, "ERROR (%s, line %d): Unable to read from the input file.\n", __FILE__, __LINE__);
            break;
        case FILE_IO_STATUS_FTELL_FAIL:
            fprintf(stderr, "ERROR (%s, line %d): Failed upon a call to ftell.\n", __FILE__, __LINE__);
            break;
        case FILE_IO_STATUS_FSEEK_FAIL:
            fprintf(stderr, "ERROR (%s, line %d): Failed upon a call to fseek.\n", __FILE__, __LINE__);
            break;
        default:
            fprintf(stderr, "ERROR (%s, line %d): Default case reached.\n", __FILE__, __LINE__);
            break;
    }

    return false;
}

FileIoStatus skipSpacesAndTabs(FILE* const pFile)
{
    while (true)
    {
        /* Save the file position indicator */
        const long kFilePtrPos = ftell(pFile);

        /* Populate temp and advance the file position indicator */
        char temp;
        const FileIoStatus kFileIoStatus = freadChar(pFile, &temp);

        if (kFilePtrPos == -1L)
            return FILE_IO_STATUS_FTELL_FAIL;

        if (kFileIoStatus)
            /*
            Entered if kFileIoStatus != FILE_IO_STATUS_ALL_GOOD, i.e., if
            freadChar encountered an error
            */
            return kFileIoStatus;

        if (temp == '\n')
            return FILE_IO_STATUS_VALUE_NOT_FOUND;

        if (temp != ' ' && temp != '\t')
        {
            /*
            Found the value! Use the saved file position indicator to take one
            step back so the next char read is the first char of the value.
            */
            if (fseek(pFile, kFilePtrPos, SEEK_SET))
                return FILE_IO_STATUS_FSEEK_FAIL;

            return FILE_IO_STATUS_VALUE_FOUND;
        }
    }
}

FileIoStatus freadChar(FILE* const pFile, char* const pChar)
{
    FileIoStatus fileIoStatus;

    fileIoStatus = FILE_IO_STATUS_ALL_GOOD;

    if (fread(pChar, sizeof(char), 1, pFile) != 1)
    {
        if (feof(pFile))
            fileIoStatus = FILE_IO_STATUS_FEOF;
        else if (ferror(pFile))
            fileIoStatus = FILE_IO_STATUS_FERROR;
    }

    return fileIoStatus;
}
