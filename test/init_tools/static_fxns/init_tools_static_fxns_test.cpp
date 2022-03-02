// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_tools.c"
}

#include <gtest/gtest.h>

TEST(CheckStartOfLineTest, FreadCharEof)
{
    const char* const kFileName {
        "../input/CheckStartOfLineTest_FreadCharEof.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(checkStartOfLine(pFile, "freadCharEof"), FILE_IO_STATUS_FEOF);

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

TEST(ProceedToNextLineTest, FreadCharEofEmptyFile)
{
    const char* const kFileName {
        "../input/ProceedToNextLineTest_FreadCharEofEmptyFile.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(proceedToNextLine(pFile), FILE_IO_STATUS_FEOF);

    fclose(pFile);
}

TEST(ProceedToNextLineTest, FreadCharEofOnlyOneLine)
{
    const char* const kFileName {
        "../input/ProceedToNextLineTest_FreadCharEofOnlyOneLine.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(proceedToNextLine(pFile), FILE_IO_STATUS_FEOF);

    fclose(pFile);
}

TEST(ProceedToNextLineTest, MultipleLines)
{
    const char* const kFileName {
        "../input/ProceedToNextLineTest_MultipleLines.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(proceedToNextLine(pFile), FILE_IO_STATUS_ALL_GOOD);

    fclose(pFile);
}

TEST(SkipSpacesAndTabsTest, FreadCharEofEmptyFile)
{
    const char* const kFileName {
        "../input/SkipSpacesAndTabsTest_FreadCharEofEmptyFile.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(skipSpacesAndTabs(pFile), FILE_IO_STATUS_FEOF);

    fclose(pFile);
}

TEST(SkipSpacesAndTabsTest, FreadCharEofOnlyOneLineOfSpacesAndTabs)
{
    const char* const kFileName {
        "../input/"
        "SkipSpacesAndTabsTest_FreadCharEofOnlyOneLineOfSpacesAndTabs.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(skipSpacesAndTabs(pFile), FILE_IO_STATUS_FEOF);

    fclose(pFile);
}

TEST(SkipSpacesAndTabsTest, NewLineBeforeNonSpaceNonTab)
{
    const char* const kFileName {
        "../input/SkipSpacesAndTabsTest_NewLineBeforeNonSpaceNonTab.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(skipSpacesAndTabs(pFile), FILE_IO_STATUS_VALUE_NOT_FOUND);

    fclose(pFile);
}

TEST(SkipSpacesAndTabsTest, NonSpaceNonTabBeforeNewLine)
{
    const char* const kFileName {
        "../input/SkipSpacesAndTabsTest_NonSpaceNonTabBeforeNewLine.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_EQ(skipSpacesAndTabs(pFile), FILE_IO_STATUS_VALUE_FOUND);

    fclose(pFile);
}
