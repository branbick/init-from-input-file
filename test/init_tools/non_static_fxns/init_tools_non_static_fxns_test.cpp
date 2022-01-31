// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_tools.h"
}

#include <gtest/gtest.h>

#include <cstring>

TEST(PrintErrorTest, CaptureStderr)
{
    // TODO: Clean up (e.g., add comments and use non-literal for errMsg len)
    // Resources:
    // - https://github.com/google/googletest/search?q=capturestderr
    // - https://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
    const char* const kMsg {"Dummy message"};
    const char* const kFileMacro {__FILE__};
    const int kLineMacro {__LINE__};
    const char* const kFileName {"Dummy file name"};
    const char* const kKeyName {"Dummy key name"};

    // TODO: May not be wise bc capturing stderr is part of the private API
    testing::internal::CaptureStderr();

    printError(kMsg, kFileMacro, kLineMacro, kFileName, kKeyName);

    char* const errMsg {new char[255]};

    sprintf(errMsg,
            "ERROR: %s\n       Source: %s | Line: %d | Input: %s | Key: %s\n",
            kMsg, kFileMacro, kLineMacro, kFileName, kKeyName);

    EXPECT_STREQ(errMsg, testing::internal::GetCapturedStderr().c_str());

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

TEST(FreadCharTest, Comprehensive)
{
    const char* const kFileName {"../FreadCharTest_Comprehensive.inp"};
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
