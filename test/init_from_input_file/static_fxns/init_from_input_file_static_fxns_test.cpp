// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_from_input_file.c"
}

#include <gtest/gtest.h>

// TODO: Add tests
TEST(InitNonBoolNonStrTest, MatchingFailure)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    signed char sc;

    // Attempt to populate a signed char (i.e., sc) with a non-numeric
    // character constant (i.e., the value corresponding to the key named
    // "charSuccess") -> cause a matching failure
    EXPECT_FALSE(initNonBoolNonStr(pFile, "charSuccess", "%d", &sc));

    fclose(pFile);
}

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

TEST(InitNonBoolNonStrTest, SignedCharSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    signed char sc;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "scharSuccess", "%d", &sc));
    EXPECT_EQ(sc, -1);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, UnsignedCharSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    unsigned char uc;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "ucharSuccess", "%u", &uc));
    EXPECT_EQ(uc, 1U);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, ShortSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    short s;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "shortSuccess", "%hd", &s));
    EXPECT_EQ(s, -2);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, UnsignedShortSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    unsigned short us;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "ushortSuccess", "%hu", &us));
    EXPECT_EQ(us, 2U);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, IntSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    int i;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "intSuccess", "%d", &i));
    EXPECT_EQ(i, -3);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, UnsignedIntSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    unsigned int ui;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "uintSuccess", "%u", &ui));
    EXPECT_EQ(ui, 3U);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, LongSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    long l;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "longSuccess", "%ld", &l));
    EXPECT_EQ(l, -4L);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, UnsignedLongSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    unsigned long ul;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "ulongSuccess", "%lu", &ul));
    EXPECT_EQ(ul, 4UL);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, FloatSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    float f;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "floatSuccess", "%f", &f));
    EXPECT_EQ(f, 0.12345F);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, DoubleSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    double d;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "doubleSuccess", "%lf", &d));
    EXPECT_EQ(d, 0.123456789);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, LongDoubleSuccess)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    long double ld;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "ldoubleSuccess", "%Lf", &ld));
    EXPECT_EQ(ld, 0.12345678987654321L);

    fclose(pFile);
}
