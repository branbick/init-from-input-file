// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../../src/init_tools.h"
}

#include <gtest/gtest.h>

#include <cstring>

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

    EXPECT_TRUE(findKey(pFile, "keyAndValueExist"));

    fclose(pFile);
}

TEST(FindKeyTest, KeyDoesNotExist)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(findKey(pFile, "keyDoesNotExist"));

    fclose(pFile);
}

TEST(FindKeyTest, KeyNotLeftAligned)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(findKey(pFile, "keyNotLeftAligned"));

    fclose(pFile);
}

TEST(FindKeyTest, KeyAndValueNotSeparated)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(findKey(pFile, "keyAndValueNotSeparated"));

    fclose(pFile);
}

TEST(FindKeyTest, KeyFollowedByNewline)
{
    const char* const kFileName {"../input/FindKeyTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(findKey(pFile, "keyFollowedByNewline"));

    fclose(pFile);
}

TEST(FindValueTest, KeyAndValueExist)
{
    const char* const kFileName {"../input/FindValueTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_TRUE(findKey(pFile, "keyAndValueExist"));
    EXPECT_TRUE(findValue(pFile));

    fclose(pFile);
}

TEST(FindValueTest, KeyExistsButValueDoesNot)
{
    const char* const kFileName {"../input/FindValueTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_TRUE(findKey(pFile, "keyExistsButValueDoesNot"));
    EXPECT_FALSE(findValue(pFile));

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
