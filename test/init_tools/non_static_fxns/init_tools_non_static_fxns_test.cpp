// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_tools.h"
}

#include <gtest/gtest.h>

#include <cstring>
#include <cmath>

TEST(PrintErrorTest, StderrBuffer)
{
    const char* const kMsg {"Dummy message (ignore me)"};
    const char* const kFileMacro {__FILE__};
    const int kLineMacro {__LINE__};
    const char* const kFileName {"dummy_file_name"};
    const char* const kKeyName {"dummyKeyName"};

    char buf[BUFSIZ];
    setbuf(stderr, buf);
    printError(kMsg, kFileMacro, kLineMacro, kFileName, kKeyName);

    const char* const kFormatErrMsg {
        "ERROR: %s\n       Source: %s | Line: %d | Input: %s | Key: %s\n"};
    char* const errMsg {new char[
        std::strlen(kFormatErrMsg) - 10  // "- 10" for the format specifiers
        + std::strlen(kMsg)
        + std::strlen(kFileMacro)
        // The below is the number of digits in kLineMacro
        + static_cast<int>(std::floor(std::log10(kLineMacro))) + 1
        + std::strlen(kFileName)
        + std::strlen(kKeyName)
        + 1]};  // For the null terminator
    sprintf(errMsg,
            kFormatErrMsg,
            kMsg, kFileMacro, kLineMacro, kFileName, kKeyName);

    EXPECT_STREQ(buf, errMsg);

    delete[] errMsg;
}

TEST(StripAndLowerTest, NoWhiteSpaceAndLowercase)
{
    const char* const kStrIn {"nowhitespaceandlowercase"};
    char* const strOut {new char[std::strlen(kStrIn) + 1]};  // "+ 1" for '\0'

    stripAndLower(kStrIn, strOut);
    EXPECT_STREQ(strOut, "nowhitespaceandlowercase");

    delete[] strOut;
}

TEST(StripAndLowerTest, WhiteSpaceAndMixedCase)
{
    const char* const kStrIn {"whITe	SpacE anD\nMiXedCASe"};
    char* const strOut {new char[std::strlen(kStrIn) + 1]};  // "+ 1" for '\0'

    stripAndLower(kStrIn, strOut);
    EXPECT_STREQ(strOut, "whitespaceandmixedcase");

    delete[] strOut;
}

TEST(StripAndLowerTest, WhiteSpaceAndMixedCaseAndMore)
{
    const char* const kStrIn {"whITe	SpacE anD\nMiXedCASe+9  &.\n 26"};
    char* const strOut {new char[std::strlen(kStrIn) + 1]};  // "+ 1" for '\0'

    stripAndLower(kStrIn, strOut);
    EXPECT_STREQ(strOut, "whitespaceandmixedcase+9&.26");

    delete[] strOut;
}

TEST(FindKeyTest, KeyAndValueExist)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_TRUE(findKey(pFile, "keyAndValueExist", kFileName));

    fclose(pFile);
}

TEST(FindKeyTest, KeyDoesNotExist)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(findKey(pFile, "keyDoesNotExist", kFileName));

    fclose(pFile);
}

TEST(FindKeyTest, KeyNotLeftAligned)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(findKey(pFile, "keyNotLeftAligned", kFileName));

    fclose(pFile);
}

TEST(FindKeyTest, KeyAndValueNotSeparated)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(findKey(pFile, "keyAndValueNotSeparated", kFileName));

    fclose(pFile);
}

TEST(FindKeyTest, KeyFollowedByNewline)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(findKey(pFile, "keyFollowedByNewline", kFileName));

    fclose(pFile);
}

// TODO: Create tests for findValue(). Base them on the following:
// https://github.com/branbick/init-from-input-file/tree/unit-testing#rules-for-the-input-text-file.

TEST(FindValueTest, KeyAndValueExist)
{
    const char* const kFileName {"../input/FindValueTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;
    const char* const kKeyName {"keyAndValueExist"};

    EXPECT_TRUE(findKey(pFile, kKeyName, kFileName));
    EXPECT_TRUE(findValue(pFile, kFileName, kKeyName));

    fclose(pFile);
}

TEST(FindValueTest, KeyExistsButValueDoesNot)
{
    const char* const kFileName {"../input/FindValueTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;
    const char* const kKeyName {"keyExistsButValueDoesNot"};

    EXPECT_TRUE(findKey(pFile, kKeyName, kFileName));
    EXPECT_FALSE(findValue(pFile, kFileName, kKeyName));

    fclose(pFile);
}

TEST(FreadCharTest, Comprehensive)
{
    const char* const kFileName {"../input/FreadCharTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;
    
    char c;

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    EXPECT_EQ(c, '!');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    EXPECT_EQ(c, '9');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    EXPECT_EQ(c, ' ');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    EXPECT_EQ(c, 'A');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    EXPECT_EQ(c, 'z');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    EXPECT_EQ(c, '\n');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_FEOF);

    fclose(pFile);
}
