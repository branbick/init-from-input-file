// Prevent C++ from name-mangling the C code
extern "C" {
#include "../../src/init_tools.h"
}

#include <gtest/gtest.h>

TEST(FreadCharTest, FreadCharTestSimple)
{
    const char* const kFileName = "../freadChar_test.inp";
    FILE* const pFile = fopen(kFileName, "r");
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;
    
    char c;

    freadChar(pFile, &c);
    EXPECT_EQ(c, 'a');

    freadChar(pFile, &c);
    EXPECT_EQ(c, '\n');

    EXPECT_EQ(freadChar(pFile, &c), FILE_IO_STATUS_FEOF);

    fclose(pFile);
}
