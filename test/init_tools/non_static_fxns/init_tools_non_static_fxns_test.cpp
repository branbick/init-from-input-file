// Prevent C++ from name-mangling the C code
extern "C" {
#include "../../../src/init_tools.h"
}

#include <gtest/gtest.h>

TEST(FreadCharTest, Comprehensive)
{
    const char* const kFileName = "../FreadCharTest_Comprehensive.inp";
    FILE* const pFile = fopen(kFileName, "r");
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;
    
    char c;

    ASSERT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    ASSERT_EQ(c, '!');

    ASSERT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    ASSERT_EQ(c, '9');

    ASSERT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    ASSERT_EQ(c, ' ');

    ASSERT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    ASSERT_EQ(c, 'A');

    ASSERT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    ASSERT_EQ(c, 'z');

    ASSERT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    ASSERT_EQ(c, '\n');

    ASSERT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_FEOF);

    fclose(pFile);
}
