// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_from_input_file.c"
}

#include <gtest/gtest.h>

// TODO: Add tests
TEST(InitNonBoolNonStrTest, CharSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    char c;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "charSuccess", "%c", &c));
    EXPECT_EQ(c, 'A');

    fclose(pFile);
}
