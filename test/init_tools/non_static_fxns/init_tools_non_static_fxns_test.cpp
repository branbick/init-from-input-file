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

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    EXPECT_EQ(c, 'a');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_ALL_GOOD);
    EXPECT_EQ(c, '\n');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_FEOF);

    fclose(pFile);
}
