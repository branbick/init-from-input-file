// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_tools.c"
}

#include <gtest/gtest.h>

// TODO: Add tests
TEST(CheckStartOfLineTest, KeyDoesNotExist)
{
    const char* const kFileName {
        "../input/CheckStartOfLineTest_KeyDoesNotExist.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(checkStartOfLine(pFile, "keyDoesNotExist"),
              FILE_IO_STATUS_KEY_NOT_FOUND);

    fclose(pFile);
}

TEST(CheckStartOfLineTest, KeyFollowedBySpace)
{
    const char* const kFileName {
        "../input/CheckStartOfLineTest_KeyFollowedBySpace.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(checkStartOfLine(pFile, "keyFollowedBySpace"),
              FILE_IO_STATUS_KEY_FOUND);

    fclose(pFile);
}

TEST(CheckStartOfLineTest, KeyFollowedByTab)
{
    const char* const kFileName {
        "../input/CheckStartOfLineTest_KeyFollowedByTab.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(checkStartOfLine(pFile, "keyFollowedByTab"),
              FILE_IO_STATUS_KEY_FOUND);

    fclose(pFile);
}

TEST(CheckStartOfLineTest, KeyFollowedByNewline)
{
    const char* const kFileName {
        "../input/CheckStartOfLineTest_KeyFollowedByNewline.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(checkStartOfLine(pFile, "keyFollowedByNewline"),
              FILE_IO_STATUS_VALUE_NOT_FOUND);

    fclose(pFile);
}
