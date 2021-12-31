// Prevent C++ from name-mangling the C code
extern "C" {
#include "../../../src/init_tools.h"
}

#include <gtest/gtest.h>

#include <cstring>

TEST(StripAndLowerTest, NoWhiteSpaceAndCamelCase)
{
    const char* const kStrIn {"NoWhiteSpaceAndCamelCase"};
    char* const strOut {new char[std::strlen(kStrIn) + 1]};  // "+ 1" for '\0'

    stripAndLower(kStrIn, strOut);
    EXPECT_STREQ(strOut, "nowhitespaceandcamelcase");

    delete[] strOut;
}

TEST(StripAndLowerTest, WhiteSpaceAndLowercase)
{
    const char* const kStrIn {"white	space and\nlowercase"};
    char* const strOut {new char[std::strlen(kStrIn) + 1]};  // "+ 1" for '\0'

    stripAndLower(kStrIn, strOut);
    EXPECT_STREQ(strOut, "whitespaceandlowercase");

    delete[] strOut;
}

TEST(StripAndLowerTest, WhiteSpaceAndUppercase)
{
    const char* const kStrIn {"WHITE	SPACE AND\nUPPERCASE"};
    char* const strOut {new char[std::strlen(kStrIn) + 1]};  // "+ 1" for '\0'

    stripAndLower(kStrIn, strOut);
    EXPECT_STREQ(strOut, "whitespaceanduppercase");

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
