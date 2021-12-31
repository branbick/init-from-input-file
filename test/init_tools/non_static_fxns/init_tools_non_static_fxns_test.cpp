// Prevent C++ from name-mangling the C code
extern "C" {
#include "../../../src/init_tools.h"
}

#include <gtest/gtest.h>

#include <cstring>

TEST(StripAndLowerTest, SpacesAndLowercase)
{
    const char* const kStrIn {"spaces and lowercase"};
    char* const strOut {new char[std::strlen(kStrIn) + 1]};  // "+ 1" for the null terminator

    stripAndLower(kStrIn, strOut);
    EXPECT_STREQ(strOut, "spacesandlowercase");

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
